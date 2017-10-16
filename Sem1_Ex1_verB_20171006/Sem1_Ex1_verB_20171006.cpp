/*
Zad.1, Cw.1, WDI, 6.10.17, wersja B

Napisac funckje, ktora jako argument otrzymuje tablice t[N], a zwraca sume
10-ciu najwiekszych wartosci (nie elementow jak w wersji A) znajdujacych sie w tablicy.
Jesli nie ma 10-ciu roznych wartosci w tablicy funckja zwraca -1.
 */

#include <iostream>
#include <climits>

using namespace std;

const int N = 20;
int tab[N] = {6,1,4,2,3,3,2,4,5,9,7,6,5,1,7,8,8,9,10,10};
int tab2[N]={1,2,3,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};


void printTab(int t[N]){

    for(int i=0; i<N; i++){
        cout<<t[i]<<"\t";
    }
    cout<<endl;
}

int diffMax(int tab[N], int prev){
    int max=-1;

    for(int i=0; i<N; i++){
        if(tab[i]<prev && max<tab[i]){
            max = tab[i];
        }
    }

    return max;
}

int sumOf10GreatestVal(int t[N]){

    int *s = new int [10];

    int i=9;
    int prev =INT_MAX;
    int val;

    while(i >= 0){
        val = diffMax(t, prev);
        if(val != -1){
            s[i]=val;
            prev = val;
        }
        else{ //nie istnieje 10 roznych elementow w tablicy tab[]
            return -1;
        }
        i--;
    }

    int sum = s[0];

    for(int i=1; i<10; i++){
        sum +=s[i];
    }

    return sum;
}

int main(){

    printTab(tab);
    cout<<sumOf10GreatestVal(tab)<<endl;

    printTab(tab2);
    cout<<sumOf10GreatestVal(tab2)<<endl;

    return 0;
}