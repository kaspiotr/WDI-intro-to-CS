/*
18. Nieskończony iloczyn
sqrt(0.5)*sqrt(0.5+0.5*sqrt(0.5))*sqrt(0.5+0.5*sqrt(0.5+0.5*sqrt(0.5))) * ...
ma wartość 2/pi. Napisz program korzystający z tej zależności i wyznaczający wartość pi.
 */

/*
 * Na podstawie powyzszej zaleznosci mamy:
 *  1) pi = 2*sqrt(2)/(a(1)*sqrt(0.5 + 0.5*a(1))*...),
 *  gdzie a(1) = sqrt(0.5 + 0.5*sqrt(0.5))
 *
 *  a kazdy kolejny czynnik iloczynu obliczamy ze wzoru rekurencyjnego:
 *
 *  a(n) = sqrt(0.5 + 0.5*a(n-1))
 */

#include <iostream>
#include <math.h>

using namespace std;

const int E = 10e-3; //dokladnosc

int main(){

    double a1 = sqrt(0.5 + 0.5*sqrt(0.5));
    double a2 = sqrt(0.5 + 0.5*a1);

    double prevPi = 1/a1; //wartosc pi obliczona w poprzedniej iterazji
    double pi = 1/(a1*a2);

    while(pi-prevPi < -E || pi-prevPi > E){
        prevPi = pi;
        a1 = a2;
        a2 = sqrt(0.5 + 0.5*a1);
        pi /= a2;
    }

    pi *=2*sqrt(2); //bo 1)

    cout<<pi<<endl;

    return 0;
}