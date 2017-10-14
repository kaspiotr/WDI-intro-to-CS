/*
Cw.1, Zad.1, WDI, 6.10.17

Napisac funckje, ktora jako argument otrzymuje tablice t[N], a zwraca sume
10-ciu najwiekszych elementow znajdujacych sie w tablicy.
 */
#include <iostream>

using namespace std;

//funckja drukujaca tablice
void printTab(int tab[], int size){

    for(int i=0; i<size; i++){
        cout<<tab[i]<<"\t";
    }
    cout<<endl;
}


//funkcja zwracajaca indeks najmniejszego elementu w tablicy
int idxOfMin(int tab[]){
    int min = tab[0];
    int minIdx = 0;

    for(int i=1; i<10; i++){
        if(min > tab[i]){
            min = tab[i];
            minIdx = i;
        }
    }

    return minIdx;
}

//funkcja zwracajaca sume 10-ciu najwiekszych elementow tablicy t[]
int sumOf10Greatest(int t[], int size){
    int s[10];

    int j; //indeks, zmienna pomocnicza

    for(int i=0; i<10; i++){
        s[i]=t[i];
    }

    for(int i=10; i<size; i++){
        j = idxOfMin(s);

        if(t[i]>s[j]) s[j]=t[i];
    }

    int sum = s[0];

    for(int i=1; i<10; i++){
        sum+=s[i];
    }

    return sum;
}

int main(){

    int t[]={ 3, 7,13, 4, 8,10,23,24,20,11, 9, 5, 2,14,44,77, 6,22,33,19};// wynik->289
    int tabSize = 20;

    printTab(t,tabSize);

    cout<<sumOf10Greatest(t, tabSize)<<endl;


    return 0;
}