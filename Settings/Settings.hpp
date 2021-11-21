#pragma once

#define MINI_CASE_SENSITIVE

#include <iostream>
#include <fstream>

#include "../Include/ini/ini.h"

class SettingsManager 
{
public:
	bool IsSettingsAvailable();

	void GenerateDefaultSettings();

	void WriteSetting(const char* Module, const char* Setting, std::string NewSetting);

	std::string ReadSetting(const char* Module, const char* Setting);
};

