#include <iostream>
#include <windows.h> // Sleep, system
#include <fstream>
#include <filesystem>
#include <string>

// Nowe nagłówki
#include "../naglowki/Menu.h"
#include "../naglowki/Gameplay.h"
#include "../naglowki/GameLoader.h"
#include "../naglowki/GameSaver.h"

using namespace std;

// Funkcja pomocnicza (może zostać tutaj jako lokalna)
void animateText(const string& text, int delay) {
    for (char c : text) {
        cout << c << flush;
        Sleep(delay);
    }
}

void Menu::show() {
    // Konfiguracja konsoli
    system("chcp 65001 > nul");
    system("title RPG - Eternal of Empire");

    string name;
    int choice;
    // Wartości domyślne dla nowej gry
    int cash = 100, health = 100, level = 1;
    string statistics; // Będzie zbudowane po wczytaniu/utworzeniu

    while (true) {
        system("cls");

        cout << "╔═════════════════════════╗" << endl;
        cout << "║    Witaj w grze RPG!    ║" << endl;
        cout << "║═════════════════════════║" << endl;
        cout << "║ 1. Rozpocznij nową grę  ║" << endl;
        cout << "║ 2. Wczytaj grę          ║" << endl;
        cout << "║ 3. Zapisz grę           ║" << endl;
        cout << "║ 4. Wyjdź z gry          ║" << endl;
        cout << "╚═════════════════════════╝" << endl;
        cout << "Wybierz opcję: ";

        if (!(cin >> choice)) { // Zabezpieczenie przed wpisaniem liter
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                system("cls");
                cout << "Podaj imię postaci: ";
                cin >> name;

                string folderPath = "zapisy/" + name;

                if (!filesystem::exists(folderPath)) {
                    // Logika tworzenia nowej gry
                    cout << "Statystyki początkowe:\nZłoto: " << cash << "\nZdrowie: " << health << "\nPoziom: " << level << endl;

                    // BEZPIECZNE TWORZENIE KATALOGÓW (fix z poprzedniej rozmowy)
                    filesystem::create_directories(folderPath);

                    ofstream newCharacter(folderPath + "/character.txt");
                    newCharacter << name << ";" << endl << cash << ";" << endl << health << ";" << endl << level << ";";
                    newCharacter.close();

                    Sleep(1000);
                    cout << "Rozpoczęto nową grę." << endl;
                    Sleep(2000);
                    system("cls");

                    string story =  "║  Właśnie obudziłeś się w tajemniczym lesie, otoczony gęstym mchem i szumem drzew.   ║\n"
                                    "║  Twoje oczy powoli przystosowują się do półmroku, ale głowa jest pusta, pozbawiona  ║\n"
                                    "║  wspomnień.                                                                         ║\n"
                                    "║                                                                                     ║\n"
                                    "║  Nie pamiętasz, jak tu trafiłeś ani skąd pochodzisz. Twoje imię powoli wyłania się  ║\n"
                                    "║  z mgły zapomnienia - jesteś ";
                    string remainingStory = "                                                    ║\n"
                                            "║                                                                                     ║\n"
                                            "║  W oddali słychać szmer nocnych istot, a cienie drzew wydają się przybierać         ║\n"
                                            "║  niepokojące kształty wraz z nadchodzącym zmierzchem. Wiesz, że musisz działać      ║\n"
                                            "║  szybko.                                                                            ║\n"
                                            "║                                                                                     ║\n"
                                            "║  Zdając sobie sprawę, że nie masz przy sobie niczego, co mogłoby pomóc w            ║\n"
                                            "║  przetrwaniu, zaczynasz przeszukiwać okolicę w poszukiwaniu jakiegokolwiek          ║\n"
                                            "║  schronienia.                                                                       ║\n"
                                            "║                                                                                     ║\n"
                                            "║  Nagle, z dala od miejsca, gdzie się obudziłeś, dostrzegasz słaby blask wśród       ║\n"
                                            "║  drzew. Może to oznaka ludzkiej obecności, może też być pułapką.                    ║\n"
                                            "║                                                                                     ║\n"
                                            "║  Jednak w obliczu zbliżającej się nocy, nie masz wyboru - musisz podjąć ryzyko.     ║\n"
                                            "║  Kierujesz się ku światłu, trzymając się cicho i czujnie obserwując otoczenie.      ║\n"
                                            "║                                                                                     ║\n"
                                            "║  Im bliżej, tym bardziej widoczny staje się obraz - mały, zaniedbany domek,         ║\n"
                                            "║  pokryty porośniętym mchem na dachu. Wkroczasz do środka, szukając schronienia      ║\n"
                                            "║  przed nadchodzącą ciemnością.                                                      ║\n"
                                            "║                                                                                     ║\n"
                                            "║  Czy to miejsce będzie twoim bezpiecznym azylem, czy może tylko początkiem          ║\n"
                                            "║  większej tajemnicy, która otacza twoją osobę? Tylko czas pokaże, co kryje się za   ║\n"
                                            "║  zasłoną zapomnienia, która otacza twoje życie.                                     ║\n";

                    cout << "╔═════════════════════════════════════════════════════════════════════════════════════╗" << endl;
                    cout << "║                                                                                     ║" << endl;
                    animateText(story, 50);
                    animateText(name, 75);
                    animateText(remainingStory, 50);
                    cout << "║                                                                                     ║" << endl;
                    cout << "║                                                                                     ║" << endl;
                    cout << "║                                                                                     ║" << endl;
                    cout << "║                                                                                     ║" << endl;
                    cout << "╚═════════════════════════════════════════════════════════════════════════════════════╝" << endl;
                    Sleep(1000);
                    cout << "Aby przejść dalej naciśnij (Enter)";
                    cin.ignore();
                    cin.get();

                    // Budowanie stringa statystyk
                    statistics = "[💲 " + to_string(cash) + " 💲]   [❤️ " + to_string(health) + "HP ❤️]   [⭐ Poziom: " + to_string(level) + " ⭐]";

                    Gameplay game;
                    game.start(name, statistics);
                }
                else {
                    cout << "Niestety taka nazwa już istnieje. Podaj inną nazwę." << endl << endl;
                    cout << "Aby przejść dalej naciśnij (Enter)";
                    cin.ignore();
                    cin.get();
                }
                break;
            }
            case 2: {
                // Wczytywanie gry
                GameLoader loadGame;
                loadGame.load();
                break;
            }
            case 3: {
                // Zapisywanie gry
                GameSaver saveGame;
                saveGame.save(name, to_string(cash), to_string(health), to_string(level));
                break;
            }
            case 4: {
                // Opcja wyjścia z gry (zamknięcie programu)
                cout << endl << "╔═════════════════════════════════╗" << endl;
                cout << "║ Dziękujemy za grę! Do widzenia! ║" << endl;
                cout << "╚═════════════════════════════════╝" << endl;
                Sleep(2000);
                return;
                break;
            }
            
            default: {
                cout << "Niepoprawny wybór. Wybierz opcję od 1 do 4." << endl;
                cout << "Wciśnij (Enter)";
                cin.ignore();
                cin.get();         
                break;
            }
        }   
    }
}