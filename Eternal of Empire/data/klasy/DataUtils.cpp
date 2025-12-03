#include <iostream>
#include <fstream>
#include <sstream>
#include "../naglowki/DataUtils.h"

using namespace std;

void DataUtils::updateAttribute(const string &filePath, const string &attribute, int change) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Nie można otworzyć pliku do odczytu: " << filePath << endl;
        return;
    }

    string name;
    int cash, health, level;

    getline(file, name, ';');
    file >> cash; file.ignore();
    file >> health; file.ignore();
    file >> level; file.ignore();
    file.close();

    if (attribute == "cash") cash += change;
    else if (attribute == "health") health += change;
    else if (attribute == "level") level += change;
    else {
        cerr << "Nieznany atrybut: " << attribute << endl;
        return;
    }

    ofstream outFile(filePath);
    if (outFile.is_open()) {
        outFile << name << ";\n" << cash << ";\n" << health << ";\n" << level << ";";
        outFile.close();
    }
    else {
        cerr << "Bład: Nie można otworzyć pliku do zapisu." << endl;
    }
}

string DataUtils::getUpdatedStatistics(const string &filePath) {
    ifstream file(filePath);
    if (!file.is_open()) return "[Błąd odczytu danych]";

    string name;
    int cash, health, level;

    getline(file, name, ';');
    file >> cash; file.ignore();
    file >> health; file.ignore();
    file >> level; file.ignore();
    file.close();

    return "[💲 " + to_string(cash) + " 💲]   [❤️ " + to_string(health) + "HP ❤️]   [⭐ Poziom: " + to_string(level) + " ⭐]";
}