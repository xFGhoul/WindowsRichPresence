#include "Logging.hpp"


std::string LOG_FILE = "WindowsRichPresence.log";

const std::string GetCurrentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}


void Logging::WriteToLogFile(const char* LogType, const char* Module, const char* Message) {
        std::ofstream logFile;
        logFile.open(LOG_FILE, std::ios_base::app | std::ios_base::out);
        logFile << GetCurrentDateTime() << LogType << '[' << Module << ']' << " " << Message << std::endl;
        logFile.close();
}

void Logging::FormulateLogMessage(const char* LogType, const char* Module, const char* Message, const char* Color) {
    if (Color == "blue") {
        std::cout << termcolor::blue << GetCurrentDateTime() << " INFO " << '[' << Module << ']' << " " << Message << termcolor::reset << std::endl;
    }
    else if (Color == "red") {
        std::cout << termcolor::red << GetCurrentDateTime() << " INFO " << '[' << Module << ']' << " " << Message << termcolor::reset << std::endl;
    }
    else if (Color == "green") {
        std::cout << termcolor::green << GetCurrentDateTime() << " INFO " << '[' << Module << ']' << " " << Message << termcolor::reset << std::endl;
    }
    else if (Color == "yellow") {
        std::cout << termcolor::yellow << GetCurrentDateTime() << " INFO " << '[' << Module << ']' << " " << Message << termcolor::reset << std::endl;
    }
}



void Logging::Info(const char* Module, const char* Message) {
    Logging::FormulateLogMessage("INFO", Module, Message, "blue");
    Logging::WriteToLogFile("INFO", Module, Message);
}

void Logging::Error(const char* Module, const char* Message) {
    Logging::FormulateLogMessage("ERROR", Module, Message, "red");
    Logging::WriteToLogFile("INFO", Module, Message);
}

void Logging::Warning(const char* Module, const char* Message) {
    Logging::FormulateLogMessage("WARNING", Module, Message, "green");
    Logging::WriteToLogFile("WARNING", Module, Message);
}

void Logging::Debug(const char* Module, const char* Message) {
    Logging::FormulateLogMessage("DEBUG", Module, Message, "yellow");
    Logging::WriteToLogFile("DEBUG", Module, Message);
}