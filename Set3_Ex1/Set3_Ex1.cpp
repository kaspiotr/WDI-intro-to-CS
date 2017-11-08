//author: @kaspiotr (Piotr Kasprzyk)

/*
1. Napisać program zamieniający liczbę naturalną z systemu 10 na podstawę 2-16
*/

#include <iostream>

using namespace std;

//funckja przyjmujaca licze a w systemie 10-tkowym i zwracajaca liczbe w systemie o podstawie sysBase
void decToSysBase(int a, int sysBase){
    int tabSize = 0;
    int b = a;
    int pos = 1;
    while(b != 0){
        b /= sysBase;
        tabSize++;
    }

    char *tab = new char [tabSize];
    int idx = 0;

    while(a != 0){
        if(a%sysBase<10) tab[idx] = (a%sysBase)+'0';
        else{
            switch(a%sysBase){
                case 10:
                    tab[idx]='A';
                    break;
                case 11:
                    tab[idx]='B';
                    break;
                case 12:
                    tab[idx]='C';
                    break;
                case 13:
                    tab[idx]='D';
                    break;
                case 14:
                    tab[idx]='E';
                    break;
                case 15:
                    tab[idx]='F';
            }
        }
        a/=sysBase;
        idx++;
    }

    for(int i=tabSize-1; i>=0; i--){
        cout<<tab[i];
    }
    cout<<endl;

    delete [] tab;
}

int main(){
    int a ;
    cout<<"Podaj liczbe w systemie decymalnym"<<endl;
    cin>>a;

    for(int i=2; i<=16; i++){
        cout<<"W systemie o podstawie "<<i<<" ";
        decToSysBase(a, i);
    }

    return 0;
}