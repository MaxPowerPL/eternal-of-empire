#include <iostream>
#include <windows.h>
#include <fstream>
#include <filesystem>
#include <string>
#include "../naglowki/GameLoader.h"
#include "../naglowki/Gameplay.h"

using namespace std;

void GameLoader::load() {
    system("cls");

    cout << "Dostępnę zapisy:" << endl;
    cout << "================" << endl << endl;

    string path = "zapisy/";

    // Sprawdź czy folder istnieje, żeby uniknąć crasha
    if (!filesystem::exists(path)) {
        cout << "Brak folderu z zapisami." << endl;
        Sleep(2000);
        return;
    }

    // Wyświetl dostępne zapisy
    bool empty = true;
    for (const auto& entry : filesystem::directory_iterator(path)) {
        if (entry.is_directory()) {
            cout << "- " << entry.path().filename().string() << endl;
            empty = false;
        }
    }

    if (empty) {
        cout << "(Brak zapisów)" << endl;
        Sleep(2000);
        return;
    }

    cout << endl << "=============" << endl;
    cout << "Podaj nazwę zapisu (imię postaci): ";
    string saveName;
    cin >> saveName;

    string filePath = path + saveName + "/character.txt";

    if (filesystem::exists(filePath)) {
        system("cls");

        cout << "Następuje wczytywanie gry..." << endl;
        cout <<  "[             0%             ]";
        Sleep(500);

        system("cls");

        cout <<  "Następuje wczytywanie gry..." << endl;
        cout <<  "[ 🟦         10%             ]";
        Sleep(500);

        system("cls");

        cout <<  "Następuje wczytywanie gry..." << endl;
        cout <<  "[ 🟦🟦       20%             ]";
        Sleep(500);

        system("cls");

        cout <<  "Następuje wczytywanie gry..." << endl;
        cout <<  "[ 🟦🟦🟦     30%             ]";
        Sleep(500);
        
        system("cls");

        cout <<  "Następuje wczytywanie gry..." << endl;
        cout <<  "[ 🟦🟦🟦🟦   40%             ]";
        Sleep(500);
        
        system("cls");

        cout <<  "Następuje wczytywanie gry..." << endl;
        cout <<  "[ 🟦🟦🟦🟦🟦 50%             ]";
        Sleep(500);

        system("cls");

        cout <<  "Następuje wczytywanie gry..." << endl;
        cout <<  "[ 🟦🟦🟦🟦🟦 60% 🟦          ]";
        Sleep(500);

        system("cls");

        cout <<  "Następuje wczytywanie gry..." << endl;
        cout <<  "[ 🟦🟦🟦🟦🟦 70% 🟦🟦        ]";
        Sleep(500);

        system("cls");

        cout <<  "Następuje wczytywanie gry..." << endl;
        cout <<  "[ 🟦🟦🟦🟦🟦 80% 🟦🟦🟦      ]";
        Sleep(500);

        system("cls");

        cout <<  "Następuje wczytywanie gry..." << endl;
        cout <<  "[ 🟦🟦🟦🟦🟦 90% 🟦🟦🟦🟦    ]";
        Sleep(500);

        system("cls");

        cout <<  "Następuje wczytywanie gry..." << endl;
        cout <<  "[ 🟦🟦🟦🟦🟦 100% 🟦🟦🟦🟦🟦 ]";

        // for (int i = 0; i <= 100; i += 10) {
        //     cout << "[ ";
        //     int numFilledBlocks = static_cast<int>(i / 10); // Obliczamy liczbę wypełnionych bloków 🟦
        //     for (int j = 0; j < 10; ++j) {
        //         if (j < numFilledBlocks) {
        //             cout << "🟦";
        //         }
        //         else {
        //             cout << " ";
        //         }
        //     }
        //     cout << " " << setw(3) << right << i << "% ]" << endl; // Ustawiamy wyrównanie do prawej i dodajemy odstęp
        // }

        string name;
        int cash, health, level;

        ifstream file(filePath);
        if (file.is_open()) {
            getline(file, name, ';');
            file >> cash; file.ignore();
            file >> health; file.ignore();
            file >> level; file.ignore();
            file.close();
        }

        string stats = "[💲 " + to_string(cash) + " 💲]   [❤️ " + to_string(health) + "HP ❤️]   [⭐ Poziom: " + to_string(level) + " ⭐]";
  
        cout << endl << "Załadowano zapis gry.";
        Sleep(1000);

        Gameplay game;
        game.start(name, stats);
    }
    else {
        cout << endl << "Brak zapisanej gry." << endl;
        cout << "Wciśnij (Enter), aby kontynuować..." << endl;
        cin.ignore();
        cin.get();
    }
} 