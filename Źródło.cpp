// Ten kod zawiera implementacje funkcji dla tablicy dynamicznej

#include "Nagłówek.h"

// Metoda podwajająca pojemność tablicy dynamicznej
void Tablica::podwojenie() {
    capacity = 2 * size;    // Podwaja aktualną pojemność tablicy.
    int* nowy = new int[capacity];    // Tworzy nową, większą (o dwa razy) tablicę.
    int i = 0;
    // Kopiuje istniejące elementy do nowej tablicy.
    while (i < size) {
        nowy[i] = array[i];
        i++;
    }
    delete[] array;    // Zwalnia pamięć starej tablicy.
    array = nowy;      // Ustawia wskaźnik na nową tablicę.
}

// Konstruktor klasy Tablica, inicjalizuje tablicę o pojemności 4 i rozmiarze 0.
Tablica::Tablica() : capacity(4), size(0) {
    array = new int[capacity];
}

// Generacja losowych danych i zapisywanie ich do pliku "dane.txt".
void Tablica::generowanie_danych() {
    int liczba, dane;
    cout << "PODAJ LICZBE DANYCH DO WYGENEROWANIA: ";
    cin >> dane;
    fstream plik;
    plik.open("dane.txt", ios::out);
    for (int i = 0; i < dane; i++) {
        liczba = rand() % dane + 1; //Funkcja do generowania losowych danych
        plik << liczba << endl;
    }
    plik.close();
}

// Odczytuje dane z pliku "dane.txt" i dodaje je do tablicy.
void Tablica::odczyt_danych() {
    fstream plik;
    plik.open("dane.txt", ios::in);
    if (plik.good() == false) {
        cout << "plik nie istnieje";
        return;
    }
    string linia;
    // Odczytuje linie z pliku i dodaje je do tablicy.
    while (getline(plik, linia))
    {
        if (size == capacity) {
            podwojenie();        // Podwaja pojemność tablicy, jeśli jest pełna.
        }
        int number = stoi(linia);    // Konwertuje string na int.
        array[size++] = number;      // Dodaje element do tablicy.
    }
    plik.close();
}

// Zapisuje losowo wygenerowane liczby do tablicy.
void Tablica::zapisywanie() {
    int liczba, y, z = 0;
    cout << "podaj liczbe wyrazow tablicy: ";
    cin >> y;    // Liczba elementów do wygenerowania.
    while (z < y)
    {
        if (size == capacity) {
            podwojenie();    // Podwaja pojemność tablicy, jeśli jest pełna.
        }
        liczba = rand() % y + 1;    // Generuje losową liczbę.
        array[size++] = liczba;     // Dodaje wygenerowaną liczbę do tablicy.
        z++;
    }
}

// Dodaje element na końcu tablicy.
void Tablica::dodawanie_koniec(int element) {
    auto start = chrono::high_resolution_clock::now();    // Rozpoczyna pomiar czasu.
    if (size == capacity) {
        podwojenie();    // Podwaja pojemność tablicy, jeśli jest pełna.
    }
    array[size++] = element;    // Dodaje element na końcu tablicy.
    auto end = chrono::high_resolution_clock::now();    // Kończy pomiar czasu.
    // Obliczenie i wyświetlanie pomiaru czasu
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}

// Usuwa element z końca tablicy
void Tablica::usuwanie_koniec() {
    auto start = chrono::high_resolution_clock::now();    // Rozpoczyna pomiar czasu.
    int* koniec = new int[capacity];
    int i = 0;
    size--;    // Zmniejsza rozmiar tablicy, efektywnie usuwając ostatni element.
    while (i < size) {
        koniec[i] = array[i];
        i++;
    }
    delete[] array;
    array = koniec;
    auto end = chrono::high_resolution_clock::now();     // Kończy pomiar czasu.
     // Obliczenie i wyświetlanie pomiaru czasu
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}

// Dodaje element na początku tablicy.
void Tablica::dodawanie_poczatek(int element) {
    auto start = chrono::high_resolution_clock::now();    // Rozpoczyna pomiar czasu.
    if (size == capacity) {
        podwojenie();    // Podwaja pojemność tablicy, jeśli jest pełna.
    }
    size++;
    // Przesuwa wszystkie elementy o jedną pozycję w prawo, aby zrobić miejsce na początku.
    for (int x = size; x > 0; x--) {
        array[x] = array[x - 1];
    }
    array[0] = element;    // Wstawia nowy element na początku tablicy.
    auto end = chrono::high_resolution_clock::now();     // Kończy pomiar czasu.
     // Obliczenie i wyświetlanie pomiaru czasu
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}

