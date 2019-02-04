#include <iostream>
#include <cstdlib>
#include <ctime>

int const N = 10;

struct node {
    int value;
    node *next;
};

void print_out_list(node *first) {
    while(first != nullptr) {
        std::cout << first -> value << " ";
        first = first -> next;
    }
}

void glowna_funkcja(node *&first, int key) {
    node *p = first;
    node *prev = first;
    //gdy klucz jest pierwszym elementem (musimy go usunac)
    if(first->value == key) {
        first = first->next;
        return;
    }

    p = p -> next;
    while( p -> next != nullptr) {
        if(p -> value == key) {
            //"omijamy" ten element
            prev -> next = p -> next;
            return ;
        } else {
            p = p -> next;
            prev = prev -> next;
        }
    }

    //gdy klucz jest ostatnim elementem
    if(p->value == key) {
        prev -> next = nullptr;
        return;
    }

    //jezeli doszlismy tutaj, to musimy dodac klucz na koniec
    prev = new node;
    prev -> value = key;
    prev -> next = nullptr;
    p -> next = prev;
    return;
}

int main() {
    srand(time(0));

    int key;
    node *first = nullptr;

    node*p;
    for(int i = 0; i < N; i++) {
        p = new node;
        p -> value = rand()%50;
        p -> next = first;
        first = p;
    }

    print_out_list(first);

    std::cout << "\n" << "WPISZ KLUCZ: ";
    std::cin>>key;
    glowna_funkcja(first,key);

    print_out_list(first);

    return 0;
}