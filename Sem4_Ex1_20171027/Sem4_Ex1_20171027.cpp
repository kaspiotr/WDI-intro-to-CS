//author: kaspiotr (Piotr Kasprzyk)

/*
Zad.1, Cw.4, WDI, 27.10.17
Dana jest tablica int t[N] liczb naturalnych. Prosze napisac funkcje, ktora stwierdzi czy da sie dojsc
z pola tablicy t[] o indeksie 0 do pola tablicy t[] o indeksie n-1, jesli z pola t[i] o indeksie i mozemy skoczyc
na pole rowne czynnikowi pierwszemu liczby t[i] (gdzie i=0,...,N-1).
 */

#include <iostream>

using namespace std;

const int N = 10;

bool isPossible(int t[N]){
    bool jump[N];
    int val, div;

    for(int i=1; i<N; i++) jump[i]=false;
    jump[0]=true;

    for(int i=0; i<N; i++){
        if(jump[i]){
            val = t[i];
            div = 2;

            while(val > 1) {
                if (val % div == 0){
                    if (i + div < N) {
                        jump[i + div] = true;
                    }
                    val /= div;
                }
                else div++;
            }
        }
    }

    return jump[N-1];
}

int main(){

    int t1[N]={6,13,11,4,13,2,13,2,13,13}; //wynik: TAK
    int t2[N]={6,11,11,11,13,13,11,17,13,17}; //wynik: NIE

    if(isPossible(t1)) cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;

    return 0;
}

