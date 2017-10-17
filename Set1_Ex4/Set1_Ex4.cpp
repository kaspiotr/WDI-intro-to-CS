/*
4. Napisać program sprawdzający czy istnieje podciąg ciągu Fibonacciego o sumie równej
numerowi bieżącego roku. (przenieść dalej)
*/

#include <iostream>

using namespace std;

const int N = 2017;

int main(){
    //int N;
    //cin>>N;
    int P1=1, P2=1, P3; //P1 -wyznacza poczatek aktualnej sumy wyrazow
    int K1=1, K2=1, K3; //K1 -wyznacza koniec aktualnej sumy wyrazow
    int sum = 0;

    while(sum!=N && K1<=N){
        if(sum > N){
            sum -=P1;
            P3 = P1 + P2;
            P1 = P2;
            P2 = P3;
        }

        if(sum < N){
            sum +=K1;
            K3 = K1+K2;
            K1 = K2;
            K2 = K3;
        }
    }

    if(sum == N){
        cout<<"TAK"<<endl;
    }
    else{
        cout<<"NIE"<<endl;
    }

    return 0;
}