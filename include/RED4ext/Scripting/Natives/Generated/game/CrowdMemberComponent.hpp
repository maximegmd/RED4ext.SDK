#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace game { 
struct CrowdMemberComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameCrowdMemberComponent";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk90[0x1E0 - 0x90]; // 90
};
RED4EXT_ASSERT_SIZE(CrowdMemberComponent, 0x1E0);
} // namespace game
} // namespace RED4ext