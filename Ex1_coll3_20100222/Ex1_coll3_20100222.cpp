//author: @kaspiotr (Piotr Kasprzyk)

/*
ad-wdi kolokwium 3, poniedziałek, 22 lutego 2010 Nazwisko Imię
Zad. 1 Dana jest duża tablica typu tab=array [1..max, 1..max] of integer wypełniona liczbami
naturalnymi. Proszę napisać funkcję, która sprawdza czy w tablicy istnieją dwa elementy odległe o
jeden ruch skoczka szachowego, których wartości są liczbami względnie pierwszymi.
Uwagi:
• Zawartość tablicy wejściowej nie może ulec zmianie.
• Czas na rozwiązanie zadania wynosi 25 minut, za zadanie można otrzymać 5 punktów.
• Oceniane będą: przejrzystość i czytelność kodu oraz efektywność rozwiązania.
 */

#include <iostream>

using namespace std;

const int N = 8;
int tab[8][8];


//funckja, ktora sprawdza czy ruch skoczka jest mozliwy na szachownicy
bool isMovePossible(int row, int col, int i, int &row2, int &col2, int tabSize) { //i-numer ruchu
    int dx[]={ 1, 2, 2, 1,-1,-2,-2,-1}; //ruch w kolumnie
    int dy[]={ 2, 1,-1,-2,-2,-1, 1, 2}; //ruch w wierszu

    col2 = col + dx[i];
    row2 = row + dy[i];

    return (col2>=0 && col2<tabSize && row2>=0 && row2<tabSize);
}

int nwd(int a, int b){
    while(a*b != 0){
        if(a>b) a%=b;
        else b%=a;
    }

    if(a != 0) return a;
    return b;
}

//funckja, ktora spradza czy w tablicy dwuwymiarowej sa dwie liczby wzglenie pierwsze (relatively prime numbers)
bool areThere2Coprime(int tab[N][N]){
    int row, col, row2, col2;

    for(int i=0; i<N*N; i++){
        row = i/N;
        col = i%N;

        for(int j=0; j<8; j++){
            if(isMovePossible(row,col,j,row2,col2,N)==true){
                if(nwd(tab[row][col], tab[row2][col2])==1)
                    return true;
            }
        }

    }

    return false;
}

int main(){

    int row, col;
    for(int i=0; i<N*N; i++){
        row = i/N;
        col = i%N;

        tab[row][col]=15;
    }

    tab[2][2]=28; //dla tej opcji program powinien wypisac "TAK"
    //tab[1][2]=30; //dla tej opcji program powinien wypisac "NIE"

    if(areThere2Coprime(tab)==true) cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;

    return 0;
}