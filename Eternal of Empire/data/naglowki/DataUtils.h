#pragma once
#include <string>

class DataUtils {
private:
    std::string filePath;
    int cash;

public:
    void updateAttribute(const std::string& filePath, const std::string& attribute, int change);
    std::string getUpdatedStatistics(const std::string& filePath);
};