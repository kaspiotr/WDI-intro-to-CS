//author: @kaspiotr (Piotr Kasprzyk)

/*
5. Dane są dwie tablice mogące pomieścić taką samą liczbę elementów:
int t1[MAX][MAX];
int t2[MAX2];             // MAX2 = MAX*MAX
W każdym wierszu tablicy t1 znajdują się uporządkowane niemalejąco (w obrębie wiersza)
liczby naturalne. Proszę napisać funkcję przepisującą wszystkie liczby z tablicy t1 do
t2, tak aby liczby w tablicy t2 były uporządkowane niemalejąco.
MAX jest zdefiniowaną stałą.
*/

#include <iostream>

using namespace std;

const int MAX = 6;
const int MAX2 = MAX*MAX;

int tab[MAX][MAX];
int tab2[MAX2];

void printTab(int tab[MAX2]){
    for(int i=0; i<MAX2; i++){
        cout<<tab[i]<<"\t";
    }
    cout<<endl;
}

void print2DTab(int tab[MAX][MAX]){
    int row, col;

    for(int i=0; i<MAX*MAX; i++){
        row = i/MAX;
        col = i%MAX;

        cout<<tab[row][col]<<"\t";
        if(col == MAX-1) cout<<endl;
    }
    cout<<endl;
}

void rewriteSingletons(int t1[MAX][MAX], int t2[MAX2]){

    int *idxs = new int [MAX];
    int prev = -1;

    for(int i=0; i<MAX; i++) idxs[i]=0;

    int currMin, currMinRow;
    int k=0; //indeks mowiacy, ktory element z kolei wpisujemy do tablicy t2[]

    for(int i=0; i<MAX2; i++){
        currMin = t1[0][idxs[0]];
        currMinRow = 0;

        for(int j=1; j<MAX; j++){
            if(currMin > t1[j][idxs[j]]){
                currMin = t1[j][idxs[j]];
                currMinRow = j;
            }
        }

        if(idxs[currMinRow] < MAX-1){ //bo pole tablicy idxs moze miec maksymalnie wartosc MAX-1
            idxs[currMinRow]++;
        }

        t2[k++]=currMin;
    }

    delete [] idxs;
}

int main(){

    int row, col;
    for(int i=0; i<MAX2 ; i++){
        row = i/MAX;
        col = i%MAX;

        tab[row][col]=99;
    }

    tab[0][0]=99; tab[0][1]=99; tab[0][2]=99; tab[0][3]=99; tab[0][4]=99; tab[0][5]=99;
    tab[1][0]= 2; tab[1][1]=99; tab[1][2]=99; tab[1][3]=99; tab[1][4]=99; tab[1][5]=99;
    tab[2][0]= 3; tab[2][1]=99; tab[2][2]=99; tab[2][3]=99; tab[2][4]=99; tab[2][5]=99;
    tab[3][0]= 1; tab[3][1]= 2; tab[3][2]= 3; tab[3][3]=99; tab[3][4]=99; tab[3][5]=99;
    tab[4][0]= 2; tab[4][1]= 3; tab[4][2]=99; tab[4][3]=99; tab[4][4]=99; tab[4][5]=99;
    tab[5][0]=99; tab[5][1]=99; tab[5][2]=99; tab[5][3]=99; tab[5][4]=99; tab[5][5]=99;

    print2DTab(tab);

    rewriteSingletons(tab, tab2);

    printTab(tab2);

    return 0;
}

