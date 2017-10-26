//author: @kaspiotr (Piotr Kasprzyk)

/*
1. Mamy tablicę [1..max,1..max] of integer. Wyzeruj w niej wszystkie liczby które nie mają w tablicy innej
liczby, która powstałaby poprzez przestawienie jej cyfr. (uważając na 1000 i 0100 - nie dziala).
*/

#include <iostream>

using namespace std;

const int N = 8;

void printTab(int t[N][N]){

    int row, col;
    for(int i=0; i<N*N; i++){
        row = i/N;
        col = i%N;
        cout<<t[row][col]<<"\t";
        if(i%N == N-1) cout<<endl;
    }
    cout<<endl;
}

bool fineNumbers(int a, int b){
    int *digA = new int [10]; //tablica alokowana na stercie
    int *digB = new int [10];

    for(int i=0; i<10; i++){
        digA[i]=0;
        digB[i]=0;
    }

    int noOfDigA=0, noOfDigB=0;

    while(a != 0){
        digA[a%10]++;
        noOfDigA++;
        a/=10;
    }

    while(b != 0){
        digB[b%10]++;
        noOfDigB++;
        b/=10;
    }

    if(noOfDigA != noOfDigB){
        delete [] digA;
        delete [] digB;
        return false;
    }

    for(int i=0; i<10; i++){
        if(digA[i] != digB[i]){
            delete [] digA;
            delete [] digB;
            return false;
        }
    }

    delete [] digA;
    delete [] digB;
    return true;
}

void zeroization(int tab[N][N]){

    int row, col, row2, col2;

    bool r[N][N]; //tablica alokowana na stosie

    for(int i=0; i<N*N; i++){
        row = i/N;
        col = i%N;
        r[row][col] = false;
    }

    for(int i=0; i<N*N; i++){
        row = i/N;
        col = i%N;

        for(int j=i+1; j<N*N; j++){
            row2 = j/N;
            col2 = j%N;

            if(fineNumbers(tab[row][col], tab[row2][col2]) == true){
                r[row][col]=true;
                r[row2][col2]=true;
            }
        }
    }

    for(int i=0; i<N*N; i++){
        row = i/N;
        col = i%N;
        if(r[row][col]==false){
            tab[row][col]=0;
        }
    }
}

int main(){

    int tab[N][N];

    tab[0][0]=101; tab[0][1]=110; tab[0][2]= 23; tab[0][3]=  1; tab[0][4]=  2; tab[0][5]= 3; tab[0][6]= 4; tab[0][7]= 5;
    tab[1][0]=  6; tab[1][1]= 11; tab[1][2]=223; tab[1][3]= 32; tab[1][4]=  7; tab[1][5]= 8; tab[1][6]= 9; tab[1][7]=10;
    tab[2][0]= 11; tab[2][1]= 12; tab[2][2]= 13; tab[2][3]= 14; tab[2][4]= 15; tab[2][5]=16; tab[2][6]=17; tab[2][7]=18;
    tab[3][0]= 19; tab[3][1]= 20; tab[3][2]= 21; tab[3][3]= 22; tab[3][4]= 23; tab[3][5]=24; tab[3][6]=25; tab[3][7]=26;
    tab[4][0]= 27; tab[4][1]= 28; tab[4][2]= 29; tab[4][3]= 30; tab[4][4]= 31; tab[4][5]=32; tab[4][6]=33; tab[4][7]=34;
    tab[5][0]= 35; tab[5][1]= 36; tab[5][2]= 37; tab[5][3]= 38; tab[5][4]= 39; tab[5][5]=40; tab[5][6]=41; tab[5][7]=42;
    tab[6][0]= 43; tab[6][1]= 44; tab[6][2]= 45; tab[6][3]= 46; tab[6][4]= 47; tab[6][5]=48; tab[6][6]=49; tab[6][7]=50;
    tab[7][0]=999; tab[7][1]= 52; tab[7][2]= 53; tab[7][3]= 54; tab[7][4]= 55; tab[7][5]=56; tab[7][6]=57; tab[7][7]=58;

    printTab(tab);

    zeroization(tab);

    printTab(tab);

    return 0;
}