#include <iostream>

int const N = 5;

struct node {
    int value;
    node *next;
};

bool zapis_trojkowy(int x) {
    int y = 0;
    int temp = x;
    while(temp > 0) {
        y = y*10 + temp%3;
        temp/=3;
    }

    int ilosc1 = 0;
    int ilosc2 = 0;
    while(y > 0) {
        if(y%10 == 1)
            ilosc1++;
        else if(y%10 == 2)
            ilosc2++;
        y/=10;
    }
    return(ilosc1 > ilosc2);
}

void print_out_list(node *p) {
    while(p!= nullptr) {
        std::cout << p -> value << " ";
        p = p-> next;
    }
}

void usuwac(node *&first) {
    //gdy lista jest pusta
    if(first == nullptr)
        return;
    //gdy lista zawiera tylko jeden element
    if(first -> next == nullptr) {
        if(zapis_trojkowy(first -> value)) {
            first = nullptr;
            return;
        } else
            return;
    }

    //sprawdzenie poczatku listy
    while(zapis_trojkowy(first -> value)) {
        first = first -> next;
    }

    //sprawdzenie czy cos jeszcze jest w liscie (po first czyli
    //czy istnieje first -> next)
    node *prev = first;
    node *p;
    if(first -> next != nullptr)
        p = first -> next;
    else
        return ;

    //sprawdzenie reszty (oprocz ostatniego)
    while(p -> next != nullptr) {
        if(zapis_trojkowy(p -> value)) {
            prev -> next = p -> next;
            p = p -> next;
        } else {
            p = p -> next;
            prev = prev -> next;
        }
    }

    //sprawdzenie ostatniego
    if(zapis_trojkowy(p -> value)) {
        prev -> next = nullptr;
        return;
    } else {
        return;
    }
}

int main() {
    node *first = nullptr;
    node *p;
    for(int i=0;i < N; i++) {
        p = new node;
        std::cin >> p -> value;
        p -> next = first;
        first = p;
    }

    print_out_list(first);

    usuwac(first);

    std::cout << "\n";

    print_out_list(first);


    return 0;
}