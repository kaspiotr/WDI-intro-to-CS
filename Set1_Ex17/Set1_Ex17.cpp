/*
17. Napisać program wyznaczający wartość liczby e korzystając z zależności:
e = 1/0! + 1/1! + 1/2! + 1/3! + ...
 */

#include <iostream>

using namespace std;

const int E = 10e-3; //dokladnosc

int main(){
    int i=1; //i-oznacza maksymalny czynnik mianownika rozpatrywanego w danej iteracji

    long long int denominator = 1; //mianownik -na poczatku rowny 0!=1; musi byc long long int, bo
                                   //inaczej dojdzie do przepelnienia


    double prevE = (double)1/denominator; //wartosc liczby e otrzymana w poprzedniej iteracji (tu denominator=0!=1)
    double e = prevE + (double)1/denominator; //szykana wartosc liczby e (tu denominator=1!=1)

    while(e-prevE < -E || e-prevE > E){
        prevE = e;
        i++;
        denominator *= i;
        e += (double)1/denominator;
    }

    cout<<e<<endl;

    return 0;
}