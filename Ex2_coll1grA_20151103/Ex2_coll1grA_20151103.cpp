//author: @kaspiotr (Piotr Kasprzyk)

/*
ad-wdi-k1a, wtorek, 3 listopada 2015

 Prosze napisac program, ktory wypelnia tablice t[N] pseudolosowymi liczbami nieparzytymi
 z zakresu [1...99], a nastepnie wyznacza roznice pomiedzy dlugoscia najdluzszego znajdujacego
 sie w niej ciagu arytmetycznego o dodatniej roznicy, a dlugoscia najdluzszego ciagu
 arytmetycznego o ujemnej roznicy, przy zalozeniu, ze kolejymi wyrazami ciagu sa elementy
 tablicy o kolejnych indeksach.
*/

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void initializeTab(int *tab, int N){
    int val;
    for(int i=0; i<N; i++){
        val=rand()%100+1;
        if(val%2 == 0){
            val++;
            tab[i]=val;
        }
        else{
            tab[i]=val;
        }
    }
}

void printTab(int *tab, int N){
    for(int i=0; i<N; i++){
        cout<<tab[i]<<"\t";
    }
    cout<<endl;
}

int diffBetweenLengths(int *t, int N){

    int rest;
    int j,k;
    int posRest, negRest;
    int currLength=1, maxPosLen=1, maxNegLen=0;
    for(int i=0; i<N-1; i=j){

        currLength=0;

        j=i+1;
        k=i;

        rest = t[j]-t[i];
        while(t[j]-t[k] == rest){
            currLength++;
            j++; k++;
        }

        if(rest<0){
            negRest = rest;
            if(maxNegLen < currLength){
                maxNegLen = currLength;
            }
        }

        if(rest>=0){
            posRest = rest;
            if(maxPosLen < currLength){
                maxPosLen = currLength;
            }
        }
    }

    int result = maxPosLen - maxNegLen;

    return result;
}

int main(){

    srand(time(NULL));
    int N;
    //int N=11;
    cin>>N;

    int *t = new int [N];

    //int t[N]={7,9,11,1,13,99,7,39,35,31,27};
    //int t[N]={27,31,35,39,11,9,7,1,13,99,7};
    initializeTab(t, N);

    printTab(t, N);

    cout<<diffBetweenLengths(t,N)<<endl;

    delete [] t;

    return 0;
}
