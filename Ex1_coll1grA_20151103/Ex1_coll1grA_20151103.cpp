/*
ad-wdi-k1a, wtorek, 3 listopada 2015
1) Prosze napisac program, ktory wczytuje liczbe naturalna A i odpowiada na pytanie: "czy w ktorymkolwiek
 z systemow o podstawie 2-16, wszytskie cyfry liczby A zapisanej w tym systemie, sa liczbami pierwszymi?".
 */

#include <iostream>

using namespace std;

bool isPrime(int a){
    if(a == 1) return false;
    if(a%2 == 0){
        if(a == 2) return true;
        if(a != 2) return false;
    }

    int div = 3;
    while(div*div <= a){
        if(a%div == 0){
            if(a == div) return true;
            if(a != div) return false;
        }
        else{
            div+=2;
        }
    }

    return false;
}


//funckja przyjmujaca licze a w systemie 10-tkowym i zwracajaca liczbe w systemie o podstawie sysBase
bool areAllDigitsPrime(int a, int sysBase){
    int tabSize = 0;
    int b = a;
    int pos = 1;
    while(b != 0){
        b /= sysBase;
        tabSize++;
    }

    int *tab = new int [tabSize];
    int idx = 0;

    while(a != 0){
        tab[idx] = a%sysBase;
        a/=sysBase;
        idx++;
    }

    for(int i=0; i<tabSize; i++){
        if(isPrime(tab[i])==false) return false;
    }

    delete [] tab;

    return true;
}

int main(){
    int a;

    cin>>a;

    for(int i=2; i<=16; i++){
        cout<<"W systemie o podstawie "<<i<<" ";
        if(areAllDigitsPrime(a, i) == true) cout<<"TAK";
        else cout<<"NIE";
        cout<<endl;
    }

    return 0;
}

