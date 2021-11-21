#include "Settings.hpp"

std::string CONFIG_FILE = "config.ini";

bool SettingsManager::IsSettingsAvailable() {
    bool IsConfigAvaiable = false;
    std::ifstream ConfigFile;

    ConfigFile.open(CONFIG_FILE);
    if (!ConfigFile.is_open()) {
        IsConfigAvaiable = false;
    }
    else {
        IsConfigAvaiable = true;
    }
    return IsConfigAvaiable;
}

void SettingsManager::GenerateDefaultSettings() {
    mINI::INIFile file(CONFIG_FILE);

    mINI::INIStructure ini;

    ini["MAIN"]["HIDE_CONSOLE"] = "False";

    file.generate(ini, true);
}

void SettingsManager::WriteSetting(const char* Module, const char* Config, std::string NewConfig) {
    mINI::INIFile file(CONFIG_FILE);

    mINI::INIStructure ini;

    file.read(ini);

    ini[Module][Config] = NewConfig;

    file.write(ini, true);
}

std::string SettingsManager::ReadSetting(const char* Module, const char* Config) {
    mINI::INIFile file(CONFIG_FILE);

    mINI::INIStructure ini;

    file.read(ini);

    std::string config;

    config = ini.get(Module).get(Config);

    return config;
}