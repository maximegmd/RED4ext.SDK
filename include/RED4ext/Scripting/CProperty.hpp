#pragma once

#include <Windows.h>
#include <cstdint>
#include <RED4ext/CName.hpp>

namespace RED4ext
{
struct IRTTIType;
struct CClass;

struct CProperty
{
    IRTTIType* type;
    CName name;
    CName unk10;
    CClass* parent;
    uint32_t flags;
    int64_t unk28;
};

RED4EXT_ASSERT_SIZE(CProperty, 0x30);
RED4EXT_ASSERT_OFFSET(CProperty, type, 0x0);
RED4EXT_ASSERT_OFFSET(CProperty, name, 0x8);
RED4EXT_ASSERT_OFFSET(CProperty, parent, 0x18);
RED4EXT_ASSERT_OFFSET(CProperty, flags, 0x20);
} // namespace RED4ext


namespace RED4ext
{
template<typename T>
class REDprop
{
public:
    REDprop(uintptr_t aAddress)
        : m_address(reinterpret_cast<T>(aAddress + reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr))))
    {
    }

    operator T() const
    {
        return m_address;
    }

private:
    T m_address;
};
} // namespace RED4ext
