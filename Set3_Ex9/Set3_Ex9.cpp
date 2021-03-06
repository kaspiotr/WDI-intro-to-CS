//author: @kaspiotr (Piotr Kasprzyk)

/*9. Dana jest tablica int t[N] zawierająca liczby naturalne.
W tablicy możemy przeskoczyć z pola o
indeksie k o n pól w prawo  jeżeli wartość n jest czynnikiem pierwszym liczby t[k]. Napisać
funkcję sprawdzającą czy jest możliwe przejście z pola 0 na pole N-1.*/

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
