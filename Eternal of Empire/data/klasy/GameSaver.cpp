#include <iostream>
#include <windows.h>
#include <fstream>
#include <filesystem>
#include <string>
#include "../naglowki/GameSaver.h"
#include "../naglowki/GameLoader.h"
#include "../naglowki/Gameplay.h"
#include "../naglowki/Menu.h"

using namespace std;

void GameSaver::save(const string &name, const string &cash, const string &health, const string &level) {
    system("cls");
    string folderPath = "zapisy/" + name;

    filesystem::create_directories(folderPath);

    system("cls");

    cout << "Następuje zapisywanie gry..." << endl;
    cout <<  "[             0%             ]";
    Sleep(500);

    system("cls");

    cout <<  "Następuje zapisywanie gry..." << endl;
    cout <<  "[ 🟩         10%             ]";
    Sleep(500);

    system("cls");

    cout <<  "Następuje zapisywanie gry..." << endl;
    cout <<  "[ 🟩🟩       20%             ]";
    Sleep(500);

    system("cls");

    cout <<  "Następuje zapisywanie gry..." << endl;
    cout <<  "[ 🟩🟩🟩     30%             ]";
    Sleep(500);
        
    system("cls");

    cout <<  "Następuje zapisywanie gry..." << endl;
    cout <<  "[ 🟩🟩🟩🟩   40%             ]";
    Sleep(500);
        
    system("cls");

    cout <<  "Następuje zapisywanie gry..." << endl;
    cout <<  "[ 🟩🟩🟩🟩🟩 50%             ]";
    Sleep(500);

    system("cls");

    cout <<  "Następuje zapisywanie gry..." << endl;
    cout <<  "[ 🟩🟩🟩🟩🟩 60% 🟩          ]";
    Sleep(500);

    system("cls");

    cout <<  "Następuje zapisywanie gry..." << endl;
    cout <<  "[ 🟩🟩🟩🟩🟩 70% 🟩🟩        ]";
    Sleep(500);

    system("cls");

    cout <<  "Następuje zapisywanie gry..." << endl;
    cout <<  "[ 🟩🟩🟩🟩🟩 80% 🟩🟩🟩      ]";
    Sleep(500);

    system("cls");

    cout <<  "Następuje zapisywanie gry..." << endl;
    cout <<  "[ 🟩🟩🟩🟩🟩 90% 🟩🟩🟩🟩    ]";
    Sleep(500);

    system("cls");

    cout <<  "Następuje zapisywanie gry..." << endl;
    cout <<  "[ 🟩🟩🟩🟩🟩 100% 🟩🟩🟩🟩🟩 ]";

    // for (int i = 0; i <= 100; i += 10) {
    //     cout << "[ ";
    //     int numFilledBlocks = static_cast<int>(i / 10); // Obliczamy liczbę wypełnionych bloków 🟩
    //     for (int j = 0; j < 10; ++j) {
    //         if (j < numFilledBlocks) {
    //             cout << "🟩";
    //         }
    //         else {
    //             cout << " ";
    //         }
    //     }
    //     cout << " " << setw(3) << right << i << "% ]" << endl; // Ustawiamy wyrównanie do prawej i dodajemy odstęp
    // }

    ofstream file(folderPath + "/character.txt", ios::trunc);

    if (file.is_open()) {
        // Zapisanie danych do pliku
        file << name << ";\n" << cash << ";\n" << health << ";\n" << level << ";";
        // Zamknięcie pliku
        file.close();
        cout << "Twój zapis gry został pomyślnie nadpisany." << endl;
        Sleep(1000);
    }
    else {
        cerr << "\nBłąd: Nie udało się zapisać pliku!" << endl;
        Sleep(1000);
    }
}