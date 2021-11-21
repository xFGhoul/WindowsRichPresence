#pragma once

#include <fstream>
#include <sys/stat.h>
#include <windows.h>
#include <tlhelp32.h>

class Function
{
public:
        bool CheckFileExists(std::string FileName);
        bool CheckDirectoryExists(std::string DirectoryPath);
        void Setup();
};