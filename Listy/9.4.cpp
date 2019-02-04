#include <iostream>

/*  Dana jest niepusta lista reprezentująca liczbę naturalną. Kolejne
elementy listy przechowują kolejne cyfry. Proszę napisać funkcję
zwiększającą taką liczbę o 1. */

/* 1. Dochodzimy do konca listy
 2. Sprawdzamy czy ostatni int jest 9:
    - Tak, zerujemy go i poprzedni zwiekszamy o jeden
    - Nie, zwiekszamy go o jeden */


int const N = 5;

struct node {
    int value;
    node *next, *prev;
};

struct wart {
    int count;
    node *head, *tail;
};

void print_out_list(wart *wartownik) {
    node *p = wartownik -> head;
    while(p!= nullptr) {
        std::cout<< p -> value << " ";
        p = p -> next;
    }
}

int main() {

    //wskaznik na poczatek listy i pierwszy element
    node *first = new node;
    first -> next = nullptr;
    first -> prev = nullptr;
    std::cin>>first -> value;

    //deklaracja wartonwika
    wart *wartownik = new wart;
    wartownik -> head = first;
    wartownik -> count = 1;


    //wypelnienie listy dodajac na poczatek
    /* node *p;

    for(int i = 0; i < N; i++) {
        p = new node;
        std::cin>> p -> value;
        p -> prev = nullptr;
        p -> next = first;
        first = p;
    } */

    //wypelnienie listy dodajac na koniec
    node *p, *prevq;
    prevq = first;

    for(int i = 0; i < N - 1; i++) {

        //tworzymy nowy element p
        p = new node;
        std::cin>> p->value;
        p -> prev = prevq;
        p -> next = nullptr;

        //laczymy poprzedni (ostatni) element listy z nowym p
        prevq -> next = p;
        prevq = p;

        //uzupelniamy wartownika
        wartownik -> count += 1;
        wartownik -> tail = p;
    }

    print_out_list(wartownik);
    std::cout<<"\n";

    //zaczynamy od konca
    p = wartownik -> tail;
    while((p != nullptr) && (p -> value == 9)) {
        p->value = 0;
        p = p -> prev;
    }

    if(p == nullptr) {
        p = new node;
        p -> value = 1;
        p -> prev = nullptr;
        p -> next = wartownik -> head;
        wartownik -> head = p;
    } else {
        p -> value ++;
    }

    print_out_list(wartownik);

    return 0;
}