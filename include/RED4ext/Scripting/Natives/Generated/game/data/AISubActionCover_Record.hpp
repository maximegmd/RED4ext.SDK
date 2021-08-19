#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/AISubAction_Record.hpp>

namespace RED4ext
{
namespace game::data { 
struct AISubActionCover_Record : game::data::AISubAction_Record
{
    static constexpr const char* NAME = "gamedataAISubActionCover_Record";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk48[0x78 - 0x48]; // 48
};
RED4EXT_ASSERT_SIZE(AISubActionCover_Record, 0x78);
} // namespace game::data
} // namespace RED4ext