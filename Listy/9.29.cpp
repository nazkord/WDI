#include <iostream>


int const N1 = 3;

struct node {
    std::string value;
    node *next;
};

void print_out_list(node *first) {
    node * p = first;
    do {
        std:: cout << p -> value << " ";
        p = p -> next;
    } while (p != first);
}

bool czy_poprzedza(std::string s1, std::string s2) {
    char c1 = s1[s1.length()-1];
    char c2 = s2[0];
    return ((int) c1 < c2);
}

bool wstawianie(node *&h, std::string napis) {
    //gdy jest pusta
    if(h == nullptr) {
        node * temp = new node;
        temp -> value = napis;
        temp ->next = nullptr;
        h = temp;
        return true;
    }

    node *p = h ->next;
    node *prev = h;
    bool flaga = false;

    //gdy posiada tylko jeden element
    if(p == prev) {
        if(czy_poprzedza(prev->value,napis) && czy_poprzedza(napis,p->value)) {
            node * temp = new node;
            temp ->value = napis;
            temp ->next = p;
            prev ->next = temp;
            h = temp;
            return true;
        }
    }

    while(p != h && !flaga) {
        if(czy_poprzedza(prev->value,napis) && czy_poprzedza(napis,p->value)) {
            node * temp = new node;
            temp ->value = napis;
            temp ->next = p;
            prev ->next = temp;
            h = temp;
            flaga = true;
        } else {
            p = p -> next;
            prev = prev -> next;
        }
    }
    return flaga;
}

int main() {

    //pierwsza lista
    node *first1 = nullptr;
    node *last = nullptr;
    node *p;
    for(int i = 0; i < N1; i++) {
        // 1 krok
        p = new node;
        std::cin >> p -> value;
        p -> next = first1;

        //2 krok
        if(first1 == nullptr)
            last = p;
        first1 = p;

    }

    last -> next = first1;

    print_out_list(first1);

    std::cout << "\n";

    bool flaga;
    std::string napis;
    std::cin >> napis;

    flaga = wstawianie(first1,napis);

    if(flaga) {
        print_out_list(first1);
    }

    return 0;
}