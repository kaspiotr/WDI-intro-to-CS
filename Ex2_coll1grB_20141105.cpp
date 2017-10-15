/*
ad-wdi-k1b, środa, 5 listopada 2014

2. Dane są dwie tablice mogące pomieścić taką samą liczbę elementów:
 int t1[10][N];
 int t2[M]; // M = 10*N
W każdym wierszu tablicy t1 znajdują się uporządkowane rosnąco (w obrębie wiersza) liczby
naturalne.
Proszę napisać fragment programu przepisujący wszystkie singletony (liczby występujące dokładnie
raz) z tablicy t1 do t2, tak aby liczby w tablicy t2 były uporządkowane rosnąco. Pozostałe elementy
tablicy t2 powinny zawierać zera.
 */

#include <iostream>

using namespace std;

void printTable(int *tab, int tabSize){
    for(int i=0; i<tabSize; i++){
        cout<<tab[i]<<"\t";
    }
    cout<<endl;
}

void Merge(int *A, int end1, int end2){
    int i=0;
    int j=end1;
    int k=0;

    int *B = new int [end2];

    while(i<end1 && j<end2){
        if(A[i] < A[j]){
            B[k]=A[i];
            i++;
            k++;
        }
        else{
            B[k]=A[j];
            j++;
            k++;
        }
    }

    while(i < end1){
        B[k]=A[i];
        i++;
        k++;
    }

    while(j < end2){
        B[k]=A[j];
        j++;
        k++;
    }

    for(int m=0; m<end2; m++){
        A[m]=B[m];
    }

    delete [] B;
}

void rewrite(int **t1, int *t2, int N){
    int row, col;

    for(int i=0; i<10*N; i++){
        row = i/N;
        col = i%N;

        t2[i]=t1[row][col];
    }

    //teraz posortujemy tablice t2 uzywajac zmodyikowanej wersji
    //algorytmu MergeSort
    int tabSize = 10*N;
    for(int i=N; i<tabSize; i*=2){
        for(int j=0; j<tabSize-i; j+=2*i){
            int end2 = (2*i < tabSize-j) ? 2*i : tabSize-j;
            Merge(&(t2[j]), i, end2);
        }
    }



    //teraz usuwamy z tablicy t2 powtarzajace sie elementy
}

int main(){

    int N = 5;
    int **t1 = new int* [10];

    for(int i=0; i<10; i++){
        t1[i] = new int [N];
    }

    t1[0][0]=7; t1[0][1]=8; t1[0][2]=9; t1[0][3]=10; t1[0][4]=13;
    t1[1][0]=1; t1[1][1]=2; t1[1][2]=7; t1[1][3]=8;  t1[1][4]=9;
    t1[2][0]=7; t1[2][1]=8; t1[2][2]=9; t1[2][3]=10; t1[2][4]=13;
    t1[3][0]=6; t1[3][1]=8; t1[3][2]=10; t1[3][3]=12; t1[3][4]=14;
    t1[4][0]=1; t1[4][1]=2; t1[4][2]=3; t1[4][3]=4; t1[4][4]=5;
    t1[5][0]=3; t1[5][1]=4; t1[5][2]=7; t1[5][3]=15; t1[5][4]=16;
    t1[6][0]=1; t1[6][1]=2; t1[6][2]=3; t1[6][3]=5; t1[6][4]=13;
    t1[7][0]=7; t1[7][1]=8; t1[7][2]=9; t1[7][3]=10; t1[7][4]=13;
    t1[8][0]=2; t1[8][1]=5; t1[8][2]=7; t1[8][3]=11; t1[8][4]=13;
    t1[9][0]=2; t1[9][1]=4; t1[9][2]=8; t1[9][3]=16; t1[9][4]=32;

    int *t2 = new int [10*N];

    rewrite(t1, t2, N);

    printTable(t2, 10*N);

    int t2Size = 10*N;

    //usuwanie z tablicy powtarzajacych sie elementow
    int j=0, k;
    for(int i=0; i<t2Size-1; i=j){
        j=i+1;
        while(t2[i]==t2[j]) j++;
        k=j;
        while(k>=i){
            if(k<j && (i+1)!=j) t2[k]=0; //bo i+1==j oznacza ze element pod indeksem i-tym jest singletonem
            k--;
        }
    }

    //printTable(t2, 10*N);

    //znow sortujemy tablice t2 MergeSortem
    for(int i=1; i<t2Size-1; i*=2){
        for(int j=0; j<t2Size-i; j+=2*i){
            int end2 = (2*i<t2Size-j) ? 2*i : t2Size-j;
            Merge(&t2[j], i, end2);
        }
    }

    printTable(t2, 10*N);

    //Free each sub-array
    for(int i = 0; i < 10; i++) {
        delete[] t1[i];
    }
    //Free the array of pointers
    delete[] t1;

    delete[] t2;

    return 0;
}



