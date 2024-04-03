#include "Nagłówek.h"

//W tym kawałku kodu mamy implementacje funkcji dotyczących listy jednokierunkowej opierającej się na pojedynczym wskaźniku: head.
Lista_wiazana::Lista_wiazana() : head(nullptr) {}
// Destruktor zwalniający pamięć zarezerwowaną dla elementów listy.
Lista_wiazana::~Lista_wiazana() {
    while (head != nullptr) { // Dopóki lista nie jest pusta...
        Node* usun = head;    // Zapamiętuje obecny element do usunięcia.
        head = head->next;    // Przesuwa głowę listy na następny element.
        delete usun;    // Zwalnia pamięć obecnego elementu.
    }
}
// Dodaje elementy do listy na podstawie danych z pliku "dane.txt".
void Lista_wiazana::add() {
    fstream plik;
    plik.open("dane.txt", ios::in);
    // Sprawdzanie czy plik istnieje lub czy jest możliwość dostępu do niego
    if (plik.good() == false) {
        cout << "plik nie istnieje";
        return;
    }
    string linia;
    while (getline(plik, linia))     // Odczytuje plik linia po linii.
    {
        int number = stoi(linia);    // Konwertuje string na int.
         // Tworzy nowy węzeł i dodaje go na początku listy.
        Node* newNode = new Node(number);
        newNode->next = head;
        head = newNode;
    }
    plik.close();    //Zamyka plik
}
// Odwraca kolejność elementów w liście.
void Lista_wiazana::reverse() {
    Node* current = head;
    Node* prev = nullptr, * next = nullptr;

    while (current != nullptr) {    // Przechodzi przez listę.
        next = current->next;    // Zapamiętuje następny element.
        current->next = prev;    // Zmienia wskaźnik na poprzedni element.
        prev = current;        // Przesuwa prev i current o jeden element dalej.
        current = next;
    }
    head = prev; // Ustawia głowę listy na ostatni przetworzony element
}
// Dodaje element na początku listy.
void Lista_wiazana::dodaj_poczatek(int value) {
    auto start = chrono::high_resolution_clock::now();    // Rozpoczyna pomiar czasu.
    // Tworzy nowy węzeł i wstawia go na początku listy.
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    auto end = chrono::high_resolution_clock::now();    //Kończy pomiar czasu.
    // Oblicza i wyświetla czas wykonania operacji.
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
// Usuwa pierwszy element z listy.
void Lista_wiazana::usun_poczatek() {
    if (head != nullptr) {    //Standardowo sprawdza żeby lista nie była pusta.
        auto start = chrono::high_resolution_clock::now();    // Rozpoczyna pomiar czasu.
        Node* usun = head;    // Zapamiętuje element do usunięcia.
        head = head->next;    // Przesuwa głowę na następny element.
        delete usun;     // Zwalnia pamięć usuniętego elementu.
        auto end = chrono::high_resolution_clock::now();    //Kończy pomiar czasu.
        // Oblicza i wyświetla czas wykonania operacji.
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        cout << "---------------------" << endl;
        cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
        cout << "---------------------" << endl;
    }
    
}
// Dodaje nowy węzeł na końcu listy.
void Lista_wiazana::dodaj_koniec(int value) {
    auto start = chrono::high_resolution_clock::now();    // Rozpoczyna pomiar czasu.
    Node* newNode = new Node(value);    // Tworzy nowy węzeł.
    if (head == nullptr) {
        // Jeśli lista jest pusta, nowy węzeł staje się głową listy.
        head = newNode;
    }
    else {
        // W przeciwnym razie przechodzi listę do końca i dodaje nowy węzeł.
        Node* wezel = head;
        while (wezel->next != nullptr) {
            wezel = wezel->next;
        }
        wezel->next = newNode;
    }
    auto end = chrono::high_resolution_clock::now();    //Kończy pomiar czasu.
     // Oblicza i wyświetla czas wykonania operacji.
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
    
}
// Usuwa ostatni węzeł z listy.
void Lista_wiazana::usun_koniec() {
    auto start = chrono::high_resolution_clock::now();    // Rozpoczyna pomiar czasu.
    Node* wezel = head;
    // Przesuwa wskaźnik do przedostatniego węzła w liście.
    while (wezel->next->next != nullptr) {     
        wezel = wezel->next;
    }
    // Usuwa ostatni węzeł listy.
    delete wezel->next;
    // Ustawia wskaźnik następnego elementu przedostatniego węzła na nullptr.
    wezel->next = nullptr;
    auto end = chrono::high_resolution_clock::now();    //Kończy pomiar czasu.
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
     // Oblicza i wyświetla czas wykonania operacji.
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
//Dodawanie elementu w środek listy wiązanej
void Lista_wiazana::dodaj_srodek(int value) {
    // Pobiera od użytkownika pozycję, na której ma być dodany nowy węzeł.
    int pozycja;
    Node* newNode = new Node(value); //Tworzy nowy węzęł
    Node* wezel = head;
    cout << "PODAJ POZYCJE ELEMENTU: ";
    cin >> pozycja;
    auto start = chrono::high_resolution_clock::now();    // Rozpoczyna pomiar czasu.
    // Przesuwa wskaźnik do węzła poprzedzającego wybraną pozycję.
    for (int i = 0; i < (pozycja - 2); i++) {
        wezel = wezel->next;
    }
    // Wstawia nowy węzeł na wybraną pozycję.
    newNode->next = wezel->next;
    wezel->next = newNode;
    auto end = chrono::high_resolution_clock::now();    //Kończy pomiar czasu.
     // Oblicza i wyświetla czas wykonania operacji.
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
// Usuwanie elementu z wybranej pozycji listy jednokierunkowej
void Lista_wiazana::usun_srodek() {
    int pozycja;
    Node* wezel = head;
    cout << "PODAJ POZYCJE ELEMENTU DO USUNIECIA: ";
    cin >> pozycja;
    auto start = chrono::high_resolution_clock::now();    // Rozpoczyna pomiar czasu.
    // Obsługuje różne przypadki błędnych danych wejściowych i pustej listy.
    if (pozycja < 1) {
        cout << "bledna pozycja!" << endl;
        return;
    }
    else if (head == nullptr) {
        cout << "lista jest pusta" << endl;
        return;
    }
    // Usuwa węzeł z początku listy, jeśli pozycja to 1.
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
    // Przesuwa wskaźnik do węzła poprzedzającego węzeł do usunięcia.
    for (int i = 0; i < (pozycja - 2); i++) {
        wezel = wezel->next;
    }
    Node* temp = wezel->next; //Zapamiętuje węzeł do usunięcia
    wezel->next = temp->next; //Przepinanie wskażników
    delete temp;    // Usuwa wybrany węzeł.
    auto end = chrono::high_resolution_clock::now();    //Kończy pomiar czasu.
     // Oblicza i wyświetla czas wykonania operacji.
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
void Lista_wiazana::szukaj() {
    // Pobiera od użytkownika wartość szukanego węzła.
    int szukana, x = 1;
    cout << "PODAJ LICZBE KTOREJ SZUKASZ: ";
    cin >> szukana;
    auto start = chrono::high_resolution_clock::now();    // Rozpoczyna pomiar czasu.
    Node* wezel = head;
    // Przeszukuje listę w poszukiwaniu węzła o danej wartości.
    while (wezel != nullptr) {
        if (wezel->value == szukana) {
            cout << "SZUKANA ZNAJDUJE SIE NA " << x << " POZYCJI"<<endl;
            auto end = chrono::high_resolution_clock::now();    //Kończy pomiar czasu.
             // Oblicza i wyświetla czas wykonania operacji.
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            cout << "---------------------" << endl;
            cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
            cout << "---------------------" << endl;
            return;
        }
        wezel = wezel->next;
        x++;    // Licznik pozycji
    }
    cout << "NIESTETY LISTA NIE ZAWIERA SZUKANEJ LICZBY. SPROBOJ PONOWNIE"<<endl;
}
//Wyświetlanie elementów listy
void Lista_wiazana::show() {
    Node* element = head;
    // Przechodzi przez listę, wyświetlając wartości węzłów.
    while (element != nullptr) {
        cout << element->value << endl;
        element = element->next;
    }
    cout << "---------------------" << endl;
}
