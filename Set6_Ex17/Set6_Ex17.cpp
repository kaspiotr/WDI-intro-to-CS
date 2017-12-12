//author: @kaspiotr (Piotr Kasprzzyk)

/*
17. Dany jest ciąg zer i jedynek zapisany w tablicy int t*N+. Proszę napisad funkcję, która
odpowiada na pytanie czy jest możliwe pocięcie ciągu na kawałki z których każdy
reprezentuje liczbę pierwszą. Długośd każdego z kawałków nie może przekraczad 30. Na
przykład dla ciągu 111011 jest to możliwe, a dla ciągu 110100 nie jest możliwe.
*/

#include <iostream>
#include <string>

using namespace std;

const int N = 6;

struct divisors{
    int val;
    bool isDiv;
};

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
        } else {
            div += 2;
        }
    }

    return true;
}

//idx -indeks ostatniego elementu jednego z podzbiorow, na ktory zostala podzielona tablica t[] w danym wywolaniu
//funckji rekurencyjnej
bool isItPossToDiv(divisors t[N], int idx, bool include){

    if(idx == N-1){
        int j, result=0, pos=10;
        for(int i=N-1; i>=0; i-=j){
            if(t[i].isDiv){
                result+=t[i].val;
                j=i-1;
                while(j>=0 && !t[j].isDiv){
                    result+=pos*t[j].val;
                    pos*=10;
                    j--;
                }
                if(!isPrime(result)) return false;

                i=j+1;
                result=0;
                pos=10;
            }
        }

        return true;
    }

    bool res;
    //ustawiam element pod idx jako koniec zbioru
    if(include) t[idx].isDiv=true;
    res = isItPossToDiv(t, idx+1, true);
    if(res) return true;

    t[idx].isDiv=false; //wycofujemy zmiany dokonane w poprzednim wywolaniu rekurencyjnym
    //nie ustawiam elementu pod idx jako konca zbioru
    res = isItPossToDiv(t, idx+1, false);
    if(res) return true;

    return false;
}



bool isItPossToDivStart(int t[N])
{
    divisors tab[N];

    for(int i=0; i<N; i++){
        tab[i].val = t[i];
        tab[i].isDiv = false;
    }

    tab[N-1].isDiv = true; //bo zawsze ostatni element tablicy bedzie ostatnim elementem kazdego z podzbiorow

    bool res;
    res = isItPossToDiv(tab, 0, true);
    if(res) return true;

    res = isItPossToDiv(tab, 0, false);
    if(res) return true;

    return false;
}


int main(){

    int tab1[]={1,1,1,0,1,1};
    int tab2[]={1,1,0,1,0,0};

    cout<<isItPossToDivStart(tab1)<<endl;
    cout<<isItPossToDivStart(tab2)<<endl;

    return 0;
}

