#include "Nagłówek.h"

void Tablica::podwojenie() {
    capacity = 2 * size;
    int* nowy = new int[capacity];
    int i = 0;
    while (i < size) {
        nowy[i] = array[i];
        i++;
    }
    delete[] array;
    array = nowy;
}

Tablica::Tablica() : capacity(4), size(0) {
    array = new int[capacity];
}
void Tablica::generowanie_danych() {
    int liczba, dane;
    cout << "PODAJ LICZBE DANYCH DO WYGENEROWANIA: ";
    cin >> dane;
    fstream plik;
    plik.open("dane.txt", ios::out);
    for (int i = 0; i < dane; i++) {
        liczba = rand() % dane + 1;
        plik << liczba << endl;
    }
    plik.close();
}
void Tablica::odczyt_danych() {
    fstream plik;
    plik.open("dane.txt", ios::in);
    if (plik.good() == false) {
        cout << "plik nie istnieje";
        return;
    }
    string linia;
    while (getline(plik, linia))
    {
        if (size == capacity) {
            podwojenie();
        }
        int number = stoi(linia);
        array[size++] = number;
    }
    plik.close();
}

void Tablica::zapisywanie() {
    int liczba, y, z = 0;
    cout << "podaj liczbe wyrazow tablicy: ";
    cin >> y;
    while (z < y)
    {
        if (size == capacity) {
            podwojenie();
        }
        liczba = rand() % y + 1;
        array[size++] = liczba;
        z++;
    }
}

void Tablica::dodawanie_koniec(int element) {
    auto start = chrono::high_resolution_clock::now();
    if (size == capacity) {
        podwojenie();
    }
    array[size++] = element;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}

void Tablica::usuwanie_koniec() {
    auto start = chrono::high_resolution_clock::now();
    int* koniec = new int[capacity];
    int i = 0;
    size--;
    while (i < size) {
        koniec[i] = array[i];
        i++;
    }
    delete[] array;
    array = koniec;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}

void Tablica::dodawanie_poczatek(int element) {
    auto start = chrono::high_resolution_clock::now();
    if (size == capacity) {
        podwojenie();
    }
    size++;
    for (int x = size; x > 0; x--) {
        array[x] = array[x - 1];
    }
    array[0] = element;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}

void Tablica::usuwanie_poczatek() {
    auto start = chrono::high_resolution_clock::now();
    int* poczatek = new int[capacity];
    int i = 0;
    for (int x = 1; x < size; x++) {
        array[x - 1] = array[x];
    }
    size--;
    while (i < size) {
        poczatek[i] = array[i];
        i++;
    }
    delete[] array;
    array = poczatek;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
void Tablica::dodawanie_srodek() {
    int z, srodek;
    cout << "PODAJ POZYCJE NA KTORA CHCESZ DODAC LICZBE: ";
    cin >> z;
    auto start = chrono::high_resolution_clock::now();
    if (z > size) {
        cout << "podane miejsce wykracza poza zakres";
        return;
    }
    size++;
    srodek = rand() % 99 + 1;
    for (int x = size; x >= z; x--) {
        array[x] = array[x - 1];
    }
    array[z - 1] = srodek;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
void Tablica::usuwanie_srodek() {
    int* srodek = new int[capacity];
    int s, i = 0, n = 0;
    cout << "PODAJ POZYCJE DO USUNIECIA: ";
    cin >> s;
    auto start = chrono::high_resolution_clock::now();
    size--;
    while (i < size) {
        srodek[i] = array[n];
        i++;
        n++;
        if (i == (s - 1)) {
            n++;
        }
    }
    delete[] array;
    array = srodek;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}

void Tablica::wyszukiwanie() {
    int szukana;
    cout << "PODAJ LICZBE KTORA CHCESZ ZWROCIC: ";
    cin >> szukana;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        if (array[i] == szukana)
        {
            cout << "HURRA podana liczba znajduje sie na " << i + 1 << "pozycji" << endl;
            auto end = chrono::high_resolution_clock::now();
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

void Tablica::show() {
    int x;
    cout << "podaj warosc pozycji ktora chcesz zwrocic ";
    cin >> x;
    if (x > size) {
        cout << "tablica nie ma tulu elemenetów";
        return;
    }
    cout << "podany wtraz to " << array[x - 1];
}

void Tablica::test() {
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}
