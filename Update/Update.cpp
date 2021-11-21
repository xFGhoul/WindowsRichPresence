#include "Update.hpp"

std::string RELEASES_URL = "https://api.github.com/repos/xFGhoul/WindowsRichPresence/releases/latest";
std::string CURRENT_VERSION = "test";
std::string ZIP_FILE_NAME = "WindowsRichPresence.zip";

bool Update::CheckForUpdates() {
    bool IsNewUpdate = false;
    cpr::Response r = cpr::Get(cpr::Url{RELEASES_URL});
    auto json = nlohmann::json::parse(r.text, nullptr, false);
    std::string name;
    name = json["tag_name"];
    if (name != CURRENT_VERSION) {
        IsNewUpdate = true;
    }
    return IsNewUpdate;
}

void Update::InstallUpdate() {
    auto r = cpr::Get(cpr::Url{RELEASES_URL});
    auto json = nlohmann::json::parse(r.text, nullptr, false);
    std::string browser_download_url;
    browser_download_url = json["assets"][0]["browser_download_url"];
    std::ofstream of(ZIP_FILE_NAME, std::ios::binary);
    cpr::Response download = cpr::Download(of, cpr::Url{browser_download_url});
}
