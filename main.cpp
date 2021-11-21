#include "Includes.h"

// Initializing Classes

WindowsDiscordRichPresence* RPC;
SettingsManager* Settings;
Function* Functions;
Logging* Log;
Update* Updater;

// Main Program

// TODO: Try Fixing FTXUI(https://github.com/ArthurSonzogni/FTXUI/issues/263)
// TODO: Build A Menu(For Settings And Handling RPC) Using FTXUI or Tabulate
// TODO: System Tray
// TODO: App Icon
// TODO: Improve Printing(Pretty Shitty)
// TODO: Set Up Window Title Fetching(Core Logic)
// TODO: Fix "Elapsed 0:00", Don't Know If This Is A Code Issue Or Discord Issue.

int main() {
    system("cls");
    SetConsoleTitleA("WindowsRichPresence - Initializion");
    SetConsoleOutputCP(CP_UTF8);
    ASCII::PrintInitalizing();
    if (!Settings->IsSettingsAvailable()) {
        Settings->GenerateDefaultSettings();
    }
    if (!Functions->CheckFileExists("WindowsRichPresence.log")) {
        std::ofstream logFile("WindowsRichPresence.log");
        logFile.open("WindowsRichPresence.log", std::ofstream::out | std::ofstream::trunc);
        logFile.close();
        Settings->GenerateDefaultSettings();
    }
    if (Updater->CheckForUpdates()) {
        Updater->InstallUpdate();
    }
    system("cls");
    SetConsoleTitleA("WindowsRichPresence - Main");
    ASCII::MainLogo();
    Log->Info("RPC", "Initializing RPC");
    RPC->Init();
    Log->Info("RPC", "RPC Initialized");
    RPC->Update("state", "details", std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count(), "default", "default");
    Log->Info("RPC", "Updated RPC.");
    Sleep(-1);
}
