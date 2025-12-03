# ⚔️ Eternal of Empire

Konsolowa gra RPG stworzona w języku C++ przy użyciu Visual Studio. Projekt skupia się na zasadach programowania obiektowego, zarządzaniu plikami oraz interaktywnej narracji.

## 📖 O Projekcie

**Eternal of Empire** to tekstowa gra fabularna (RPG), w której gracz eksploruje tajemniczy las, wchodzi w interakcje z postaciami niezależnymi (NPC) i zarządza zasobami. Projekt powstał w celu przećwiczenia:
* **Standardów C++17** (w tym biblioteki `<filesystem>`).
* **Programowania Obiektowego** (Separacja klas, Enkapsulacja).
* **Zasad Czystego Kodu** (Angielskie konwencje nazewnicze, zasady SOLID).
* **Operacji na plikach** (Własny system zapisu i odczytu).

## 🚀 Funkcjonalności

* **System Statystyk:** Zarządzanie Zdrowiem (Health), Złotem (Cash) i Poziomem (Level).
* **System Zapisu i Wczytywania:**
    * Dynamiczne tworzenie folderów zapisu przy użyciu `std::filesystem`.
    * Własna serializacja danych postaci do plików `.txt`.
    * Wizualne paski ładowania zaimplementowane w konsoli.
* **Interaktywne Menu:** Nawigacja pomiędzy różnymi stanami gry (Nowa Gra, Wczytaj, Zapisz, Wyjdź).
* **Narracja:** Wciągająca opowieść tekstowa z efektem animowanego wyświetlania tekstu.
* **Czysta Architektura:** Logika rozdzielona na pliki nagłówkowe (`.h`) i źródłowe (`.cpp`) w uporządkowanej strukturze katalogów.

## 🛠️ Technologie (Tech Stack)

* **Język:** C++ (Standard ISO C++17)
* **IDE:** Visual Studio 2022
* **Platforma:** Windows (Wykorzystuje `<windows.h>` do manipulacji konsolą)

## 📂 Struktura Projektu

Projekt podąża za modułową strukturą, aby utrzymać kod w czystości i łatwości w utrzymaniu:

```text
Eternal of Empire/
├── data/
│   ├── naglowki/       # Pliki nagłówkowe (.h) definiujące interfejsy klas
│   │   ├── Area.h
│   │   ├── Gameplay.h
│   │   ├── Menu.h
│   │   └── ...
│   └── klasy/          # Pliki źródłowe (.cpp) implementujące logikę
│       ├── Area.cpp
│       ├── Gameplay.cpp
│       ├── Menu.cpp
│       └── ...
├── main.cpp            # Punkt wejścia (Entry point)
└── README.md
