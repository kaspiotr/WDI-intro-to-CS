//author: @kaspiotr (Piotr Kasprzyk)

/*
1. Mamy tablicę [1..max,1..max]. Napisz funkcję, która zwraca długość najdłuższego podciągu rosnącego
znajdującego się w dowolnym (jednym) wierszu, którego wszystkie elementy są ze sobą względnie
pierwsze.
 */

//jesli liczby sa wzglednie pierwsze to ich NWW jest rowna ich iloczynowi.
#include <iostream>

using namespace std;

const int N = 4;

int nwd(int a, int b){
    while(a*b != 0){
        if(a>b) a%=b;
        else b%=a;
    }

    if(a != 0) return a;
    else return b;
}

//rowNo -po wywolaniu funkcji bedzie przechowywac nr wiersza, w ktorym znajduje sie najdluzszy szykany podciag
//el -po wywolanu funkcji bedzie przechowywac wartosc ostatniego elementu znalezionego najdluzszego ciagu
int longestRiseSubseqOfCoPrimes(int t[N][N], int &rowNo, int &el){
    int row, col, prev, j, row2, col2, curr, prevNWD, len=0, maxLen=0, k;

    for(int i=0; i<N*N-1; i++){
        len = 1;
        row = i/N;
        col = i%N;
        prev = t[row][col];

        j = i+1;
        row2 = j/N;
        col2 = j%N;
        curr = t[row2][col2];

        prevNWD = nwd(prev, curr);

        k=i;
        len=0;
        while(j<N*N && row2==row && prev<curr){
            k++; j++;
            row = k/N; col = k%N; row2 = j/N; col2 = j%N;

            prev = t[row][col];
            curr = t[row2][col2];

            prevNWD = nwd(prevNWD, curr);

            len++;
            if((j==N*N && prevNWD!=1) || (row2!=row && prevNWD!=1)) len=0;
        }

        if(maxLen < len){
            maxLen = len;
            rowNo = row2;
            el = prev;
        }
    }

    return maxLen;
}

int main(){

    int tab[N][N] = {{20,20, 6,35},
                     { 9, 6, 4,20},
                     {20,10,12,15},
                     {20,20,20,20}};

    int rowNo = 0;
    int el = 0;

    cout<<longestRiseSubseqOfCoPrimes(tab, rowNo, el)<<endl;
    cout<<rowNo<<endl;
    cout<<el<<endl;

    return 0;
}



