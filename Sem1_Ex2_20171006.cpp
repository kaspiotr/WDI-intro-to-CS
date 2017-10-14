/*
Dane sa dwie tablice jednowymiarowe tego samego ramiaru int t1[N] oraz int t2[N]. W obu tablicach elementy
sa uporzadkowane niemalejaco. Nalezy wypelnic trzecia tablice int t3[M], tak aby byla ona posortowana niemalejaco.
*/

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N=100;
const int M=2*N;

int t1[N];
int t2[N];
int t3[M];

//funkcja inicjalizuje tablice rozmiaru N w porzadku niemalejacym
//wartosciami z zakresu od 1 do 999
void nonDecreasingOrderTab(int tab[N]){
    int val;
    int currMax = 1;

    for(int i=0; i<N; i++){
        val = ((double)rand()/((double)RAND_MAX+1.0))*(999-currMax+1)+currMax;
        tab[i]=val;
        currMax = val; //bo tablica ma byc w porzadk niemalejacym
    }
}

void printTab(int tab[], int size){
    for(int i=0; i<size; i++){
        cout<<tab[i]<<"\t";
    }
    cout<<endl;
}

void Merge(int t1[N], int t2[N], int t3[M]){
    int i,j,k;

    i=j=k=0;

    while(i<N && j<N){
        if(t1[i]<t2[j]){
            t3[k++]=t1[i++];
        }
        else{
            t3[k++]=t2[j++];
        }
    }

    while(i<N){
        t3[k++]=t1[i++];
    }

    while(j<N){
        t3[k++]=t2[j++];
    }
}

int main(){
    srand(time(NULL));

    nonDecreasingOrderTab(t1);
    printTab(t1, N);
    cout<<endl;

    nonDecreasingOrderTab(t2);
    printTab(t2, N);
    cout<<endl;

    Merge(t1, t2, t3);
    printTab(t3, M);

    return 0;
}