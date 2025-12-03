#include <iostream>
#include <windows.h>
#include "../naglowki/Dialogue.h"

using namespace std;

void DialogueSystem::startDialogue(const string &name, const string &statistics) {
    system("cls");

    cout << "Napotykasz starą wiedźmę. " << statistics << endl;
    cout << "Wiedźma: \"Witaj, młodzieńcze. Czy potrzebujesz mojej pomocy?\"" << endl << endl;
    cout << "Co chcesz zrobić?" << endl;
    cout << "1. Poproś o wskazówki" << endl;
    cout << "2. Odejdź" << endl;
    cout << "Wybor: ";

    int choice;
    if (!(cin >> choice)) {
        cin.clear(); cin.ignore(1000, '\n');
    }

    switch (choice)
    {
        case 1:
            cout << "Wiedźma: \"Poszukaj ukrytej jaskini na północy. Może tam znajdziesz skarb.\"";
            break;
        case 2:
            cout << "Wiedźma: \"Do zobaczenia, młodzieńcze.\"";
            break;

        default:
            cout << "Wiedźma patrzy na Ciebie dziwnie (Niepoprawny wybór)." << endl;
            break;
    }

    cout << "\n[Naciśnij Enter, aby wrócić]";
    cin.ignore();
    cin.get();
}