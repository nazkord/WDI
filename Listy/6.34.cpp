#include <iostream>
#include <cmath>

/* Proszę napisać funkcję, która jako parametr otrzymuje liczbę naturalną i zwraca
sumę iloczynów elementów wszystkich niepustych podzbiorów zbioru podzielników
pierwszych tej liczby. Można założyć, że liczba podzielników pierwszych nie
przekracza 20, zatem w pierwszym etapie funkcja powinna wpisać podzielniki do
tablicy pomocniczej. Przykład: 60 -> [2, 3, 5] -> 2 + 3 + 5 + 2*3 + 2*5 + 3*5 +
2*3*5 = 71 */

bool pierwsza(int x) {
    for(int i=2; i <= sqrt(x); i++) {
        if(x % i == 0)
            return false;
    }
    return (x!=1);
}

void suma(int t[20], int p, int limit, int product, int &sum) {
    /// t,0,4,0,sum
    if(p == limit) {
        if(product!=1) {
            sum += product;
        }

        return;
    }

    suma(t, p+1, limit, product*t[p],sum);
    suma(t, p+1, limit, product, sum);

}

int pomoc_suma(int x) {
    int t[20];
    int p = 0;
    for(int i =0; i < 20; i++)
        t[i] = 0;

    for(int i=2; i <= x/2; i++) {
        if(x % i == 0 && pierwsza(i)) {
            t[p] = i;
            p++;
        }
    }

    int sum = 0;
    suma(t,0,p,1,sum);

    return sum;
}

int main() {
    std::cout << pomoc_suma(60);


    return 0;
}