/*
 Autor: @thoren (Tomasz Makowski)
*/
#include <iostream>
using namespace std;
int main() {
    const int N=1000000; //ilość przeszukiwanych liczb
    for (int i=1; i<N; i++) {
        int suma=1; //suma dzielnikow liczby
        //zaczynamy od sumy=1 bo każda rozważana liczba jest podzielna przed 1
        for (int k=2; (k*k)<i; k++) { //przeszukiwanie tylko do √i (najszybciej)
            //zaczynamy od k=2 bo dla k=1 dodamy 1 oraz "i", a dodajemy tylko dzielniki właściwe
            if ((i%k==0)) {
                suma+=(k+i/k);
            }
        }
        if ((suma)==i) { //warunek liczby doskonałej
            cout << "Liczba " << i << " jest doskonala" << endl;
        }
    }
    return 0;
}