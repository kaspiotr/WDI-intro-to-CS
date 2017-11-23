//author: @kaspiotr (Piotr Kasprzyk)

/*
6. Dana jest tablica wypełniona liczbami naturalnymi:
int t[MAX][MAX];
Proszę napisać funkcję, która w poszukuje w tablicy najdłuższego ciągu geometrycznego
leżącego ukośnie w kierunku prawo-dół, liczącego co najmniej 3 elementy. Do funkcji
należy przekazać tablicę. Funkcja powinna zwrócić informacje czy udało się znaleźć
taki ciąg oraz długość tego ciągu.
MAX jest zdefiniowaną stałą.
*/

#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

const int MAX = 7;

//funckja pomocnicza, do inicjalizacji tablicy testowej
bool isPrime(int a){
    if(a < 1) return false;
    if(a%2 == 0){
        if(a == 2) return true;
        if(a != 2) return false;
    }

    int div = 3;
    int sqroot = sqrt((double)a);
    while(div < sqroot){
        if(a%div == 0){
            if(a == div) return true;
            else return false;
        }
        else div += 2;
    }

    return true;
}

//funkcja, ktora znajduje ciag geometryczny w podanej przekatnej
//x,y -wiersz i kolimna, w ktorej ma poczatek analizowana wlasnie przekatna
int findGeoSeqInDiag(int t[MAX][MAX], int y, int x){
    int maxLength = 0;
    int length = 2;

    int a1, a2, a3;

    while(y<MAX-2 && x<MAX-2){
        a1 = t[y][x];
        a2 = t[y+1][x+1];
        a3 = t[y+2][x+2];

        if(a2*a2 == a1*a3){
            length++;
        }
        else{
            if(maxLength < length) maxLength = length;
            length = 2;
        }

        y++;
        x++;
    }

    if(maxLength < length) return length;
    return maxLength;
}

int findLongestGeoSeq(int t[MAX][MAX]){
    int maxLength = 0;

    //przegladniecie przekatnych rozpoczynajacych sie w pierwszym wierszu tablicy t[][]
    for(int x=0; x<MAX-1; x++){
        int val = findGeoSeqInDiag(t, 0, x);
        if(maxLength < val) {
            maxLength = val;
        }
    }

    //przegladniecie przekatnych rozpoczynajacych sie w pierwszej kolumnie tablicy t[][]
    for(int y=1; y<MAX-1; y++){
        int val = findGeoSeqInDiag(t, y, 0);
        if(maxLength < val){
            maxLength = val;
        }
    }

    if(maxLength >= 3) return maxLength;
    return -1; //funckja zwraca -1 jesli nie istnieje ciag geometryczny o dlugosci co najmniej 3
}

int main(){

    //inicjalizacja tablicy testowej
    srand(time(NULL));

    int tab[MAX][MAX];
    int c;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            c = rand() % 100;
            while(!isPrime(c)) c = rand() % 100;
            tab[i][j] = c;
        }
    }

    tab[1][2] = 4; tab[2][3] = 8; tab[3][4] = 16; tab[4][5] = 32; tab[5][6] = 64;
    tab[4][4] = 16; tab[5][5] = 48; tab[6][6] = 144;

    cout<<findLongestGeoSeq(tab)<<endl;

    return 0;
}