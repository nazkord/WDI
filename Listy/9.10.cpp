#include <iostream>
#include <cstdlib>
#include <ctime>

/* Proszę napisać funkcję, otrzymującą jako parametr wskaźnik na pierwszy
element listy o wartościach typu int, usuwającą wszystkie elementy, których
wartość dzieli bez reszty wartość bezpośrednio następujących po nich
elementów. */

int const N = 5;

struct node {
    int value;
    node *next;
};

void print_out_list(node *first) {
    while(first != nullptr) {
        std::cout << first->value << " ";
        first = first->next;
    }
}

// I sposob (warunek dla ktorego i kolejnego)
void usunac1(node *&first) {
    //jezeli lista jest pusta lub zawiera tylko jeden element
    if(first == nullptr || first -> next == nullptr)
        return;

    node *prev = first;
    node *p = first -> next;

    //sprawdzenie pierwszych dwoch elementow
    while(((p->value) % (prev->value)) == 0) {
        first = p;
        prev = p;
        if (p->next != nullptr)
            p = p->next;
        else
            return;
    }

    //sprawdzenie reszty elementow(wlacznie z ostatnim)
    //sprawdzamy p->next i p element i jezeli trzeba to usuwany p
    //czyli laczymy prev i p->next
    while(p -> next != nullptr) {
        if((p -> next -> value) % (p-> value) == 0) {
            prev -> next = p -> next;
            p = p -> next;
        } else {
            p = p -> next;
            prev = prev -> next;
        }
    }

}

int main() {

    //pierwszy element
    node *first = new node;
    std::cin >> first -> value;
    first -> next = nullptr;

    node *p;
    node *prev = first;
    for(int i = 0; i < N - 1; i++) {
        p = new node;
        std::cin >> p -> value;
        p -> next = nullptr;
        prev -> next = p;
        prev = p;
    }

    print_out_list(first);

    usunac1(first);

    std::cout<<"\n";
    print_out_list(first);


    return 0;
}