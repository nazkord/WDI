#include <iostream>

/* Dwie listy zawierają niepowtarzające się (w obrębie listy) liczby
naturalne. W pierwszej liście liczby są posortowane rosnąco, a w drugiej
nie. Proszę napisać funkcję usuwającą z obu list liczby występujące w obu
listach. Do funkcji należy przekazać wskazania na obie listy, funkcja
powinna zwrócić łączną liczbę usuniętych elementów. */

int const N1 = 8;

int const N2 = 8;

struct node {
    node *next;
    int value;
};

void print_out_list(node *first) {
    while(first != nullptr) {
        std::cout << first -> value << " ";
        first = first -> next;
    }
}

int oczysc(node *&first1, node *&first2) {
    //dodaje wartownik do obu listy
    node *wartownik1 = new node;
    wartownik1 -> next = first1;

    node *wartownik2 = new node;
    wartownik2 -> next = first2;


    node *prev1 = wartownik1;
    node *prev2 = wartownik2;
    node *p1 = first1;
    node *p2 = first2;
    int counter = 0;

    while(p2 != nullptr) {
        while(p1 != nullptr && p1 -> value < p2 -> value) {
            p1 = p1 -> next;
            prev1 = prev1 -> next;
        }

        if(p1 != nullptr && p1 -> value == p2 -> value) {
            //usuwamy z 1 listy
            if(p1 == first1) {
                p1 = p1->next;
                prev1->next = p1;
                first1 = p1;
            } else {
                p1 = p1->next;
                prev1->next = p1;
            }

            //usuwamy z 2 listy
            if(p2 == first2) {
                p2 = p2->next;
                prev2->next = p2;
                first2 = p2;
            } else {
                p2 = p2->next;
                prev2->next = p2;
            }

            counter+=2;
        } else {
            p2 = p2 -> next;
            prev2 = prev2 -> next;
        }

        p1 = first1;
        prev1 = wartownik1;
    }

    wartownik1 -> next = nullptr;

    wartownik2 -> next = nullptr;

    return counter;
}

int main() {

    //pierwsza lista
    node *first1 = nullptr;
    node *p;
    for(int i = 0; i < N1; i++) {
        // 1 krok
        p = new node;
        std::cin >> p -> value;
        p -> next = first1;

        //2 krok
        first1 = p;
    }

    //druga lista
    node *first2 = nullptr;
    for(int i = 0; i < N2; i++) {
        // 1 krok
        p = new node;
        std::cin >> p -> value;
        p -> next = first2;

        //2 krok
        first2 = p;
    }

    print_out_list(first1);

    std::cout << "\n";

    print_out_list(first2);

    std::cout << "\n";

    std::cout << "Usunieto: " << oczysc(first1, first2) << "\n";

    print_out_list(first1);

    std::cout << "\n";

    print_out_list(first2);

    return 0;
}