#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/Event.hpp>

namespace RED4ext
{
namespace game::ui { 
struct EnableStickerEditorEvent : red::Event
{
    static constexpr const char* NAME = "gameuiEnableStickerEditorEvent";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk40[0x48 - 0x40]; // 40
};
RED4EXT_ASSERT_SIZE(EnableStickerEditorEvent, 0x48);
} // namespace game::ui
} // namespace RED4ext