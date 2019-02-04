#include <iostream>

/* Lista reprezentuje wielomian o współczynnikach całkowitych. Elementy w
liście ułożone są według rosnących potęg. Proszę napisać funkcję
obliczającą różnicę dwóch dowolnych wielomianów. Wielomiany reprezentowane
są przez wyżej opisane listy. Procedura powinna zwracać wskaźnik do nowo
utworzonej listy reprezentującej wielomian wynikowy. Listy wejściowe
powinny pozostać niezmienione. */

int const N1 = 0;

int const N2 = 1;

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

node * dodaj(node *first1, node *first2) {
    node * p = nullptr;
    node * last = nullptr;

    while(first1 != nullptr && first2 != nullptr) {
        node * temp = new node;
        temp -> value = first1 -> value + first2 -> value;
        temp -> next = nullptr;
        if(p == nullptr) {
            p = temp;
            last = temp;
        } else {
            last -> next = temp;
            last = temp;
        }
        first1 = first1 -> next;
        first2 = first2 -> next;
    }

    while(first1 != nullptr) {
        node * temp = new node;
        temp -> value = first1 -> value;
        temp -> next = nullptr;
        last -> next = temp;
        last = temp;
        first1 = first1 -> next;
    }

    while(first2 != nullptr) {
        node * temp = new node;
        temp -> value = first2 -> value;
        temp -> next = nullptr;
        if(p == nullptr) {
            p = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
        first2 = first2 -> next;
    }

    return p;
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

    print_out_list(dodaj(first1,first2));

    return 0;
}