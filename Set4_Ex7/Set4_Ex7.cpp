//author: @kaspiotr (Piotr Kasprzyk)

/*
7. Dana jest tablica wypełniona liczbami naturalnymi:
int t[MAX][MAX];
Proszę napisać funkcję, która poszukuje w tablicy kwadratu o liczbie pól będącej liczbą nieparzystą
większą od 1, którego iloczyn 4 pól narożnych wynosi k. Do funkcji należy przekazać tablicę i wartość k.
Funkcja powinna zwrócić informacje czy udało się znaleźć kwadrat oraz współrzędne (wiersz, kolumna)
środka kwadratu.
MAX jest zdefiniowaną stałą.
*/

#include <iostream>

using namespace std;

const int MAX = 8;

bool isThereSquare(int t[MAX][MAX], int &row, int &col, int k, int &sideSize){
    int side = 3, product=0;

    while(side < MAX){

        for(int i=0; i<MAX-side+1; i++){

            for(int j=0; j<MAX-side+1; j++){
                product = t[i][j]*t[i][j+side-1]*t[i+side-1][j]*t[i+side-1][j+side-1];
                if(product == k){
                    row = i+side/2;
                    col = j+side/2;
                    sideSize = side;
                    return true;
                }
            }
        }

        side += 2;
    }

    return false;
}

int main(){

    //inicjalizacja tablicy testowej
    int tab[MAX][MAX];

    int row1, col1;
    for(int i=0; i<MAX*MAX; i++){
        row1 = i/MAX;
        col1 = i%MAX;

        tab[row1][col1]=1;
    }

    tab[2][3]=2;
    tab[2][7]=5;
    tab[6][3]=4;

    int k=40; //testowy iloczyn
    int row = 0, col = 0, sideSize = -1;

    cout<<isThereSquare(tab, row, col, k, sideSize)<<endl;
    cout<<"Row: "<<row<<endl;
    cout<<"Col: "<<col<<endl;
    cout<<"Size: "<<sideSize<<endl;


    return 0;
}