#include <iostream>
#include <cstdlib>
#include <ctime>

/*  Dana jest niepusta lista, proszę napisać funkcję usuwającą co ktorys
(wpisujemy z klawiatury) element listy. Do funkcji należy przekazać
wskazanie na pierwszy element listy.   */

const int N = 5;

struct node {
    int value;
    node *next;
};

void print_out_list(node *p) {
    while(p != nullptr) {
        std::cout<< p -> value << " ";
        p = p -> next;
    }
    std::cout<<"\n";
}

void remove_every(node *&first, int x) {

    //sprawdzamy czy lista jest pusta
    if(first == nullptr || first -> next == nullptr)
        return;

    node *p = first;
    int q = 1;

    while(p -> next != nullptr) {
        if((q+1) % x == 0) {
            //gdy za usuwanym elementem nic nie ma
            if(p -> next -> next == nullptr)
                p -> next = nullptr;
            //gdy za usuwanym elementem cos jest
            else {
                p->next = p->next->next;
                p = p->next;
                q += 2;
            }
        } else {
            p = p -> next;
            q++;
        }
    }

}

int main() {
    srand(time(0));

    node *first = nullptr;
    node *p;

    for(int i = 0; i < N; i++) {
        p = new node;
        p -> value = rand()%10+1;
        p -> next = first;
        first = p;
    }

    print_out_list(first);

    int x;
    std::cout<<"CO KTORY ELEMENT CHCESZ USUWAC: ";
    std::cin>>x;

    remove_every(first, x);

    print_out_list(first);

    return 0;
}