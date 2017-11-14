//author: @kaspiotr (Piotr Kasprzyk)

/*
1.Dana jest tablica int t[N][N] zawierająca liczby naturalne. Dokładnie w jednym wierszu, bądź kolumnie znajduje się
fragmentu ciągu arytmetycznego o długości większej niż 2, którego elementy są liczbami pierwszymi. Proszę napisać
funkcję która zwróci długość tego ciągu.
*/

#include <iostream>
#include <math.h>

using namespace std;

const int N = 4;

bool isPrime(int a) {
    if (a < 2) return false;
    if (a % 2 == 0) {
        if (a == 2) return true;
        else return false;
    }
    int div = 3;
    while (div <= sqrt(a)) {
        if (a % div == 0) {
            if (a == div) return true;
            else return false;
        } else div += 2;
    }

    return true;
}

void print2DTable(int tab[N][N]) {
    int row, col;
    for (int i = 0; i < N * N; i++) {
        row = i / N;
        col = i % N;

        if (col % N == 0) cout << endl;
        cout << tab[row][col] << "\t";
    }
    cout << endl;

}


int longestPrimeArythSeq(int t[N][N], int &resRow, int &resCol) {

    int row, col, row2, col2, a1, a2, diff;
    int maxLen = 2, len;

    for(int i=0; i<N*N-2; i++){
        if(i==(N*(N-1)-2) || i==(N*(N-1)-1)) continue;
        row = i/N; col= i%N;
        a1 = t[row][col];

        if(isPrime(a1)){
            //sprawdzamy wiersz
            if(col < N-2){
                row2 = row; col2 = col+1;
                a2 = t[row2][col2];
                diff = a2 -a1;
                len = 2;

                while(col2<N && diff==(a2-a1) && isPrime(a2)){
                    a2 = t[row2][col2++];
                    len++;
                    diff*=2;
                }

                if(maxLen < len){
                    maxLen = len;
                    resRow = row;
                    resCol = col;
                }

            }

            //sprawdzamy kolumne
            if(row < N-2){
                row2 = row+1; col2 = col;
                a2 = t[row2][col2];
                diff = a2-a1;
                len = 2;

                while(row2<N && diff==(a2-a1) && isPrime(a2)){
                    a2 = t[row2][col2++];
                    len++;
                    diff*=2;
                }

                if(maxLen < len){
                    maxLen = len;
                    resRow = row;
                    resCol = col;
                }
            }
        }
    }

    return maxLen;
}


int main() {

    int t1[N][N];
    int t2[N][N];
    //inicjalizacja tablicy t1 i t2
    int row, col;
    for(int i=0; i<N*N; i++){
        row = i/N; col=i%N;
        t1[row][col] = 8;
        t2[row][col] = 8;
    }

    t1[2][0] = 2; t1[2][1] = 3; t1[2][2] = 5;
    t1[3][0] = 2; t1[3][1] = 3; t1[3][2] = 7; t1[3][3] = 5;

    t2[0][2] = 2; t2[0][3] = 2;
    t2[1][2] = 3; t2[1][3] = 3;
    t2[2][2] = 5; t2[2][3] = 7;
                  t2[3][3] = 5;

    int resRow=0, resCol=0;

    print2DTable(t1);
    cout<<endl;
    cout<<"Length of sequence = "<<longestPrimeArythSeq(t1, resRow, resCol)<<endl;
    cout<<"Row of a1 = "<<resRow<<endl;
    cout<<"Col of a1 = "<<resCol<<endl;

    print2DTable(t2);
    cout<<endl;
    cout<<"Length of sequence = "<<longestPrimeArythSeq(t2, resRow, resCol)<<endl;
    cout<<"Row of a1 = "<<resRow<<endl;
    cout<<"Col of a1 = "<<resCol<<endl;

    return 0;
}