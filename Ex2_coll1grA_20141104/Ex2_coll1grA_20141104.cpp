//author: @kaspiotr (Piotr Kasprzyk)

/*
ad-wdi-k1a, wtorek, 4 listopada 2014

2. Dane są dwie tablice mogące pomieścić taką samą liczbę elementów:
 int t1[N][N];
 int t2[M]; // M = N*N
W każdym wierszu tablicy t1 znajdują się uporządkowane niemalejąco (w obrębie wiersza) liczby
naturalne. Proszę napisać fragment programu przepisujący wszystkie liczby z tablicy t1 do t2, tak aby
liczby w tablicy t2 były uporządkowane niemalejąco.
*/

#include <iostream>

using namespace std;

void print1DTable(int *t2, int N){
    for(int i=0; i<N*N; i++){
        cout<<t2[i]<<"\t";
    }
    cout<<endl;
}


void print2DTable(int **t1, int N){
    int row, col;

    for(int i=0; i<N*N; i++){
        row = i/N;
        col = i%N;

        cout<<t1[row][col]<<"\t";

        if(col == N-1) cout<<endl;
    }
    cout<<endl;
}

void Merge(int *A, int end1, int end2){
    int i=0;
    int j=end1;
    int k=0;

    int *B = new int [end2];

    while(i<end1 && j<end2){  // można zastąpić inkrementowanie tak jak Garek mówił czyli B[k++]=A[i++]
        if(A[i]<A[j]){
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

    while(j <end2){
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
    //przepisujemy t1 do t2
    int row, col;
    int size = N*N;

    for(int i=0; i<size; i++){
        row=i/N;
        col=i%N;

        t2[i]=t1[row][col];
    }

    for(int i=N; i<size; i*=2){
        for(int j=0; j<size-i; j+=2*i){
            int end2 = (2*i < size-j) ? 2*i : size-j;
            Merge(&(t2[j]), i, end2);
        }
    }
}

int main(){

    int N=5;
    int **t1 = new int* [N];

    for(int i=0; i<N; i++){
        t1[i] = new int [N];
    }

    t1[0][0]= 4; t1[0][1]= 4; t1[0][2]= 6; t1[0][3]= 8; t1[0][4]= 12;
    t1[1][0]= 3; t1[1][1]= 4; t1[1][2]= 7; t1[1][3]= 12; t1[1][4]= 13;
    t1[2][0]= 1; t1[2][1]= 1; t1[2][2]= 7; t1[2][3]= 8; t1[2][4]= 9;
    t1[3][0]= 2; t1[3][1]= 2; t1[3][2]= 3; t1[3][3]= 3; t1[3][4]= 5;
    t1[4][0]= 5; t1[4][1]= 8; t1[4][2]= 9; t1[4][3]= 11; t1[4][4]= 12;

    print2DTable(t1, N);

    int *t2 = new int [N*N];

    rewrite(t1, t2, N);

    print1DTable(t2, N);

    //Free each sub-array
    for(int i = 0; i < 10; i++) {
        delete[] t1[i];
    }
    //Free the array of pointers
    delete[] t1;

    delete[] t2;

    return 0;
}
