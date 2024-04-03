// W tym kswałku kodu mamy implementacje listy jednokierunkowej 
// opierająca się na dwóch wskaźnikach: head, tail.
 
#include "Nagłówek.h"

// Konstruktor inicjalizuje pustą listę ustawiając wskaźniki head i tail na nullptr.
Lista_tail::Lista_tail() : head(nullptr), tail(nullptr) {}
// Destruktor zwalnia pamięć zarezerwowaną dla elementów listy, przeglądając listę od head do tail.
Lista_tail::~Lista_tail(){
    while (head != nullptr) {
        Node* usun = head;    // Zapamiętuje węzeł do usunięcia.
        head = head->next;    // Przesuwa head do następnego węzła.
        delete usun;          // Zwalnia pamięć aktualnego węzła.
    }
    // Ustawia wskaźniki head i tail na nullptr
    head = nullptr;
    tail = nullptr;
}
// Dodaje elementy do listy na podstawie danych z pliku "dane.txt".
void Lista_tail::add() {
    fstream plik;
    plik.open("dane.txt", ios::in);    // Otwiera plik do odczytu
    if (plik.good() == false) {        // Sprawdza czy można odczytać dane z pliku
        cout << "plik nie istnieje";
        return;
    }
    string linia;
    while (getline(plik, linia)) // Przechodzi się po pliku
    {
        int number = stoi(linia); // string do int
        Node* newNode = new Node(number);    // Tworzy nowy węzeł.
        if (head == nullptr) {
            head = newNode;    // Jeśli lista jest pusta, nowy węzeł staje się head i tail
        }
        else {
            tail->next = newNode;    //W przeciwnym razie, dodaje węzeł na końcu listy.
            }
        tail = newNode;    // Aktualizuje tail do nowo dodanego węzła.
    }
    plik.close();
}
// Dodaje nowy węzeł na początku listy.
void Lista_tail::dodaj_poczatek(int value) {
    auto start = chrono::high_resolution_clock::now();     //Początek zapisywania czasu.
    Node* newNode = new Node(value);    // Tworzy nowy węzeł.
    if (head == nullptr) {    // Jeśli lista jest pusta, nowy węzeł staje się head i tail.
        head = tail = newNode;
    }
    else {
        newNode->next = head;    // W przeciwnym razie, ustawia nowy węzeł jako head.
        head = newNode;
    }
    auto end = chrono::high_resolution_clock::now();    // Koniec zapisywania czasu.
    // Obliczenie i wyświetlanie czasu.
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start); 
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
// Usuwa węzeł z początku listy.
void Lista_tail::usun_poczatek() {
    auto start = chrono::high_resolution_clock::now();     //Początek zapisywania czasu.
    if (head != nullptr) {
        Node* usun = head;    // Zapamiętuje węzeł do usunięcia.
        head = head->next;    // Przesuwa head do następnego węzła.
        delete usun;          // Zwalnia pamięć aktualnego węzła.
    }
    auto end = chrono::high_resolution_clock::now();    // Koniec zapisywania czasu.
    // Obliczenie i wyświetlenie czasu.
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
// Metoda dodająca nowy węzeł na koniec listy.
void Lista_tail::dodaj_koniec(int value) {
    auto start = chrono::high_resolution_clock::now();     //Początek zapisywania czasu.
    Node* newNode = new Node(value);    // Tworzy nowy węzeł z podaną wartością.
    if (head == nullptr) {    // Jeśli lista jest pusta, nowy węzeł staje się jednocześnie głową i ogonem listy.
        head = newNode;
        tail = newNode;
    }
    else {    // W przeciwnym przypadku, dodaje nowy węzeł na koniec listy i aktualizuje wskaźnik tail.
        tail->next = newNode;
        tail = newNode;
    }
    auto end = chrono::high_resolution_clock::now();    // Koniec zapisywania czasu.
    // Obliczenie i wyświetlenie czasu.
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
// Metoda usuwająca ostatni węzeł z listy.
void Lista_tail::usun_koniec() {
    if (head == nullptr) return;    // Lista jest pusta, nie ma co usuwać.
    if (head == tail) {    // Lista ma tylko jeden element, więc usuwa ten element i ustawia head i tail na nullptr.
        delete head;
        head = tail = nullptr;
        return;
    }
    auto start = chrono::high_resolution_clock::now();     //Początek zapisywania czasu.
    // Znajduje przedostatni węzeł listy.
    Node* wezel = head;
    while (wezel->next != tail) {
        wezel = wezel->next;
    }
    delete tail;    // Usuwa ostatni węzeł.
    tail = wezel;    // Aktualizuje wskaźnik tail na przedostatni węzeł.
    tail->next = nullptr;    // Ustawia next ostatniego węzła na nullptr.
    auto end = chrono::high_resolution_clock::now();    // Koniec zapisywania czasu.
    // Obliczenie i wyświetlenie czasu.
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
// Metoda dodająca nowy węzeł na wybranej pozycji w liście.
void Lista_tail::dodaj_srodek(int value) {
    int pozycja;
    Node* newNode = new Node(value); // Robi nowy węzeł.
    Node* wezel = head;
    cout << "PODAJ POZYCJE ELEMENTU: ";
    cin >> pozycja;    // Podanie pozycji.
    auto start = chrono::high_resolution_clock::now();     //Początek zapisywania czasu.
    // Przesuwa wskaźnik do węzła bezpośrednio przed pozycją, na której ma zostać wstawiony nowy węzeł.
    for (int i = 0; i < (pozycja - 2); i++) {
        wezel = wezel->next;
    }
     // Wstawia nowy węzeł do listy na wybranej pozycji (oczywiście zgodnie ze schematem, żeby nie zgubić połączenia z ogonem listy).
    newNode->next = wezel->next;
    wezel->next = newNode;
    auto end = chrono::high_resolution_clock::now();    // Koniec zapisywania czasu.
    // Obliczenie i wyświetlenie czasu.
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
// Metoda usuwająca węzeł z wybranej pozycji.
void Lista_tail::usun_srodek() {
    int pozycja;
    Node* wezel = head;
    cout << "PODAJ POZYCJE DO USUNIECIA: ";
    cin >> pozycja; // Pozycja do usunięcia.
    auto start = chrono::high_resolution_clock::now();     //Początek zapisywania czasu.
    // Sprawdza warunki brzegowe: nieprawidłowa pozycja, pusta lista.
    if (pozycja < 1) {
        cout << "bledna pozycja!" << endl;
        return;
    }
    else if (head == nullptr) {
        cout << "lista jest pusta" << endl;
        return;
    }
    // Obsługuje specjalny przypadek usunięcia pierwszego węzła.
    else if (pozycja == 1) {
        Node* temp = head;    // Zapamiętuje węzeł do usunięcia.
        head = head->next;    // Przesuwa głowę na następny węzeł.
        delete temp;    // Usuwa węzeł.
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
    Node* temp = wezel->next;    // Zapamiętuje węzeł do usunięcia.
    wezel->next = temp->next;    // Przepina wskaźnik na następny węzeł po usuniętym.
    delete temp;    // Usuwa węzeł.
    auto end = chrono::high_resolution_clock::now();    // Koniec zapisywania czasu.
    // Obliczenie i wyświetlenie czasu.
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "---------------------" << endl;
    cout << "CZAS WYKONANIA: " << duration.count() << "NS" << endl;
    cout << "---------------------" << endl;
}
//Wyszukiwanie elentu w liście.
void Lista_tail::szukaj() {
    int szukana, x = 1;
    cout << "PODAJ LICZBE KTOREJ SZUKASZ: ";
    cin >> szukana;    // Wartość do wyszukiwania.
    auto start = chrono::high_resolution_clock::now();     //Początek zapisywania czasu.
    Node* wezel = head;    // Węzeł wskazuje na pierwszy element listy.
    // Przeszukuje listę w poszukiwaniu węzła o danej wartości.
    while (wezel != nullptr) {
        if (wezel->value == szukana) {
            cout << "SZUKANA ZNAJDUJE SIE NA " << x << " POZYCJI"<<endl;
            auto end = chrono::high_resolution_clock::now();    // Koniec zapisywania czasu.
            // Obliczenie i wyświetlenie czasu.
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
// Wyświetlanie wszystkich elementów listy.
void Lista_tail::show() {
    Node* wezel = head; // Węzeł wskazuje na pierwszy element listy.
    // Przechodzi przez całą listę, wyświetlając wartości poszczególnych węzłów.
    while (wezel != nullptr) {
        cout << wezel->value << endl;
        wezel = wezel->next;
    }
    cout << "---------------------" << endl;
}
