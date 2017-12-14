//author: @kaspiotr (Piotr Kasprzyk)

/*
19. Tablica int t[8][8] zawiera liczby naturalne. Proszę napisad funkcję, która sprawdza czy można wybrać z tablicy
niepusty podzbiór o zadanej sumie. Warunkiem dodatkowym jest aby żadne dwa wybrane elementy nie leżały w tej samej
kolumnie ani wierszu. Do funkcji należy przekazać wyłącznie tablicę  oraz wartośd sumy, funkcja powinna zwrócić
wartość typu bool.
*/

#include <iostream>

using namespace std;

const int N=4;

//wlasciwa funckja rekurencyjna
bool isThereSetRec(int t[N][N], int sum, bool rows[N], bool cols[N], int &currSum){
    if(currSum == sum) return true;

    int row, col; bool result;
    for(int i=0; i<N*N; i++){
        row = i/N;
        col = i%N;

        if(!rows[row] && !cols[col]){
            rows[row]=true; cols[col]=true;
            currSum += t[row][col];
            result = isThereSetRec(t, sum, rows, cols, currSum);
            if(result) return true;
            rows[row] = false; cols[col]=false;
            currSum -= t[row][col];
        }
    }

    return false;
}

bool isThereSet(int t[N][N], int sum){
    bool rows[N], cols[N];

    for(int i=0; i<N; i++){
        rows[i]=false;
        cols[i]=false;
    }

    int row, col;
    bool result; //zmienna dla przejrzystosci
    int currSum = 0;

    for(int i=0; i<N*N; i++){
        row = i/N;
        col = i%N;
        rows[row]=true; cols[col]=true; //zajmujemy wiersz i kolumne wstawiajac element
        currSum += t[row][col];
        result = isThereSetRec(t, sum, rows, cols, currSum);
        if(result) return true;
        rows[row]=false; cols[col]=false; //w razie niepowodzenia cofamy wprowadzone wczesniej zmiany
        currSum -= t[row][col];
    }

    return false;
}

int main(){

    int sum = 110;

    int tab1[][N]={{ 1, 1, 1, 1},
                   { 1,45, 1, 1},
                   { 1, 1,65, 1},
                   { 1, 1, 1, 1}};


    int tab2[][N]={{ 1, 1, 1, 1},
                   { 1, 1, 1, 1},
                   { 1, 1, 1, 1},
                   { 1, 1, 1, 1}};
    cout<<isThereSet(tab1, sum)<<endl;
    cout<<isThereSet(tab2, sum)<<endl;

    return 0;
}

