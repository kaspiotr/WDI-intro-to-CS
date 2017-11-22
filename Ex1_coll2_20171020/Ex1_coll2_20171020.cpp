//author: @kaspiotr (Piotr Kasprzyk)

/*
Dana jest tablica int tab[1000][1000] wypelniona liczbami naturalnymi
w taki sposob, ze w kazdym wierszu liczby te sa posortowane rosnaco.
Napisac funckje int max1000(int tab[1000][1000]), ktora dla tablicy
tab zwraca sume 1000 najmniejszych liczb znajdujacych sie w tej tablicy.

Czas na wykonanie zadania: 15 min
 */

/*
Rozwiazanie: tablica idxs[1000], ktora pod indeksem odpowiadajacym numerowi
 wiersza w tablicy tab przechwuje numer kolumny, w ktorej znajduje sie,
 w danym wierszu, najmniejszy element tego wiersza jeszcze nie dodany do
 sumy
 */

#include <iostream>

using namespace std;

int tab[1000][1000];

int max1000(int tab[1000][1000]){

    int *idxs = new int [1000];
    int sum = 0;

    for(int i=0; i<1000; i++) idxs[i]=0;

    int currMin, currMinRow; //currMin -wskazuje najmniejszy element tablicy tab[] wskazywany przez tablice idxs[]
                             //w danej iteracji
                             //currMinRow -wskazuje numer wiersza, w ktory znajduje sie element o wartosci currMin

    for(int i=0; i<1000; i++){ //1000 iteracji bo szukamy 1000 najmniejszych elementow tablicy tab[]
        currMin = tab[0][idxs[0]];
        currMinRow = 0;

        for(int j=1; j<1000; j++){
            if(currMin > tab[j][idxs[j]]){
                currMin = tab[j][idxs[j]];
                currMinRow = j;
            }
        }

        if(idxs[currMinRow] < 999){ //bo pole tablicy idxs moze miec maksymalnie wartosc 1000-1=999
            idxs[currMinRow]++;
        }
        sum+=currMin;
    }

    delete [] idxs;

    return sum;
}


int main(){
    //int tab[1000][1000]; <-tutaj nie mozna zadeklarowac tablicy, bo bedzie segmentation vault

    //inicjalizacja tablicy, ktora przetestuje poprawnosc funckji max1000
    int row, col;
    for(int i=0; i<1000000; i++){
        row = i/1000;
        col = i%1000;

        tab[row][col]=99;
    }

    tab[0][0]=99; tab[0][1]=99; tab[0][2]=99; tab[0][3]=99; tab[0][4]=99; tab[0][5]=99;
    tab[1][0]= 2; tab[1][1]=99; tab[1][2]=99; tab[1][3]=99; tab[1][4]=99; tab[1][5]=99;
    tab[2][0]= 3; tab[2][1]=99; tab[2][2]=99; tab[2][3]=99; tab[2][4]=99; tab[2][5]=99;
    tab[3][0]= 1; tab[3][1]= 2; tab[3][2]= 3; tab[3][3]=99; tab[3][4]=99; tab[3][5]=99;
    tab[4][0]= 2; tab[4][1]= 3; tab[4][2]=99; tab[4][3]=99; tab[4][4]=99; tab[4][5]=99;
    tab[5][0]=99; tab[5][1]=99; tab[5][2]=99; tab[5][3]=99; tab[5][4]=99; tab[5][5]=99;

    //Wynik jaki powinna zwrocic funckja max1000, to: 2+3+1+2+3+2+3+99*994 = 16 + 98307 = 98323

    cout<<max1000(tab)<<endl;

    return 0;
}