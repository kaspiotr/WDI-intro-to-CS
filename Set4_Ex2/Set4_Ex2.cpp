//author: @kaspiotr (Piotr Kasprzyk)

/*
2. Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi.
Proszę napisać funkcję który odpowiada na pytanie, czy w każdym wierszu tablicy
występuje co najmniej jedna liczba złożona wyłącznie z nieparzystych cyfr.
MAX jest zdefiniowaną stałą.
 */

#include <iostream>

using namespace std;

const int MAX = 4;

//funckja, ktora sprawdza czy wszystkie cyfry podanej liczby sa nieparzyste (tak -zwraca true, nie -zwraca false)
bool areAllDigsOdd(int a){

    int digit;
    while(a != 0){
        digit = a%10;
        if(digit%2 == 0) return false;
        a/=10;
    }

    return true;
}

//funckja, ktora sprawdza czy w kazdym wierszu danej tablicy 2D znajduje sie conajmniej jedna liczba, ktorej wszystkie
//cyfry sa liczbami nieparzystymi
bool isInEveryRowSuchANumber(int t[MAX][MAX]){

    for(int row=0; row<MAX; row++){
        for(int col=0; col<MAX; col++){
            if(areAllDigsOdd(t[row][col])) break;
            if(col == MAX-1 && (!areAllDigsOdd(t[row][col]))) return false;
        }
    }

    return true;
}


int main(){

    //przykladowe tablice: dla t1 -powinnismy otrzymac true, a dla t2 -false
    int t1[MAX][MAX];
    int t2[MAX][MAX];

    int row, col;

    for(int i=0; i<MAX*MAX; i++){
        row = i/MAX;
        col = i%MAX;

        t1[row][col]= 2;
        t2[row][col]= 2;
    }

    t1[0][3]=13;
    t1[1][1]=15;
    t1[2][0]=17;
    t1[3][2]=9;

    cout<<isInEveryRowSuchANumber(t1)<<endl;
    cout<<isInEveryRowSuchANumber(t2)<<endl;


    return 0;
}
