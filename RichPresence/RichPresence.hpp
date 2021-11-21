#pragma once

#include "../Include/discord-rpc/discord_rpc.h"

class WindowsDiscordRichPresence
{
public:
        void Init();
        void Update(const char* state, const char* details, int64_t startTimestamp, const char* largeImageKey, const char* largeImageText);
        void Shutdown();
};