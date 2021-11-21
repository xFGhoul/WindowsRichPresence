#pragma once

#include <iostream>

#include "../Utilities/ASCII.hpp"
#include "../Utilities/Functions.hpp"

#include "../Include/json/single_include/nlohmann/json.hpp"

#include <cpr/cpr.h>

class Update
{
public:
    bool CheckForUpdates();
    void InstallUpdate();
};

