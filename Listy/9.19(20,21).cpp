#include <iostream>

int const N = 12;

struct node {
    node *next;
    int value;
};

void print_out_list(node *first) {
    int counter = 0;
    while(first != nullptr) {
        std::cout << first -> value << " ";
        first = first -> next;
        counter++;
        if(counter == 21)
            break;
    }
}

bool czyCykl(node *first) {
    //czy pusta
    if(first == nullptr)
        return false;

    node *szybki = first;
    node *wolny = first;
    bool flaga = false;

    while(!flaga) {
        if (szybki->next == nullptr) {
            flaga = false;
            break;
        } else {
            szybki = szybki->next->next;
            wolny = wolny->next;
            if(szybki == wolny)
                flaga = true;
        }
    }
    return flaga;
}

int dlugoscCykl(node *first) {

    node *szybki  = first;
    node *wolny = first;
    int length = 0;

    do {
        szybki = szybki -> next -> next;
        wolny = wolny -> next;
    } while (szybki != wolny);

    do {
        //szybki = szybki -> next -> next;
        wolny = wolny -> next;
        length++;
    } while (szybki != wolny);
    return length;
}

int elementsBeforeCycle(node *first) {

    node *szybki  = first;
    node *wolny = first;
    node *p = first;
    //szukana ilosc
    int length = 0;

    //szukamy spotkanie dwoch wskaznikow w cyklu
    do {
        szybki = szybki -> next -> next;
        wolny = wolny -> next;
    } while (szybki != wolny);

    //przechodzimy przez cykl i sprawdzamy czy p nie jest juz na poczatku cyklu
    for(;;) {
        do {
            wolny = wolny -> next;
            if(p == wolny)
                return length;
        } while(szybki != wolny);
        p = p -> next;
        length++;
    }
}

int main()
{
    node *first = new node;
    first -> value = 1;
    first -> next = nullptr;

    node *last = first;

    node *p;
    node *cykl;

    for(int i = 1; i < N; i++) {
        // 1 krok
        p = new node;
        p -> value = i + 1;
        p -> next = nullptr;

        //2 krok
        last -> next = p;
        last = last -> next;

        if(i==10)
            cykl = p;
    }

    last -> next = cykl;

    print_out_list(first);

    if(czyCykl(first)) {
        std::cout<<"\n"<<"TAK TAK TAAAAAK";
        std::cout<<"\n"<<"Jego dlugosc wynosi: " << dlugoscCykl(first);
        std::cout<<"\n"<<"Ilosc elementow przed cyklem wynosi: " << elementsBeforeCycle(first);
    } else {
        std::cout<<"JESTES PRZEGRYWEM";
    }

    return 0;
}