//author: @kaspiotr (Piotr Kasprzyk)

/*
2. Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy liczba ta jest iloczynem
dowolnych dwóch wyrazów ciągu Fibonacciego.
*/

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int P1=1, P2=1, P3; //P1 -mniejszy czynnik
    int K1=1, K2=2, K3; //K1 -wiekszy czynnik

    int product = P1*K1;

    //przesuwamy K1 maksymalnie do przodu
    while(n < product && K1<n){
        product /= K1;
        K3 = K1+K2;
        K1 = K2;
        K2 = K3;
        product *= K1;
    }


    if(n == product) cout<<"Liczba jest iloczynem dowolnych dwoch wyrazow ciagu Fibonacci'ego"<<endl;

    //cofamy K1 i przesuwamy w przod P1
    while(n != product && P1 < K1){
        if(n > product){
            product /= K1;
            K3 = K2;
            K2 = K1;
            K1 = K3 - K2;
            product *= K1;
        }

        if(n < product) {
            product /= P1;
            P3 = P1 + P2;
            P1 = P2;
            P2 = P3;
            product *= P1;
        }
    }

    if(n == product) cout<<"Liczba jest iloczynem dowolnych dwoch wyrazow ciagu Fibonacci'ego"<<endl;
    else cout<<"Liczba nie jest iloczynem dowolnych dwoch wyrazow ciagu Fibonacci'ego"<<endl;

    return 0;
}
