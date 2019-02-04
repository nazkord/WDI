#include <iostream>

/* Dane są dwie niepuste listy, z których każda zawiera niepowtarzające
się elementy. Elementy w pierwszej liście są uporządkowane rosnąco, w
drugiej elementy występują w przypadkowej kolejności. Proszę napisać
funkcję, która z dwóch takich list stworzy jedną, w której uporządkowane
elementy będą stanowić sumę mnogościową elementów z list wejściowych.
Do funkcji należy przekazać wskazania na obie listy, funkcja powinna
zwrócić wskazanie na listę wynikową. Na przykład dla list:
2 -> 3 -> 5 ->7-> 11
8 -> 2 -> 7 -> 4
powinna pozostać lista:
2 -> 3 -> 4 -> 5 ->7-> 8 -> 11 */

int const N1 = 6;

int const N2 = 6;

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

node * polacz(node *first1, node *first2) {
    //deklarowanie wskaznikow pomocniczych
    node *w1 = new node;
    w1 -> next = first1;

    node *p1 = first1;
    node *prev1 = w1;
    node *p2 = first2;

    //glowna petla
    while (p2 != nullptr) {
        while(p1 != nullptr && p1 -> value < p2 -> value) {
            p1 = p1 -> next;
            prev1 = prev1 -> next;
        }

        //jezeli mozemy dodac
        if(p1 != nullptr && p1 -> value != p2 -> value) {
            //dodajemy na poczatek
            if(p1 == first1) {
                node *p = new node;
                p -> value = p2 -> value;
                prev1 -> next = p;
                p -> next = p1;
                p1 = p;
                first1 = p;
            } else {
                //dodajemy gdzies w srodku
                node *p = new node;
                p->value = p2->value;
                prev1->next = p;
                p->next = p1;
                p1 = p;
            }
        } else if(p1 == nullptr) {
            //dodajemy na koniec
            node *p = new node;
            p -> value = p2 -> value;
            prev1 -> next = p;
            p -> next = p1;
            p1 = p;
        } else {
            //nic nie robimy, czyli idziemy dalej
            p2 = p2 ->next;
        }
        //ustawiamy wskazniki 1 listy na poczatek
        p1 = first1;
        prev1 = w1;

    }
    return first1;
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

    print_out_list(polacz(first1,first2));

    return 0;
}