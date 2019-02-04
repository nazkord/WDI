#include <iostream>

/* Proszę napisać funkcję, która rozdziela listę na dwie listy. Pierwsza
powinna zawierać klucze parzyste dodatnie, drugi klucze nieparzyste ujemne,
pozostałe elementy należy usunąć z pamięci. Do funkcji należy przekazać
wskaźniki na listę z danymi oraz wskaźniki na listy wynikowe. Funkcja
powinna zwrócić liczbę usuniętych elementów. */

int const N1 = 10;

int const N2 = 6;

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

int rozlacz(node *&h, node *&first1) {
    if(h == nullptr) return 0;
    node *p = h;
    //wartownik
    node *w = new node;
    w -> next = h;
    node *prev = w;
    int counter = 0;

    while(p != nullptr) {
        int x = p -> value;
        if((x > 0) && (x % 2 == 0 )) {
            //usuwanie zlego elementu z listy glownej
            p = p -> next;
            prev = prev -> next;

        } else if((x < 0) && (x % 2 == (-1))) {
            //tworzenie i wstawianie nowego elementu na poczatek 1 listy

            node *temp = new node;
            temp -> value = x;
            temp -> next = first1;
            first1 = temp;

            //usuwanie tego elementu z listy glownej
            if(p == h) {
                p = p->next;
                prev -> next = p;
                h = p;
            } else {
                p = p->next;
                prev->next = p;
            }

        } else {
            //usuwanie zlego elementu z listy glownej
            if(p == h) {
                p = p->next;
                prev -> next = p;
                h = p;
            } else {
                p = p->next;
                prev->next = p;
            }
            counter++;
        }
    }

    return counter;
}


int main() {

    //pierwsza lista
    node *h = nullptr;
    node *p;
    for(int i = 0; i < N1; i++) {
        // 1 krok
        p = new node;
        std::cin >> p -> value;
        p -> next = h;

        //2 krok
        h = p;
    }

    /*  //druga lista
    node *first2 = nullptr;
    for(int i = 0; i < N2; i++) {
        // 1 krok
        p = new node;
        std::cin >> p -> value;
        p -> next = first2;

        //2 krok
        first2 = p;
    } */

    node *first1 = nullptr;

    print_out_list(h);

    std::cout << "\n";

    int y = rozlacz(h,first1);

    std::cout << "Usunieto: " << y << "\n";

    print_out_list(h);

    std::cout << "\n";

    print_out_list(first1);

    std::cout << "\n";

    return 0;
}