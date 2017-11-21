//author: @kaspiotr (Piotr Kasprzyk)

/*
1. Dana jest tablica int t[MAX][MAX]. Proszę napisad funkcję wypełniającą tablicę liczbami naturalnymi po spirali.
MAX jest zdefiniowaną stałą.
*/

#include <iostream>

using namespace std;

const int MAX = 7;

//funkcja pomocnicza, ktora wyswietla tablice
void print2DTab(int t[MAX][MAX]){

    int row, col;
    for(int i=0; i<MAX*MAX; i++){
        row = i/MAX;
        col = i%MAX;

        cout<<t[row][col]<<"\t";
        if(col == MAX-1) cout<<endl;
    }
}

void spiral(int t[MAX][MAX]){

    int b=0, e=MAX-1, j=1; //b-begin, e-end

    while(b<=e){

        for(int i=b; i<=e; i++) t[b][i]=j++;

        for(int i=b+1; i<=e; i++) t[i][e]=j++;

        for(int i=e-1; i>=b; i--) t[e][i]=j++;

        for(int i=e-1; i>b; i--) t[i][b]=j++;

        b++;
        e--;
    }
}

int main(){

    int tab[MAX][MAX];

    spiral(tab);

    print2DTab(tab);

    return 0;
}



