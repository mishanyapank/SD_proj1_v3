#ifndef NAGŁÓWEK_H
#define NAGŁÓWEK_H
#include<iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <chrono>

using namespace std;


class Tablica {
private:
    int* array;
    size_t capacity;
    size_t size;

    void podwojenie();
public:
    Tablica();
    ~Tablica() {
        delete[] array;
    }
    void generowanie_danych();
    void odczyt_danych();
    void zapisywanie();
    void dodawanie_koniec(int element);
    void usuwanie_koniec();
    void dodawanie_poczatek(int element);
    void usuwanie_poczatek();
    void dodawanie_srodek();
    void usuwanie_srodek();
    void wyszukiwanie();
    void show();
    void test();
};
struct Node {
    int value;
    Node* next;

    Node(int value) : value(value), next(nullptr) {}
};

class Lista_wiazana {
private:
    Node* head;
public:
    Lista_wiazana();
    ~Lista_wiazana();
    void add();
    void reverse();
    void dodaj_poczatek(int value);
    void usun_poczatek();
    void dodaj_koniec(int value);
    void usun_koniec();
    void dodaj_srodek(int value);
    void usun_srodek();
    void szukaj();
    void show();
};
class Lista_tail {
private:
    Node* head;
    Node* tail;
public:
    Lista_tail();
    ~Lista_tail();
    void add();
    void dodaj_poczatek(int value);
    void usun_poczatek();
    void dodaj_koniec(int value);
    void usun_koniec();
    void dodaj_srodek(int value);
    void usun_srodek();
    void szukaj();
    void show();
};
#endif
