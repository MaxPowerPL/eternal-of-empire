#include <iostream>
#include <windows.h>
#include "../naglowki/Area.h"
#include "../naglowki/DataUtils.h"

using namespace std;

namespace {
    void investigateHut(const string& name) {
        system("cls");
        string filePath = "zapisy/" + name + "/character.txt";
        DataUtils dataUtils;

        cout << "Badając chatkę, znajdujesz ukryty skarb!" << endl;
        Sleep(1000);
        cout << "Zdobyłeś 50 złotych monet." << endl;

        dataUtils.updateAttribute(filePath, "cash", 50);

        Sleep(2000);
        cout << "Aby przejść dalej naciśnij (Enter)" << endl;
        cin.ignore();
        cin.get();
    };

    void followStream() {
        system("cls");

        string choice;

        cout << "Podążając strumykiem, trafiasz na ukryty ołtarz." << endl;
        Sleep(750);
        cout << "Czy chcesz się zatrzymać i zbadać?" << endl;
        cout << "Tak/Nie: ";
        cin >> choice;

        if (choice == "Tak" || choice == "tak") {
            cout << "Zbadałeś ołtarz, lecz niczego nie znalazłeś." << endl;
            Sleep(750);
        }
        else if (choice == "Nie" || choice == "nie") {
            cout << "Kontynuujesz swoją podróż." << endl;
            Sleep(750);
        }
        else {
            cout << "Niepoprawny wybór. Wybierz opcję Tak lub Nie";
            Sleep(750);
        }

        cout << "Wciśnij (Enter)";
        cin.ignore();
        cin.get();
    };

    void walkPath() {
        system("cls");

        string choice;

        cout << "Idąc ścieżką, natrafiasz na grupę podróżnych." << endl;
        Sleep(1000);
        cout << "Czy chcesz się z nimi zatrzymać i porozmawiać?" << endl;
        cout << "Tak/Nie: ";
        cin >> choice;

        if (choice == "Tak" || choice == "tak") {
            cout << "Spędziłeś trochę czasu rozmawiając z podróżnymi." << endl;
            Sleep(750);
            cout << "Otrzymujesz cenny przepis na lekarstwo." << endl;
            Sleep(750);
        }
        else if (choice == "Nie" || choice == "nie") {
            cout << "Kontynuujesz swoją podróż." << endl;
            Sleep(750);
        }
        else {
            cout << "Niepoprawny wybór. Wybierz opcję Tak lub Nie";
            Sleep(750);
        }

        cout << "Wciśnij (Enter)";
        cin.ignore();
        cin.get();
    };

    void openChest(const string& name) {
        system("cls");
        string filePath = "zapisy/" + name + "/postac.txt";
        DataUtils dataUtils;

        cout << "Otwierając skrzynię, znajdujesz starożytną mapę." << endl;
        Sleep(750);
        cout << "Mapa wskazuje na ukryty grobowiec." << endl;
        Sleep(750);
        cout << "Czy chcesz się tam udać?" << endl;
        cout << "Tak/Nie: ";

        string choice;
        cin >> choice;

        if (choice == "Tak" || choice == "tak") {
            system("cls");

            cout << "Udałeś się do grobowca." << endl;
            Sleep(750);
            cout << "Wewnątrz znajdujesz skarb, lecz także starożytną pułapkę!" << endl;
            Sleep(750);
            cout << "Czy chcesz spróbować zdobyć skarb i ryzykować życie?" << endl;
            cout << "Tak/Nie: ";

            string choiceTomb;
            cin >> choiceTomb;

            if (choiceTomb == "Tak" || choiceTomb == "tak") {
                cout << "Ryzykujesz życie, lecz udaje Ci się zdobyć skarb." << endl;
                Sleep(750);
                cout << "Zdobywasz 100 złotych monet." << endl;
                dataUtils.updateAttribute(filePath, "cash", 100);
                Sleep(750);
                cout << "Oraz jesteś lekko ranny."  << endl;
                dataUtils.updateAttribute(filePath, "health", -15);
                Sleep(750);
            }
            else if (choiceTomb == "Nie" || choiceTomb == "nie") {
                cout << "Postanawiasz opuścić grobowiec, unikając pułapki." << endl;
                Sleep(750);
            }
            else {
                cout << "Niepoprawny wybór. Wybierz opcję Tak lub Nie";
                Sleep(750);
            }

            cout << "Aby przejść dalej naciśnij (Enter)";
            cin.ignore();
            cin.get();
        }
        else if (choice == "Nie" || choice == "nie") {
            cout << "Decydujesz się nie udawać do grobowca." << endl;
            Sleep(750);
        }
        else {
            cout << "Niepoprawny wybór. Wybierz opcję Tak lub Nie";
            Sleep(750);
        }

        cout << "Aby przejść dalej naciśnij (Enter)";
        cin.ignore();
        cin.get();
    };

    void encounterStranger(const string& name) {
        system("cls");

        string filePath = "zapisy/" + name + "/postac.txt";
        DataUtils dataUtils;

        cout << "Spotykasz nieznajomego, który prosi o drogę do pobliskiej wioski." << endl;
        Sleep(1000);
        cout << "Czy chcesz mu pomóc?" << endl;
        cout << "Tak/Nie: ";

        string choice;
        cin >> choice;

        if (choice == "Tak" || choice == "tak") {
            cout << "Pomagając nieznajomemu, otrzymujesz nagrodę." << endl;
            Sleep(750);
            cout << "Otrzymujesz 20 złotych monet." << endl;
            dataUtils.updateAttribute(filePath, "cash", 20);
            Sleep(750);
            cout << "Oraz 1 poziom reptuacji." << endl;
            dataUtils.updateAttribute(filePath, "level", 1);
            Sleep(750);
        }
        else if (choice == "Nie" || choice == "nie") {
            cout << "Odmawiasz pomocy nieznajomemu." << endl;
            Sleep(750);
        }
        else {
            cout << "Niepoprawny wybór. Wybierz opcję Tak lub Nie";
            Sleep(750);
        }

        cout << "Wciśnij (Enter)";
        cin.ignore();
        cin.get();
    };
}

void Area::loadArea(const string &name, const string &statistics) {
    while (true) {
        system("cls");

        cout << "================================================= " << statistics << endl;
        cout << "Zbadałeś okolicę. Znajdujesz:" << endl;
        Sleep(1000);
        cout << "- Małą chatkę, która wygląda na opuszczoną." << endl;
        Sleep(1000);
        cout << "- Strumyk, który biegnie na wschód." << endl;
        Sleep(1000);
        cout << "- Ścieżkę prowadzącą na północ." << endl;
        Sleep(1000);
        cout << "- Drewnianą skrzynię leżącą pod drzewem na zachód." << endl;
        Sleep(1000);
        cout << "- Nieznajomy ukryty w krzakach na południe." << endl;
        cout << "=================================================" << endl;
        cout << "Wróc do lasu (Q)" << endl << endl;
        cout << "Co chcesz zrobić? (wpisz numer / Q): ";

        char choice;
        cin >> choice;

        if (choice == 'q' || choice == 'Q') {
            return;
        }

        switch (choice)
        {
            case '1':
                investigateHut(name);
                break;
            case '2':
                followStream();
                break;
            case '3':
                walkPath();
                break;
            case '4':
                openChest(name);
                break;
            case '5':
                encounterStranger(name);
                break;
    
            default:
                cout << "Niepoprawny wybór. Spróbuj ponownie." << endl;
                cout << "Wciśnij (Enter)";
                cin.ignore();
                cin.get();
                return;
        }
    }
}