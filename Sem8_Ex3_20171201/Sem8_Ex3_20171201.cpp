//author: @kaspiotr (Piotr Kasprzyk)

/*
Zad.3 Przyklad algorytmu, ktory wykorzysuje rekurence z powrotami. Dana jest tablica int t[N][N] reprezentujaca
szachownice, na ktorej wykonujemy ruchy skoczkiem. Nalezy napisac funkcje, ktora wypisze podana tablice
z wpisanymi w kazde z jej pol numerem skoku, ktore musial wykonac skoczek aby znalezc sie na kazdym polu podanej tablicy
dokladnie raz.
*/

#include <iostream>

using namespace std;

const int N=5;

void print2DTable(int t[N][N]){
    int row, col;

    for(int i=0; i<N*N; i++){
        row = i/N;
        col = i%N;

        cout<<t[row][col]<<" ";
        if(col == N-1) cout<<endl;
    }
    cout<<endl;
}

bool isMovePoss(int t[N][N], int row, int col, int i, int &row1, int &col1){

    int dx[] = { 1, 2, 2, 1,-1,-2,-2,-1};
    int dy[] = {-2,-1, 1, 2, 2, 1,-1,-2};

    row1 = row + dy[i];
    col1 = col + dx[i];

    return (row1>=0 && row1<N && col1>=0 && col1<N && t[row1][col1]==0);
}

//end -dodatkowa zmienna, ktora pozwoli zatrzymac wykonywanie sie funkcji po znalezieniu pierwszego z rozwiazan
void knight(int t[N][N], int row, int col, int stepNo, bool &end){

    if(end) return;
    int row1, col1;
    t[row][col]=stepNo;
    if(stepNo == N*N){
        print2DTable(t);
        end = true;
    }

    for(int i=0; i<8; i++)
        if(isMovePoss(t,row,col,i,row1,col1)) knight(t,row1,col1,stepNo+1, end);

    t[row][col]=0;
}

int main(){

    int tab[N][N];

    int row2, col2;

    for(int i=0; i<N*N; i++){
        row2 = i/N;
        col2 = i%N;

        tab[row2][col2]=0;
    }

    bool end=false;

    knight(tab, 0, 0, 1, end);

    return 0;
}

