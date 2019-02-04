#include <iostream>

int const N = 5;

struct node {
    int value;
    node *next;
};

bool zapis_osiemkowy(int x) {
    int temp = x;
    int y = 0;
    while(temp > 0) {
        y = y*10 + temp%8;
        temp /= 8;
    }

    int counter = 0;
    while(y > 0) {
        if(y % 10 == 5)
            counter ++;
        y /= 10;
    }
    return (counter % 2 == 0 && counter != 0);
}

void print_out_list(node *p) {
    while(p!= nullptr) {
        std::cout << p -> value << " ";
        p = p-> next;
    }
}

void przeniesc(node *&first) {

    //sprawdzamy czy lista jest pusta lub ma tylko jeden element
    if(first == nullptr || first -> next == nullptr)
        return;

    //pierwszego elementu nie musimy sprawdzac (nie bedziemy go nigdzie przenosic)

    //sprawdzenie wszystkich elementow (oprocz ostatniego)
    node *prev = first;
    node *p = first -> next;
    while( p -> next != nullptr) {
        if(zapis_osiemkowy(p -> value)) {
            prev -> next = p -> next;

            //przeniesienie na poczatek
            p -> next = first;
            first = p;

            p = prev -> next;
        } else {
            p = p -> next;
            prev = prev -> next;
        }
    }

    //sprawdzenie ostatniego elementu
    if(zapis_osiemkowy(p -> value)) {
        prev -> next = nullptr;
        p -> next = first;
        first = p;
    } else {
        return;
    }

}

int main() {
    node *first = new node;
    std::cin >> first -> value;
    first -> next = nullptr;
    node *p, *prev;
    prev = first;

    for(int i=0;i < N - 1; i++) {
        p = new node;
        std::cin >> p -> value;
        p -> next = nullptr;
        prev -> next = p;
        prev = p;
    }

    print_out_list(first);

    przeniesc(first);

    std::cout << "\n";
    print_out_list(first);



    return 0;
}