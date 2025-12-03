#pragma once
#include <string>

class Gameplay {
private:
    std::string playerName;
    std::string playerStats;

public:
    void start(const std::string& name, const std::string& statistics);
};