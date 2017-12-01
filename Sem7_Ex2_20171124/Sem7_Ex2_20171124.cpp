//author: @kaspiotr (Piotr Kasprzyk)

/*
Napisac funckje rekurencyjna void wypisz(), ktora wypisuje kolejne elementy tablicy.
*/

#include <iostream>

using namespace std;

const int N = 10;

void wypisz(int t[N], int idx){
    if(idx < N){
        cout<<t[idx]<<"\t";
        wypisz(t, idx+1);
    }
}

//zamiana miejscami dwoch linijek powyzszej funkcji nie spowoduje wypisania tablicy w odwrotnej kolejnosci
void wypiszReversedTest(int t[N], int idx){
    if(idx < N){
        wypisz(t, idx+1);
        cout<<t[idx]<<"\t";
    }
}

int main(){

    int tab[]={1,2,3,4,5,6,7,8,9,10};

    wypisz(tab, 0);
    cout<<endl;
    wypiszReversedTest(tab, 0);

    return 0;
}
