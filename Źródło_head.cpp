#include "Nagłówek.h"


Lista_wiazana::Lista_wiazana() : head(nullptr) {}
Lista_wiazana::~Lista_wiazana() {
    while (head != nullptr) {
        Node* usun = head;
        head = head->next;
        delete usun;;
    }
}
void Lista_wiazana::add() {
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
        newNode->next = head;
        head = newNode;
    }
    plik.close();
}
void Lista_wiazana::reverse() {
    Node* current = head;
    Node* prev = nullptr, * next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev; 
}
void Lista_wiazana::dodaj_poczatek(int value) {
    auto start = chrono::high_resolution_clock::now();
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
void Lista_wiazana::usun_poczatek() {
    if (head != nullptr) {
        auto start = chrono::high_resolution_clock::now();
        Node* usun = head;
        head = head->next;
        delete usun;
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        cout << "---------------------" << endl;
        cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
        cout << "---------------------" << endl;
    }
    
}

void Lista_wiazana::dodaj_koniec(int value) {
    auto start = chrono::high_resolution_clock::now();
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        
        Node* wezel = head;
        while (wezel->next != nullptr) {
            wezel = wezel->next;
        }
        wezel->next = newNode;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
    
}

void Lista_wiazana::usun_koniec() {
    auto start = chrono::high_resolution_clock::now();
    Node* wezel = head;
    while (wezel->next->next != nullptr) {
        wezel = wezel->next;
    }
    delete wezel->next;
    wezel->next = nullptr;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
void Lista_wiazana::dodaj_srodek(int value) {
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
void Lista_wiazana::usun_srodek() {
    int pozycja;
    Node* wezel = head;
    cout << "PODAJ POZYCJE ELEMENTU DO USUNIECIA: ";
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
void Lista_wiazana::szukaj() {
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
    cout << "NIESTETY LISTA NIE ZAWIERA SZUKANEJ LICZBY. SPROBOJ PONOWNIE"<<endl;
}

void Lista_wiazana::show() {
    Node* element = head;
    while (element != nullptr) {
        cout << element->value << endl;
        element = element->next;
    }
    cout << "---------------------" << endl;
}
