/*
13. Napisać program wyznaczający wartość do której zmierza iloraz dwóch kolejnych wyrazów
ciągu Fibonacciego. Wyznaczyć ten iloraz dla różnych wartości początkowych wyrazów
ciągu.
*/

#include <iostream>

using namespace std;

const double E=10e-3;

int main(){
    int F1=1, F2=1, F3; //tu podstawiamy inne wartosci poczatkowe F1 i F2 i badamy uzyskany iloraz
    double quotient1 = (double)F2/F1;

    F3 = F1+F2;
    F1 = F2;
    F2 = F3;

    double quotient2 = (double)F2/F1;

    while(quotient1 - quotient2 < -E || quotient1 - quotient2 > E){
        F3 = F1+F2;
        F1 = F2;
        F2 = F3;
        quotient1 = (double)F2/F1;

        F3 = F1+F2;
        F1 = F2;
        F2 = F3;
        quotient2 = (double)F2/F1;
    }

    cout<<quotient2<<endl;

    return 0;
}