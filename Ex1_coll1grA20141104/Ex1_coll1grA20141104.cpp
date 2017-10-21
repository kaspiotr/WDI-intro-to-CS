//author: @kaspiotr (Piotr Kasprzyk)

/*
ad-wdi-k1a, wtorek, 4 listopada 2014
1. Proszę napisać program, który wczytuje wprowadzany z klawiatury ciąg liczb naturalnych
zakończonych zerem stanowiącym wyłącznie znacznik końca danych.
Program powinien wypisać 10 co do wielkości wartość, jaka wystąpiła w ciągu.
Na przykład dla ciągu: 1,2,3,2,3,4,5,6,7,8,9,9,11,12,13,0 powinna zostać wypisana liczba 3.
Można założyć, że w ciągu znajduje się wystarczająca liczba elementów.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

void printTable(int *tab, int size){
    for(int i=0; i<size; i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(int A[], int p, int r){
    int pivot = A[r];

    int j = p-1;

    for(int i=p; i<r; i++){
        if(A[i] <= pivot){
            j++;
            swap(A[j], A[i]);
        }
    }

    j++;
    swap(A[j],A[r]);

    return j;
}

void QuickSort(int *A, int p, int r){
    while(p<r){
        int q = Partition(A, p, r);
        QuickSort(A, p, q-1);
        p=q+1;
    }
}

int main(){
    string seq;

    cin>>seq; //przykladowe dane wejsciowe: 1,2,3,2,3,4,5,6,7,8,9,9,11,12,13,0

    int strSize = seq.size();

    int *tab = (int*)malloc(strSize*sizeof(int));

    int idx = 0; //idx -wskazuje aktualnie rozpatrywany indeks ciagu wejsciowego
    int pos = 1; //wskazuje pos cyfry z ciagu dla aktualnie rozwazanej liczby
    int currInt=0; //aktualnie konstruowana liczba na podstaiwe ciagu
    int digit=0;
    int length=0;
    int tabIdx=0;

    while(idx < strSize){
        pos = 1;
        currInt=0;

        while(seq[idx] != '0' && seq[idx] != ','){
            digit = seq[idx]-'0';
            currInt *= pos;
            currInt += digit;
            pos*=10;
            idx++;
        }

        if(seq[idx] == ','){
            tab[tabIdx] = currInt;
            tabIdx++;
            idx++;
            length++;
            continue;
        }

        if(seq[idx]=='0') break;
    }

    tab = (int*)realloc(tab, length*sizeof(int));

    printTable(tab, length);
    //cout<<length;

    //teraz posortujemy tablice tab[]
    QuickSort(tab, 0, length-1);
    //printTable(tab, length);

    //wypisanie 10-tego co do wielkosci elementu tablicy tab[]
    cout<<tab[length-10];

    delete tab;

    return 0;
}