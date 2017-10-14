/*
Cw.1, Zad.3, WDI, 6.10.17

Dana jest tablica jednwymiarowa. Elementy tablicy to liczby naturalne posortowane niemalejaco
(liczby sie powtarzaja). Chcemy sie dowiedziec jaka jest wartosc elementu w tablicy ktory
wystepuje  w niej najczesciej. Moze to byc np. tablica zawierajaca 10000 elementow, w ktorej
powtarzajace sie wartosci wystepuja w grupach po kilkadziesiat/kilkaset elementow.
*/

#include <iostream>
#include <limits.h>
#include <time.h>
#include <cstdlib>

using namespace std;

const int N = 10000;

void printTab(int tab[], int size){

    for(int i=0; i<size; i++){
        cout<<tab[i]<<"\t";
    }
    cout<<endl;
}

//funckja, ktora zwraca p, czyli indeks ostatniego elementu w tablicy tab[]
//o wartosci rownej wartosci szukanego elementu el
int binarySearch(int tab[], int n, int el){
    int l=0; //lewy indeks
    int p=n-1; //prawy indeks
    int mid; //srodkowy element

    while(l <= p){
        mid=(l+p)/2;

        if(el >= tab[mid]) l = mid+1;
        else p = mid-1;
    }

    return p;
}

//funckja, ktora zwraca wartosc elementu znajdujacego sie w tablicy tab[], ktory
//powtarza sie najczesciej
int mostPopEl(int tab[], int n){
    int lastIdx=0; //zmienna, ktora bedzie wskazywac indeks ostatniego elementu
    //w tablicy tab o podanej wartosci
    int nextIdx;
    int noOfEl=0, noOfMostPopEl=0, valOfMostPopEl;

    for(int i=0; i<n; i+=nextIdx){
        lastIdx = binarySearch(tab, n, tab[i]);

        noOfEl = lastIdx - i + 1;
        if(noOfMostPopEl < noOfEl){
            noOfMostPopEl = noOfEl;
            valOfMostPopEl = tab[lastIdx];
        }

        nextIdx = lastIdx+1;
    }

    return valOfMostPopEl;
}

int main(){

    srand(time(NULL));

    int tab[N];

    int noOfEl, val;
    int currMax = 1; //zmienna, dzieki ktorej przy tworzeniu tablicy

    for(int i=0; i<N; i+=noOfEl){
        // wzor: ((double) rand() / ((double) RAND_MAX + 1.0)) * (max - min + 1) + min;
        //losowanie ilosci elementow, ktore maja byc w zakresie od min=1 do max=999 (tzn. [min, max])
        noOfEl = ((double) rand() / ((double) RAND_MAX + 1.0)) * (999 - 1 + 1) + 1;
        val = ((double) rand() / ((double) RAND_MAX + 1.0)) * (INT_MAX - currMax + 1) + currMax;

        for(int j=i; j<N && j<=i+noOfEl-1; j++) tab[j]=val;
        currMax = val+1; //bo mamy miec kolejnosc niemalejaca w tablicy tab[]
    }

    printTab(tab, N);

    cout<<mostPopEl(tab, N)<<endl;

    return 0;
}

