#include <iostream>

// scalic dwie posortowane listy

int const N1 = 5;

int const N2 = 2;

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

node * scalanie(node *&p1, node *&p2)  {
    //sprawdzenie czy ktoras nie jest pusta
    if(p1 == nullptr)
        return p2;
    if(p2 == nullptr)
        return p1;

    //wskazniki operujace na pierwszej liscie
    //podpinam wszystko pod pierwsza liste
    node *first,*q,*v;
    if(p1 -> value < p2 -> value) {
        first = p1;
        p1 = p1 -> next;
        v = p2;
    } else {
        q = p1;
        first = p2;
        p1 = p2 -> next;
        p2 = q;
        v = p2;
    }

    q = first;

    //glowna petla while
    while(p1 != nullptr && p2 != nullptr) {
        //jezeli element z p2 < p1 wstawiamy go do p1
        if(p1 -> value > p2 -> value) {
            p2 = p2 -> next;
            q -> next = v;
            v -> next = p1;
            v = p2;
            q = q -> next;
        } else {
            //jesli nie, idziemy dalej
            q = p1;
            p1 = p1 -> next;
        }
    }

    //koncowki

    return first;
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

    node *first3 = scalanie(first1,first2);

    std::cout << "\n";

    print_out_list(first3);

    return 0;
}