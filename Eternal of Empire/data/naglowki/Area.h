#pragma once
#include <string>

class Area {
private:
    std::string name;
    std::string statistics;

public:
    void loadArea(const std::string& name, const std::string& statistics);
};