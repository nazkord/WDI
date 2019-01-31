#include <iostream>

/* Dana jest tablica int t[N] zawierająca liczby naturalne. Proszę napisać funkcję,
która odpowiada na pytanie, czy spośród (niekoniecznie wszystkich) elementów
tablicy można utworzyć dwa podzbiory o jednakowej sumie elementów, tak aby suma
mocy obu podzbiorów wynosiła k. Do funkcji należy przekazać wyłącznie tablicę t
oraz liczbę naturalną k, funkcja powinna zwrócić wartość typu bool. */

int const N = 10;

void podzbiory(int t[N], int p, int sum1, int sum2, int moc1, int moc2,
        int k, bool &result) { /// example: t,0,0,0,0,0,56,false

    /// final condition
    if(result || p == N)
        return;
    if(sum1 == sum2 && moc1 + moc2 == k)
        result = true;

    podzbiory(t, p+1, sum1 + t[p], sum2, moc1 + 1, moc2, k, result);
    podzbiory(t, p+1, sum1, sum2 + t[p], moc1, moc2 + 1, k, result);
    podzbiory(t, p+1, sum1, sum2, moc1, moc2, k, result);

}

bool opak_zbiory(int t[N], int k) {
    bool mainResult = false;
    podzbiory(t,0,0,0,0,0,k,mainResult);
    return mainResult;
}

int main() {
    int t[N];
    for(int i = 0; i < N; i++) {
        std::cin >> t[i];
    }

    std::cout << "Wpisz liczbe k: ";
    int k;
    std::cin >> k;

    if(opak_zbiory(t,k))
        std::cout << "TAKTAKTAK";
    else
        std::cout << "NIENIENIE";

    return 0;
}