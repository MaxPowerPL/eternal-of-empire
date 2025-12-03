#include <iostream>
#include <windows.h>
#include "../naglowki/Gameplay.h"
#include "../naglowki/DataUtils.h"
#include "../naglowki/Menu.h"
#include "../naglowki/Area.h"
#include "../naglowki/Dialogue.h"

using namespace std;

// Implementacja metody start()
void Gameplay::start(const string &name, const string &statistics) {
    string currentStats = statistics;
    string filePath = "zapisy/" + name + "/character.txt";

    DataUtils dataUtils;
    Area areaInForest;
    Menu gameMenu;
    DialogueSystem talkWith;

    while(true) {
        system("cls");

        cout << "Witaj, " << name << ". Co chcesz teraz zrobić? " << statistics << endl;
        cout << "------------------------------------------------" << endl;
        cout << "1. Zbadać okolicę" << endl;
        cout << "2. Porozmawiać z postacią" << endl;
        cout << "3. Idź do miasta (W budowie)" << endl;
        cout << "4. Ekwipunek (W budowie)" << endl;
        cout << "5. Wyjdź do menu głównego" << endl;
        cout << "Wybierz opcję: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                areaInForest.loadArea(name, currentStats);
                currentStats = dataUtils.getUpdatedStatistics(filePath);
                break;
            case 2:
                talkWith.startDialogue(name, currentStats);
                currentStats = dataUtils.getUpdatedStatistics(filePath);
                break;
            case 3:
            case 4:
                cout << "Ta funkcja nie jest jeszcze dostępna." << endl;
                Sleep(1000);
                break;
            case 5:
                gameMenu.show();
                return;

            default:
                cout << "Niepoprawny wybór. Wybierz opcję od 1 do 5.";
                cout << "Wciśnij (Enter)";
                cin.ignore();
                cin.get();
                break;
        }
    }
};