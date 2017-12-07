//author: @kaspiotr (Piotr Kasprzyk)

/*
2.Dana jest tablica booli int t[N][N] reprezentująca szachownicę. Pole szachownicy ma wartość true, jeżeli stoi na nim
figura, a false, jeśli jest ono puste. Proszę napisać funkcję która sprawdza czy istnieje droga skoczka
przemieszczającego się z wiersza 0 do wiersza N-1. Skoczek może poruszać się tylko po polach pustych. Skoczek w każdym
ruchu powinien przybliżać się do N-1 wiersza. Funkcja ma zwrócić najmniejszą możliwą liczbę ruchów. Skoczek może zacząć
poruszać się z dowolnego pustego pola z wiersza 0. N z zakresu 4...20.
*/

#include <iostream>

using namespace std;

const int N = 8;

bool isMovePoss(bool t[N][N], int row, int col, int moveNo, int &row1, int &col1){

    //szukamy rozwiazania, ktore mozna osiagnac w najmniejszej liczbie ruchow, wiec sprawdzamy najpierw
    //opcje ruchu o dwa wiersze do przodu, a potem o jeden wiersz do przodu; mamy tylko 4 mozliwosci ruchu, bo
    //wg tresci zadania mozemy poruszac sie tylko do przodu
    int dy[]={ 2, 2, 1, 1};
    int dx[]={-1, 1,-2, 2};

    row1 = row + dy[moveNo];
    col1 = col + dx[moveNo];

    return (row1>=0 && row1<N && col1>=0 && col1<N && (!t[row1][col1]));
}

bool knight(bool t[N][N], int row, int col, int jumpNo, bool &lastRowReached, int &stepNo){
    //t[row][col]=true;
    if(row == N-1) lastRowReached = true;
    if(lastRowReached) return true;

    int row1, col1;
    for(int i=0; i<N; i++)
        if(isMovePoss(t, row, col, i, row1, col1)){
            if(!lastRowReached) stepNo+=1;
            knight(t, row1, col1, jumpNo+1, lastRowReached, stepNo);
        }
    //t[row][col]=false;
    if(!lastRowReached) return false;
}

bool knightStart(bool t[N][N], int &stepNo){
    bool lastRowReached = false;
    for(int i=0; i<N; i++)
        if(t[0][i] && knight(t, 0, i, 0, lastRowReached, stepNo)) return true;
    return false;
}

int main(){

    //inicjalizacja tablicy testowej
    bool tab[N][N];

    int row, col;
    for(int i=0; i<N*N; i++){
        row = i/N;
        col = i%N;

        tab[row][col] = false;
    }

    //inicjalizacja pierwszej sciezki, ktora sprawdzi nasza funkcja -dluzszej
    tab[0][1]=true;
    tab[1][3]=true;
    tab[2][1]=true;
    tab[3][3]=true;
    tab[4][1]=true;
    tab[5][3]=true;
    tab[6][1]=true;
    tab[7][3]=true;

    //inicjalizacja drugiej sciezki, ktora sprawdzi funckja -krotszej
    tab[0][7]=true;
    tab[2][6]=true;
    tab[4][5]=true;
    tab[6][6]=true;
    tab[7][4]=true;

    int stepNo = 0;
    cout<<knightStart(tab, stepNo)<<endl;

    cout<<stepNo<<endl;

    return 0;
}
