//author: @kaspiotr (Piotr Kasprzyk)

/*
9. Dwie liczby naturalne są „przyjaciółkami jeżeli zbiory cyfr z których zbudowane są liczby są identyczne. Na
przykład: 123 i 321, 211 i 122, 35 i 3553. Dana jest tablica
int t[MAX][MAX]
wypełniona liczbami naturalnymi. Proszę napisać funkcję, która dla tablicy t zwraca ile elementów tablicy sąsiaduje
wyłącznie z przyjaciółkami.
MAX jest zdefiniowaną stałą.
*/

#include <iostream>

using namespace std;

const int MAX = 5;

bool isTheSameSetOfDig(int a, int b){

    bool *digs = new bool [10];
    for(int i=0; i<10; i++) digs[i]=false;

    while(a != 0){
        digs[a%10]=true;
        a/=10;
    }

    while(b != 0){
        if(!digs[b%10]) return false;
        b/=10;
    }

    delete [] digs;
    return true;
}

bool areAllNeighboursFriends(int t[MAX][MAX], int row, int col){
    int dy[]={-1,-1,-1, 0, 1, 1, 1, 0};
    int dx[]={-1, 0, 1, 1, 1, 0,-1,-1};

    int row2, col2;

    for(int i=0; i<8; i++){
        row2 = row + dy[i];
        col2 = col + dx[i];

        if(row2>=0 && row2<MAX && col2>=0 && col2<MAX){
            if(!isTheSameSetOfDig(t[row][col],t[row2][col2])) return false;
        }
    }

    return true;
}

int noOfOnlyFriendNeighbours(int t[MAX][MAX]){
    int row, col, counter=0;
    for(int i=0; i<MAX*MAX; i++){
        row = i/MAX;
        col = i%MAX;

        if(areAllNeighboursFriends(t,row,col)) counter++;
    }

    return counter;
}

int main(){

    int tab[MAX][MAX];

    int row, col;

    int j=1;
    for(int i=0; i<MAX*MAX; i++){
        row = i/MAX;
        col = i%MAX;

        tab[row][col]=j++;
    }

    tab[0][0] = 123; //sasiad
    tab[0][1] = 112233; //sasiad
    tab[0][2] = 123123; //sasiad
    tab[1][0] = 1223; //sasiad
    tab[1][1] = 321; //element
    tab[1][2] = 3312; //sasiad
    tab[2][0] = 123; //sasiad
    tab[2][1] = 321321; //sasiad
    tab[2][2] = 12123; //sasiad

    cout<<noOfOnlyFriendNeighbours(tab)<<endl;

    return 0;
}

