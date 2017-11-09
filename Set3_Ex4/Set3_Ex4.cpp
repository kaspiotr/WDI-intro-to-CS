//author: @kaspiotr (Piotr Kasprzyk)

/*
4. Napisać program wypełniający tablicę int t[MAX] liczbami naturalnymi 1-1000 i sprawdzający
czy każdy element tablicy zawiera co najmniej jedną cyfrę nieparzystą.
MAX jest zdefiniowaną stałą.
*/

#include <iostream>

using namespace std;

const int MAX = 10; //na potrzeby testow

//funckja, ktora sprawdza czy co najmniej jedna cyfra podanej liczy jest nieparzysta
bool isAtLeastOneOdd(int a){
    int digit;

    while(a != 0){
        digit = a%10;
        if(digit%2 == 1) return true;
        a/=10;
    }

    return false;
}

int main(){
    srand(time(NULL));

    int tab[MAX];

    //int tab[MAX] = {9,9,9,9,9,9,9,9,9,9};

    for(int i=0; i<MAX; i++){
        tab[i]=rand()%1000+1;
    }

    for(int i=0; i<MAX; i++){
        cout<<tab[i]<<"\t";
    }
    cout<<endl;

    bool allElsHaveOddDig = true;
    for(int i=0; i<MAX; i++){
        if(!isAtLeastOneOdd(tab[i])) allElsHaveOddDig = false;
    }

    if(allElsHaveOddDig) cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;

    return 0;
}

