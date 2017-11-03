//author: @kaspiotr (Piotr Kasprzyk)

/*
1.Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na
pytanie, czy liczba ta jest iloczynem dowolnych dwóch kolejnych wyrazów
ciągu Fibonacciego.
 */

#include <iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    int P1=1, P2=1, P3;
    int K1=1, K2=1, K3;

    int product = P1*P2;

    while(product < n){

        product/=P1;
        P3 = P1 + P2;
        P1 = P2;
        P2 = P3;
        product*=P2;

        //cout<<product<<endl;
    }

    if(product == n) cout<<"Podana liczba jest iloczynem dwoch kolejnych wyrazow ciagu Fibonacci'ego"<<endl;
    else cout<<"Podana liczba nie jest iloczynem dwoch kolejnych wyrazow ciagu Fibonacci'ego"<<endl;



    return 0;
}

