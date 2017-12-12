//author: @kaspiotr (Piotr Kasprzyk)

/*
Zad. 2 Dany jest N elementowy zbior liczba na turalnych w postaci tablicy int t[N]. Prosze napisac
funckje, ktora zwraca informacje czy jest mozliwy podzial zbioru na trzy zbiory tak aby w kazdym
z trzech zbiorow laczna liczba jedynek w liczbach zapisanych w systemie binarnym byla jednakowa. Na
przyklad dla zbioru {2,3,5,7,11,13,16} mozliwy podzial to {2,13,16} {3,11} {5,7} czyli w systemie
dwojkowym {10,1101,10000} {11,1011} {101,111} -w kazdym zbiorze jest 5 jedynek.
*/

#include <iostream>

using namespace std;

const int N = 7;

int decToBin(int a){
    int rest, result=0, pos=1;

    while(a != 0){
        rest = a%2;
        result += pos*rest;
        pos *= 10;
        a /= 2;
    }

    return result;
}

int onesCounter(int b){
    int noOfOnes=0;

    while(b != 0){
        if(b%10 == 1) noOfOnes++;
        b /= 10;
    }

    return noOfOnes;
}

bool isPossToDivInThreeSets(int t[N], int idx, int set1[N], int set2[N], int set3[N]){

    if(idx > N-1){ //bo zwiekszamy idx o 1 i przechodzimy do tego wywolania funkcji rekurencyjnej zeby tylko sprawdzic ten warunek
        int noOf1InSet1 = 0, noOf1InSet2 = 0, noOf1InSet3 = 0;
        for(int i=0; i<N; i++){
            noOf1InSet1 += onesCounter(decToBin(set1[i]));
            noOf1InSet2 += onesCounter(decToBin(set2[i]));
            noOf1InSet3 += onesCounter(decToBin(set3[i]));
        }

        if(noOf1InSet1 == noOf1InSet2 && noOf1InSet1 == noOf1InSet3) return true;
        return false;
    }

    bool result; //dla przejrzystosci, mozna bez tej zmiennej
    set1[idx]=t[idx];
    result = isPossToDivInThreeSets(t,idx+1,set1,set2,set3);
    if(result) return true;

    set2[idx]=t[idx]; set1[idx]=0;
    result = isPossToDivInThreeSets(t,idx+1,set1,set2,set3);
    if(result) return true;

    set3[idx]=t[idx]; set2[idx]=0;
    result = isPossToDivInThreeSets(t,idx+1,set1,set2,set3);
    if(result) return true;
    set3[idx]=0; //to nie jest konieczne

    return false;
}

bool isPossToDivInThreeSetsStart(int t[N]){

    int set1[N], set2[N], set3[N];

    for(int i=0; i<N; i++){
        set1[i]=0; set2[i]=0; set3[i]=0;
    }

    set1[0]=t[0];
    if(isPossToDivInThreeSets(t, 1, set1, set2, set3)) return true;

    set2[0]=t[0]; set1[0]=0;
    if(isPossToDivInThreeSets(t, 1, set1, set2, set3)) return true;

    set3[0]=t[0]; set2[0]=0;
    if(isPossToDivInThreeSets(t, 1, set1, set2, set3)) return true;
    set3[0]=0; //to nie jest konieczne

    return false;
}



int main(){

    int tab[]={2,3,5,7,11,13,16};

    cout<<isPossToDivInThreeSetsStart(tab)<<endl;

    return 0;
}



