#include <iostream>

/* . Dwie listy zawierają niepowtarzające się (w obrębie listy) liczby
naturalne. W obu listach liczby są posortowane rosnąco. Proszę napisać
funkcję usuwającą z każdej listy liczby nie występujące w drugiej. Do
funkcji należy przekazać wskazania na obie listy, funkcja powinna zwrócić
łączną liczbę usuniętych elementów. */

int const N1 = 7;

int const N2 = 7;

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

int oczyscic(node *&first1, node *&first2) {
    //wartowniki
    node *wartownik1 = new node;
    wartownik1->next = first1;

    node *wartownik2 = new node;
    wartownik2->next = first2;

    node *p1 = first1;
    node *p2 = first2;
    node *prev1 = wartownik1;
    node *prev2 = wartownik2;
    int counter = 0;

    //glowna petla!
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->value < p2->value) {
            //usuwamy z 1 listy
            if (p1 == first1) {
                p1 = p1->next;
                prev1->next = p1;
                first1 = p1;
            } else {
                p1 = p1->next;
                prev1->next = p1;
            }

            counter++;
        } else if (p1->value > p2->value) {
            //usuwamy z 2 listy
            if (p2 == first2) {
                p2 = p2->next;
                prev2->next = p2;
                first2 = p2;
            } else {
                p2 = p2->next;
                prev2->next = p2;
            }
            counter++;
        } else {
            p1 = p1->next;
            prev1 = prev1->next;
            p2 = p2->next;
            prev2 = prev2->next;
        }
    }

    //jesli dojdziemy nie rowno do koncow list
    if (p1 == nullptr && p2 != nullptr) {
        while (p2 != nullptr) {
            counter++;
            p2 = p2->next;
        }
        prev2->next = nullptr;
    } else if(p2 == nullptr && p1!= nullptr){
        while(p1 != nullptr) {
            counter++;
            p1 = p1 -> next;
        }
        prev1 ->next = nullptr;
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

    std::cout << "Usunieto: " << oczyscic(first1, first2);

    std::cout << "\n";

    print_out_list(first1);

    std::cout << "\n";

    print_out_list(first2);




    return 0;
}