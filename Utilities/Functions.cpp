#include "Functions.hpp"

bool Function::CheckDirectoryExists(std::string DirectoryPath) {
    struct stat buffer;
    return (stat(DirectoryPath.c_str(), &buffer) == 0);
}

bool Function::CheckFileExists(std::string FileName) {
    bool DoesFileExist = false;
    std::ifstream File;

    File.open(FileName);
    if (!File.is_open()) {
        DoesFileExist = false;
    }
    else {
        DoesFileExist = true;
    }
    return DoesFileExist;
}

void Function::Setup() {
    // Create Config Folders, Create Logging, Folders, etc
}