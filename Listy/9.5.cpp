#include <iostream>

/*5. Liczby naturalne reprezentowane jak poprzednim zadaniu(kazda cyfra to
osobny element listy). Proszę napisać funkcję dodającą dwie takie liczby.
W wyniku dodawania dwóch liczb powinna powstać nowa lista.  */

struct node {
    int value;
    node *next, *prev;
};

//wartownik
struct wart {
    //ilosc elementow w liscie
    int count;
    node *head, *tail;
};

void print_out_list(wart *wartownik) {
    node *p = wartownik -> head;
    while(p!= nullptr) {
        std::cout<< p -> value;
        p = p -> next;
    }
}

void tworzenie_liczby(int dl, wart *&wartownik) {
    std::cout<<"WPISZ PO KOLEI CYFRY TEJ LICZBY: ";

    //wskaznik na poczatek pierwszej listy i pierwszy element
    node *first = new node;
    first -> next = nullptr;
    first -> prev = nullptr;
    std::cin>>first -> value;

    //deklaracja wartonwika
    wartownik -> head = first;
    wartownik -> count = 1;

    node *p, *prevq;
    prevq = first;
    //wypelniamy liste dodajac do konca
    for(int i = 0; i < dl - 1; i++) {
        //tworzymy nowy element
        p = new node;
        std::cin >> p -> value;
        p -> next = nullptr;
        p -> prev = prevq;

        //laczymy poprzedni (ostatni) element listy z nowym p
        prevq -> next = p;
        prevq = p;

        //uzupelniamy wartownik
        wartownik -> tail = p;
        wartownik -> count ++;

    }
}

int main() {
    int dl1,dl2;
    std::cout<<"WPISZ DLUGOSC PIERWSZEJ LICZBY: ";
    std::cin>>dl1;
    std::cout<<"WPISZ DLUGOSC DRUGIEJ LICZBY: ";
    std::cin>>dl2;

    //tworzymy wartonwik dla pierwszej listy (liczby)
    wart *wartownik1 = new wart;
    tworzenie_liczby(dl1,wartownik1);

    //tworzymy wartonwik dla drugiej listy (liczby)
    wart *wartownik2 = new wart;
    tworzenie_liczby(dl2,wartownik2);

    //tworzenie nowej listy (liczby)
    wart *wartownik3 = new wart;

    node *first = nullptr;

    //deklaracja wartonwika
    wartownik3 -> head = first;
    wartownik3 -> count = 0;


    node *p,*q,*r,*prevr;
    p = wartownik1->tail;
    q = wartownik2->tail;
    //pierwsze wykonanie petli
    //1 krok
    r = new node;
    r -> next = nullptr;
    r -> prev = nullptr;
    r -> value = p -> value + q -> value;
    //2 krok
    p = p -> prev;
    q = q -> prev;
    //3 krok
    wartownik3 -> tail = r;
    wartownik3 -> count ++;

    //glowna petla programu
    while((p != nullptr) && (q != nullptr)) {
        //tworzymy nowy element
        prevr = new node;
        prevr -> prev = nullptr;
        prevr -> next = r;
        prevr -> value = p -> value + q -> value;

        if(r -> value > 9) {
            prevr -> value ++;
            r -> value %= 10;
        }

        //2 krok
        r = prevr;
        p = p -> prev;
        q = q -> prev;

        //uzupelniamy wartownik
        wartownik3 -> head = r;
        wartownik3 -> count ++;

    }

    if(p == nullptr) {
        while(q != nullptr) {
            //1 krok
            prevr = new node;
            prevr -> value = q -> value;
            prevr -> next = wartownik3 -> head;
            prevr -> prev = nullptr;

            if(r -> value > 9) {
                prevr -> value ++;
                r -> value %= 10;
            }

            //2 krok
            q = q -> prev;

            //3 krok
            wartownik3 -> head = prevr;
            wartownik3 -> count ++;
        }
    } else {
        while(p != nullptr) {
            //1 krok
            prevr = new node;
            prevr -> value = p -> value;
            std::cout<<p->value<<" ";
            prevr -> next = r;
            prevr -> prev = nullptr;

            if(r -> value > 9) {
                prevr -> value ++;
                r -> value %= 10;
            }

            //2 krok
            p = p -> prev;

            //3 krok
            wartownik3 -> head = prevr;
            wartownik3 -> count ++;
        }
    }


    std::cout << "WYNIK DODAWANIA: ";
    print_out_list(wartownik1);
    std::cout << " + ";
    print_out_list(wartownik2);
    std::cout << " = ";
    print_out_list(wartownik3);


    return 0;
}