//author: @kaspiotr (Piotr Kasprzyk)

/*
5. Napisać program wypełniający tablicę int t[MAX] liczbami naturalnymi 1-1000 i sprawdzający czy
istnieje element tablicy zawierający wyłącznie cyfry nieparzyste.
MAX jest zdefiniowaną stałą.
*/

#include <iostream>

using namespace std;

const int MAX = 10;

//funckja sprawdzajaca czy wszystkie cyfry podanej liczby sa nieparzyste
bool areAllDigitsOdd(int a){
    int digit;

    while(a != 0){
        digit = a%10;
        if(digit%2 == 0) return false;
        a/=10;
    }

    return true;
}


int main(){
    srand(time(NULL));

    int tab[MAX];

    for(int i=0; i<MAX; i++){
        tab[i]=rand()%1000+1;
    }

    for(int i=0; i<MAX; i++){
        cout<<tab[i]<<"\t";
    }
    cout<<endl;

    bool isThereElWithAllDigsOdd = false;

    for(int i=0; i<MAX; i++){
        if(areAllDigitsOdd(tab[i])){
            isThereElWithAllDigsOdd = true;
            break;
        }
    }

    if(isThereElWithAllDigsOdd) cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;

    return 0;
}
