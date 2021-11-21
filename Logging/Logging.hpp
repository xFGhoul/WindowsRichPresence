#pragma once

#include <iostream>
#include <fstream>

#include "../Include/termcorlor/termcolor.hpp"

class Logging 
{

public:
        void Info(const char* Module, const char* Message);
        void Warning(const char* Module, const char* Message);
        void Debug(const char* Module, const char* Message);
        void Error(const char* Module, const char* Message);
        void WriteToLogFile(const char* LogType, const char* Module, const char* Message);
        void FormulateLogMessage(const char* LogType, const char* Module, const char* Message, const char* Color);
};