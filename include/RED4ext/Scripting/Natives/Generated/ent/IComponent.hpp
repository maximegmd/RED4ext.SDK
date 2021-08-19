#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>

namespace RED4ext
{
namespace ent { 
struct IComponent : IScriptable
{
    static constexpr const char* NAME = "entIComponent";
    static constexpr const char* ALIAS = NAME;

    CName name; // 40
    uint8_t unk48[0x60 - 0x48]; // 48
    CRUID id; // 60
    uint8_t unk68[0x8B - 0x68]; // 68
    bool isEnabled; // 8B
    bool isReplicable; // 8C
    uint8_t unk8D[0x90 - 0x8D]; // 8D
};
RED4EXT_ASSERT_SIZE(IComponent, 0x90);
} // namespace ent
} // namespace RED4ext