//author: @kaspiotr (Piotr Kasprzyk)

/*
3. Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisać funkcję który odpowiada na pytanie,
czy istnieje wiersz w tablicy w którym każda z liczb zawiera przynajmniej jedna cyfrę parzystą.
MAX jest zdefiniowaną stałą.
*/

#include <iostream>

using namespace std;

const int MAX = 4;

//funkcja, ktora odpowiada na pytanie czy dana liczba zawiera przynajmniej jedna cyfre parzysta
bool isAtLeastOneDigEven(int a){

    int digit;
    while(a != 0){
        digit = a%10;
        if(digit%2 == 0) return true;
        a/=10;
    }

    return false;
}

//funckja, ktora sprawdza, czy w tablicy istnieje wiersz, w ktorym kazda liczba zawiera przynajmniej jedna cyfe parzysta
bool isThereARow(int t[MAX][MAX]){

    int rowCounter = 0;
    for(int row=0; row<MAX; row++){

        rowCounter=0;
        for(int col=0; col<MAX; col++){
            if(isAtLeastOneDigEven(t[row][col])) rowCounter++;
        }

        if(rowCounter == MAX) return true;
    }

    return false;
}


int main(){

    //przykladowa tablica, dla ktorej funckja powinna zwrocic wartosc true
    int t1[][MAX]={{13, 15, 17, 33},
                   {11, 15, 74, 99},
                   {74, 96, 36, 46},
                   {31, 13, 31, 13}};

    //przykladowa tablice, dla ktorej funckja powinna zwrocic wartosc false
    int t2[][MAX]={{13, 15, 17, 33},
                   {11, 14, 77, 99},
                   {79, 47, 34, 45},
                   {31, 13, 31, 13}};

    cout<<isThereARow(t1)<<endl;
    cout<<isThereARow(t2)<<endl;

    return 0;
}

