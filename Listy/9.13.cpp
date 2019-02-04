#include <iostream>

using namespace std;

int const N = 5;

struct node {
    node *next;
    node *prev;
    int value;
};

void print_out_list(node *first) {
    node *p = first;
    while(p != NULL) {
        cout<<p -> value << " ";
        p = p -> next;
    }
}

int jedynki(int x) {
    int counter = 0;
    int temp = x;
    while(temp > 0) {
        if(temp%2 == 1)
            counter++;
        temp/=2;
    }
    if(counter%2 == 1)
        return true;
    else
        return false;

}

void usuwac(node *&first) {

    //sprawdzenie czy lista nie jest pusta
    if(first == NULL)
        return;

    //wykonanie petli dla sytuacji w ktorej 1 element spelnia warunki zadania
    while(jedynki(first ->value)) {
        first = first -> next;
        first -> prev = NULL;
    }

    //sprawdzenie czy cos jeszcze jest w liscie
    node *prev = first;
    node *p;
    if(first -> next != NULL) {
        p = first -> next;
    } else {
        return;
    }

    //sprawdzenie reszty elementow
    while(p -> next != NULL) {
        if(jedynki(p -> value)) {
            p -> prev = NULL;
            prev -> next = p -> next;
            p -> next = NULL;
            p = prev -> next;
        } else {
            p = p -> next;
            prev = prev -> next;
        }
    }

    //sprawdzenie ostatniego
    if(jedynki(p -> value)) {
        p -> prev = NULL;
        p -> next = NULL;
        prev -> next = NULL;
    }

    return;
}

int main()
{
    //tworzenie pierwsze elementu
    node *first = NULL;
    node *p;

    for(int i = 0; i < N; i++) {
        //1 krok
        p = new node;
        cin >> p ->value;
        p -> next = first;
        p -> prev = NULL;

        //2 krok
        first = p;
    }

    print_out_list(first);

    usuwac(first);

    cout<<"\n";

    print_out_list(first);



    return 0;
}
