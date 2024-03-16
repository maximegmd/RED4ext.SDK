#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/Relocation.hpp>
#endif

#include <mutex>
#include <sstream>
#include <filesystem>

#include <Windows.h>

#include <RED4ext/Common.hpp>

RED4EXT_INLINE uintptr_t RED4ext::RelocBase::GetImageBase()
{
    static const auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr));
    return base;
}

RED4EXT_INLINE
uintptr_t RED4ext::UniversalRelocBase::Resolve(uint32_t aHash)
{
    using functionType = void* (*)(uint32_t);
    static functionType resolveFunc = nullptr;

    static std::once_flag flag;
    std::call_once(flag,
       []()
       {
           char exePath[4096];
           GetModuleFileNameA(GetModuleHandle(nullptr), exePath, 4096);

           std::filesystem::path exe = exePath;

           auto dllName = exe.parent_path() / "version.dll";
           constexpr auto functionName = "ResolveAddress";

           auto handle = LoadLibraryA(dllName.string().c_str());
           if (!handle)
           {
               std::stringstream stream;
               stream << "Failed to get '" << dllName
                      << "' handle.\nProcess will now close.\n\nLast error: " << GetLastError();

               MessageBoxA(nullptr, stream.str().c_str(), "Cyber Engine Tweaks", MB_ICONERROR | MB_OK);
               TerminateProcess(GetCurrentProcess(), 1);
               return; // Disable stupid warning
           }

           resolveFunc = reinterpret_cast<functionType>(GetProcAddress(handle, functionName));
           if (resolveFunc == nullptr)
           {
               std::stringstream stream;
               stream << "Failed to get '" << functionName
                      << "' address.\nProcess will now close.\n\nLast error: " << GetLastError();

               MessageBoxA(nullptr, stream.str().c_str(), "Cyber Engine Tweaks", MB_ICONERROR | MB_OK);
               TerminateProcess(GetCurrentProcess(), 1);
           }
       });

    auto address = resolveFunc(aHash);
    if (address == 0)
    {
        std::stringstream stream;
        stream << "Failed to resolve address for hash " << std::hex << std::showbase << aHash << ".\nProcess will now close.";

        MessageBoxA(nullptr, stream.str().c_str(), "Cyber Engine Tweaks", MB_ICONERROR | MB_OK);
        TerminateProcess(GetCurrentProcess(), 1);
    }

    return reinterpret_cast<uintptr_t>(address);
}