// Usuwa element z początku tablicy.
void Tablica::usuwanie_poczatek() {
    auto start = chrono::high_resolution_clock::now();    // Rozpoczyna pomiar czasu.
    int* poczatek = new int[capacity];
    int i = 0;
    // Przesuwa wszystkie elementy o jedną pozycję w lewo, usuwając pierwszy element.
    for (int x = 1; x < size; x++) {
        array[x - 1] = array[x];
    }
    size--;    // Zmniejsza rozmiar tablicy.
    while (i < size) {
        poczatek[i] = array[i];
        i++;
    }
    delete[] array;
    array = poczatek;
    auto end = chrono::high_resolution_clock::now();     // Kończy pomiar czasu.
     // Obliczenie i wyświetlanie pomiaru czasu
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}

// Dodaje element w środku tablicy na wybranej przez użytkownika pozycji.
void Tablica::dodawanie_srodek() {
    int z, srodek;
    cout << "PODAJ POZYCJE NA KTORA CHCESZ DODAC LICZBE: ";
    cin >> z;// Pozycja, na której ma być wstawiony element.
    auto start = chrono::high_resolution_clock::now();    // Rozpoczyna pomiar czasu.
    if (z > size) {
        cout << "podane miejsce wykracza poza zakres";
        return;
    }
    size++;
    srodek = rand() % 99 + 1;    // Generuje losową liczbę do wstawienia
    // Przesuwa elementy, aby zrobić miejsce na nowy element.
    for (int x = size; x >= z; x--) {
        array[x] = array[x - 1];
    }
    array[z - 1] = srodek;    // Wstawia nowy element na wybraną pozycję.
    auto end = chrono::high_resolution_clock::now();     // Kończy pomiar czasu.
     // Obliczenie i wyświetlanie pomiaru czasu
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
// Usuwa element z wybranej przez użytkownika pozycji w środku tablicy.
void Tablica::usuwanie_srodek() {
    int* srodek = new int[capacity];    // Tworzy nową tablicę o bieżącej pojemności.
    int s, i = 0, n = 0;
    cout << "PODAJ POZYCJE DO USUNIECIA: ";
    cin >> s;    // Użytkownik podaje pozycję elementu do usunięcia.
    auto start = chrono::high_resolution_clock::now();    // Rozpoczyna pomiar czasu.
    size--;    // Zmniejsza rozmiar tablicy o jeden, ponieważ jeden element zostanie usunięty.
      // Kopiuje elementy do nowej tablicy pomijając element do usunięcia.
    while (i < size) {
        srodek[i] = array[n];
        i++;
        n++;
        if (i == (s - 1)) {    // Pomija element na pozycji s.
            n++;
        }
    }
    delete[] array;    // Zwalnia pamięć zajmowaną przez starą tablicę.
    array = srodek;    // Ustawia wskaźnik array na nową tablicę.
    auto end = chrono::high_resolution_clock::now();     // Kończy pomiar czasu.
     // Obliczenie i wyświetlanie pomiaru czasu
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}

// Wyszukuje w tablicy element równy podanej wartości i zwraca jego pozycję.
void Tablica::wyszukiwanie() {
    int szukana;
    cout << "PODAJ LICZBE KTORA CHCESZ ZWROCIC: ";
    cin >> szukana;
    auto start = chrono::high_resolution_clock::now();    // Rozpoczyna pomiar czasu.
    for (int i = 0; i < size; i++) {
        if (array[i] == szukana)    // Jeśli znajdzie wartość, wyświetla jej pozycję.
        {
            cout << "HURRA podana liczba znajduje sie na " << i + 1 << "pozycji" << endl;
            auto end = chrono::high_resolution_clock::now();     // Kończy pomiar czasu.
             // Obliczenie i wyświetlanie pomiaru czasu
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            cout << "---------------------" << endl;
            cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
            cout << "---------------------" << endl;
            return;
        }
        else if (i == (size - 1))
        {
            cout << "Niestety w zbiorze nie ma takiej liczby" << endl;
            return;
        }
    }
}
// Wyświetla wartość elementu na wybranej pozycji.
void Tablica::show() {
    int x;
    cout << "podaj warosc pozycji ktora chcesz zwrocic ";
    cin >> x;    // Użytkownik podaje pozycję elementu do wyświetlenia.
    if (x > size) {    // Sprawdza, czy pozycja nie wykracza poza zakres tablicy.
        cout << "tablica nie ma tulu elemenetów";
        return;
    }
    cout << "podany wtraz to " << array[x - 1];
}

// Wyświetla wszystkie elementy tablicy.
void Tablica::test() {
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}
