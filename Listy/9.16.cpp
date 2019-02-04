#include <iostream>

// odwrocic liste

int const N1 = 9;

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

int usun(node *&f) {
    node * w = new node;
    w -> next = f;
    node * p = f;
    node * prev = w;

    int counter = 0;

    while(p != nullptr) {
        while(p -> next != nullptr && p -> value == p -> next -> value) {
            //usuwamy wtedy element
            if(p == f) {
                prev -> next = p -> next;
                p = p -> next;
                f = p;
            } else {
                prev -> next = p -> next;
                p = p -> next;
            }
            counter ++;
        }
        p = p -> next;
        prev = prev -> next;
    }
    return  counter;
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

    print_out_list(first1);

    std::cout << "\n";

    int x = usun(first1);

    std::cout << "Usunieto " << x << "\n";

    print_out_list(first1);

    std::cout << "\n";

    return 0;
}