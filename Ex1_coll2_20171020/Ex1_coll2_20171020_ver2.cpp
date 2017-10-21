//author: @kaspiotr (Piotr Kasprzyk)

/*
Dana jest tablica int tab[1000][1000] wypelniona liczbami naturalnymi
w taki sposob, ze w kazdym wierszu liczby te sa posortowane rosnaco.
Napisac funckje int max1000(int tab[1000][1000]), ktora dla tablicy
tab zwraca sume 1000 najmniejszych liczb znajdujacych sie w tej tablicy.

Czas na wykonanie zadania: 15 min
 */

/*
Rozwiazanie: mergeSort na tablicy tab[1000][1000] i zsumowanie
 10-ciu najmniejszych elementow
 */

#include <iostream>

using namespace std;

int tab[1000][1000];

void Merge(int *A, int end1, int end2){
    int i=0;
    int j=end1;
    int k=0;

    int *B = new int [end2];

    while(i<end1 && j<end2){
        if(A[i]<A[j]){
            B[k++]=A[i++];
        }
        else{
            B[k++]=A[j++];
        }
    }

    while(i<end1) B[k++]=A[i++];
    while(j<end2) B[k++]=A[j++];

    for(int m=0; m<end2; m++){
        A[m]=B[m];
    }

    delete [] B;
}

void MergeSort(int *A, int size){
    for(int i=1000; i<size; i*=2){
        for(int j=0; j<size-i; j+=2*i){
            int end2 = (2*i<size-j) ? 2*i : size-j ;
            Merge(&(A[j]), i, end2);
        }
    }
}

int max1000(int tab[1000][1000]){
    int *t1D = new int [1000000];
    int sum = 0;

    int row, col;
    for(int i=0; i<1000000; i++){
        row = i/1000;
        col = i%1000;
        t1D[i] = tab[row][col];
    }

    MergeSort(t1D, 1000000);

    for(int i=0; i<1000; i++){
        sum +=t1D[i];
    }

    delete [] t1D;

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

    tab[0][0]= 2; tab[0][1]=99; tab[0][2]=99; tab[0][3]=99; tab[0][4]=99; tab[0][5]=99;
    tab[1][0]=99; tab[1][1]=99; tab[1][2]=99; tab[1][3]=99; tab[1][4]=99; tab[1][5]=99;
    tab[2][0]= 3; tab[2][1]=99; tab[2][2]=99; tab[2][3]=99; tab[2][4]=99; tab[2][5]=99;
    tab[3][0]= 1; tab[3][1]= 2; tab[3][2]= 3; tab[3][3]=99; tab[3][4]=99; tab[3][5]=99;
    tab[4][0]= 2; tab[4][1]= 3; tab[4][2]=99; tab[4][3]=99; tab[4][4]=99; tab[4][5]=99;
    tab[5][0]=99; tab[5][1]=99; tab[5][2]=99; tab[5][3]=99; tab[5][4]=99; tab[5][5]=99;

    //Wynik jaki powinna zwrocic funckja max1000, to: 2+3+1+2+3+2+3+99*994 = 16 + 98307 = 98323

    cout<<max1000(tab)<<endl;

    return 0;
}