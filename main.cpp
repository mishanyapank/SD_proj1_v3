// Ten kod implementuje interfejs do pracy ze strukturami danych.
#include "Nagłówek.h"

using namespace std;

// Funkcja do czyszczenia ekranu terminala/konsoli.
void wyczysc() {
#ifdef _WIN32
    system("cls");    // Dla Windows.
#else
    system("clear");    // Dla Unix/Linux/MacOS.
#endif
}

int main()
{
    int wybor, opcja;
    char pula;
    // Inicjalizacja struktur danych.
    Tablica tab;
    Lista_wiazana list;
    Lista_tail tail;
    // Inicjalizacja generatora liczb losowych.
    srand(time(NULL));
    cout << "WITAJ! TU PROGRAM BADAJACY ZALEZNOSCI CZASOWE ROZNYCH STRUKTUR DANYCH" << endl;
    cout << "CZY WYGENEROWAC NOWA PULE DANYCH (T/N) (DANE ZOSTANA ZAPISANE I BEDA DOSTEPNE W KAZDEJ ZE STRUKTUR): ";
    cin >> pula;
    if ((pula == 'T') || (pula == 't')) {     // Generowanie danych, jeśli użytkownik wyraził taką chęć
        tab.generowanie_danych();
    }
    wyczysc();
    do {
        cout << "WYBIERZ STRUKTORE" << endl;
        cout << "1. ARRAYLIST" << endl;
        cout << "2. LISTA WIAZANA HEAD" << endl;
        cout << "3. LISTA WIAZANA HEAD I TAIL" << endl;
        cout << "4. ZAKONCZ" << endl;
        cout << "WYBOR: ";
        cin >> opcja;
        wyczysc();
        switch (opcja) {
        case 1:    // Operacje dla tablicy dynamicznej.
            tab.odczyt_danych();    // Odczytuje wcześniej wygenerowane dane.
            do {
                 // Menu wyboru operacji dla tablicy.
                cout << "ARRAYLIST" << endl;
                cout << "WYBIERZ OPERACJE" << endl;
                 // Lista dostępnych operacji.
                cout << "1. DODAWANIE NA POCZATKU TABLICY" << endl;
                cout << "2. USUWANIE NA POCZATKU TABLICY" << endl;
                cout << "3. DODAWANIE NA KONCU TABLICY" << endl;
                cout << "4. USUWANIE NA KONCU TABLICY" << endl;
                cout << "5. DODAWANIE W SRODKU TABLICY" << endl;
                cout << "6. USUWANIE W SRODKU TABLICY" << endl;
                cout << "7. WYSZUKIWANIE ELEMENTU" << endl;
                cout << "8. ZAKONCZ" << endl;
                cout << "WYBOR: ";
                cin >> wybor;
                wyczysc();
                  // Wykonanie wybranej operacji.
                switch (wybor) {
                case 1:
                    tab.dodawanie_poczatek(89);    // Przykładowe dodanie wartości na początku
                    break;
                case 2:
                    tab.usuwanie_poczatek();
                    break;
                case 3:
                    tab.dodawanie_koniec(24);
                    break;
                case 4:
                    tab.usuwanie_koniec(); 
                    break;
                case 5:
                    tab.dodawanie_srodek(); 
                    break;
                case 6:
                    tab.usuwanie_srodek();
                    break;
                case 7:
                    tab.wyszukiwanie(); 
                    break;
                }
                
            } while (wybor != 8);    // Powrót do menu głównego.
            break;
        // Analogicznie dla listy wiązanej i listy z tail.
        case 2:
            list.add();     // Dodaje elementy do listy wiązanej.
            list.reverse();    // Odwraca kolejność elementów w liście.
            do {
                // Menu i operacje dla listy wiązanej.
                cout << "LISTA WIAZANA HEAD" << endl;
                cout << "WYBIERZ OPERACJE" << endl;
                cout << "1. DODAWANIE NA POCZATKU LISTY" << endl;
                cout << "2. USUWANIE NA POCZATKU LISTY" << endl;
                cout << "3. DODAWANIE NA KONCU LISTY" << endl;
                cout << "4. USUWANIE NA KONCU LISTY" << endl;
                cout << "5. DODAWANIE W SRODKU LISTY" << endl;
                cout << "6. USUWANIE W SRODKU LISTY" << endl;
                cout << "7. WYSZUKIWANIE ELEMENTU" << endl;
                cout << "8. ZAKONCZ" << endl;
                cout << "WYBOR: ";
                cin >> wybor;
                wyczysc();
                switch (wybor) {
                case 1:
                    list.dodaj_poczatek(89); break;
                case 2:
                    list.usun_poczatek(); break;
                case 3:
                    list.dodaj_koniec(24); break;
                case 4:
                    list.usun_koniec(); break;
                case 5:
                    list.dodaj_srodek(67); break;
                case 6:
                    list.usun_srodek(); break;
                case 7:
                    list.szukaj(); break;
                }
              
            } while (wybor != 8); break;
        case 3:
            tail.add();    // Dodaje elementy do listy z tail.
            do {
                // Menu i operacje dla listy z tail.
                cout << "LISTA WIAZANA HEAD I TAIL" << endl;
                cout << "WYBIERZ OPERACJE" << endl;
                cout << "1. DODAWANIE NA POCZATKU LISTY" << endl;
                cout << "2. USUWANIE NA POCZATKU LISTY" << endl;
                cout << "3. DODAWANIE NA KONCU LISTY" << endl;
                cout << "4. USUWANIE NA KONCU LISTY" << endl;
                cout << "5. DODAWANIE W SRODKU LISTY" << endl;
                cout << "6. USUWANIE W SRODKU LISTY" << endl;
                cout << "7. WYSZUKIWANIE ELEMENTU" << endl;
                cout << "8. ZAKONCZ" << endl;
                cout << "WYBOR: ";
                cin >> wybor;
                wyczysc();
                switch (wybor) {
                case 1:
                    tail.dodaj_poczatek(89); break;
                case 2:
                    tail.usun_poczatek(); break;
                case 3:
                    tail.dodaj_koniec(24); break;
                case 4:
                    tail.usun_koniec(); break;
                case 5:
                    tail.dodaj_srodek(67); break;
                case 6:
                    tail.usun_srodek(); break;
                case 7:
                    tail.szukaj(); break;
                }
               
            } while (wybor != 8);  break;

        }
    } while (opcja != 4); // Pętla kontynuuje, dopóki użytkownik nie wybierze opcji zakończenia.
    
    
    return 0;
}
