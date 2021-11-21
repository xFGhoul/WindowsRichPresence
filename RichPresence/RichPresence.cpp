#include "RichPresence.hpp"

void WindowsDiscordRichPresence::Init() {
    DiscordEventHandlers discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    Discord_Initialize("911026851156209675", &discordPresence, 1, NULL);
}

void WindowsDiscordRichPresence::Update(const char* state, const char* details, int64_t startTimestamp, const char* largeImageKey, const char* largeImageText) {
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));

    discordPresence.state = state;
    discordPresence.details = details;
    discordPresence.startTimestamp = startTimestamp;
    discordPresence.largeImageKey = largeImageKey;
    discordPresence.largeImageText = largeImageText;

    Discord_UpdatePresence(&discordPresence);
}

void WindowsDiscordRichPresence::Shutdown() {
    Discord_Shutdown();
}