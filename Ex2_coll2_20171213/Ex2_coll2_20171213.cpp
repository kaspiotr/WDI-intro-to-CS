//author: @kaspiotr (Piotr Kasprzyk)

/*
2.Dana jest tablica int t[9]. Tablice nalezy wypelnic liczami 1..9. Prosze napisac program, ktory wypisze wszystkie
 mozliwe "wypelnienia" tablicy. Warunki dodatkowe:
    -zadne dwie pierwsze liczby nie mogą lezec obok siebie
    -suma dwoch kolejnych elementow tablicy musi byc co najmniej 2
    -1 jest juz wpisane do tablicy do t [0]
*/

#include <iostream>

using namespace std;

const int N = 9;

void printTab(int t[N]){

    for(int i=0; i<N; i++){
        cout<<t[i]<<"\t";
    }

    cout<<endl;
}

bool isPrime(int a){
    if(a <= 1) return false;
    if(a%2 == 0){
        if(a == 2) return true;
        if(a != 2) return false;
    }

    int div = 3;
    while(div*div <= a){
        if(a%div == 0){
            if(a == div) return true;
            else return false;
        } else div += 2;
    }

    return true;
}

void insertRec(int t[N], bool usedDig[N], int idx){
    if(idx == N) printTab(t);
    if(idx < N){
        for(int i=2; i<=9; i++){
            if(!usedDig[i]){
                t[idx]=i; usedDig[i]=true;
                if((t[idx-1]+t[idx])>=2 && !(isPrime(t[idx-1]) && isPrime(t[idx])))
                    insertRec(t, usedDig, idx+1);
                usedDig[i]=false;
                t[idx]=0;
            }
        }
    }
}

void inserting(int t[N]){
    bool usedDig[N+1];

    usedDig[0]=true;
    usedDig[1]=true;

    for(int i=2; i<N+1; i++) usedDig[i]=false;
    int idx = 1;

    for(int i=2; i<=9; i++){
        usedDig[i]=true;
        t[idx]=i;
        if((t[idx-1]+t[idx]) >= 2 && !(isPrime(t[idx-1]) && isPrime(t[idx]))){
            insertRec(t,usedDig,idx+1);
            usedDig[i]=false;
            t[idx]=0;
        }
    }
}

int main(){

    int tab[N];

    tab[0]=1;
    for(int i=1; i<N; i++) tab[i]=0;

    inserting(tab);

    return 0;
}