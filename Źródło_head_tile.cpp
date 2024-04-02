#include "Nagłówek.h"

Lista_tail::Lista_tail() : head(nullptr), tail(nullptr) {}
Lista_tail::~Lista_tail(){
    while (head != nullptr) {
        Node* usun = head;
        head = head->next;
        delete usun;;
    }
    head = nullptr;
    tail = nullptr;
}
void Lista_tail::add() {
    fstream plik;
    plik.open("dane.txt", ios::in);
    if (plik.good() == false) {
        cout << "plik nie istnieje";
        return;
    }
    string linia;
    while (getline(plik, linia))
    {
        int number = stoi(linia);
        Node* newNode = new Node(number);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            tail->next = newNode;
            }
        tail = newNode;
    }
    plik.close();
}
void Lista_tail::dodaj_poczatek(int value) {
    auto start = chrono::high_resolution_clock::now();
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
void Lista_tail::usun_poczatek() {
    auto start = chrono::high_resolution_clock::now();
    if (head != nullptr) {
        Node* usun = head;
        head = head->next;
        delete usun;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
void Lista_tail::dodaj_koniec(int value) {
    auto start = chrono::high_resolution_clock::now();
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
void Lista_tail::usun_koniec() {
    if (head == nullptr) return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }
    auto start = chrono::high_resolution_clock::now();
    Node* wezel = head;
    while (wezel->next != tail) {
        wezel = wezel->next;
    }
    delete tail;
    tail = wezel;
    tail->next = nullptr;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
void Lista_tail::dodaj_srodek(int value) {
    int pozycja;
    Node* newNode = new Node(value);
    Node* wezel = head;
    cout << "PODAJ POZYCJE ELEMENTU: ";
    cin >> pozycja;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < (pozycja - 2); i++) {
        wezel = wezel->next;
    }
    newNode->next = wezel->next;
    wezel->next = newNode;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
void Lista_tail::usun_srodek() {
    int pozycja;
    Node* wezel = head;
    cout << "PODAJ POZYCJE DO USUNIECIA: ";
    cin >> pozycja;
    auto start = chrono::high_resolution_clock::now();
    if (pozycja < 1) {
        cout << "bledna pozycja!" << endl;
        return;
    }
    else if (head == nullptr) {
        cout << "lista jest pusta" << endl;
        return;
    }
    else if (pozycja == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    else if (wezel->next == nullptr) {
        cout << "pozycja poza zakresem" << endl;
        return;
    }

    for (int i = 0; i < (pozycja - 2); i++) {
        wezel = wezel->next;
    }
    Node* temp = wezel->next;
    wezel->next = temp->next;
    delete temp;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
void Lista_tail::szukaj() {
    int szukana, x = 1;
    cout << "PODAJ LICZBE KTOREJ SZUKASZ: ";
    cin >> szukana;
    auto start = chrono::high_resolution_clock::now();
    Node* wezel = head;
    while (wezel != nullptr) {
        if (wezel->value == szukana) {
            cout << "SZUKANA ZNAJDUJE SIE NA " << x << " POZYCJI"<<endl;
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            cout << "---------------------" << endl;
            cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
            cout << "---------------------" << endl;
            return;
        }
        wezel = wezel->next;
        x++;
    }
    cout << "NIESTETY LISTA NIE ZAWIERA TAKIEJ LICZBY. SPROBOJ PONOWNIE"<<endl;
}

void Lista_tail::show() {
    Node* wezel = head;
    while (wezel != nullptr) {
        cout << wezel->value << endl;
        wezel = wezel->next;
    }
    cout << "---------------------" << endl;
}
