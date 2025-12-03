#pragma once
#include <string>

class GameSaver {
public:
    // Przekazujemy przez const reference (&), aby nie kopiować niepotrzebnie pamięci
    void save(const std::string& name, const std::string& cash, const std::string& health, const std::string& level);
};