//author: @kaspiotr (Piotr Kasprzyk)

/*
8. Napisać program wyszukujący liczby doskonałe mniejsze od miliona.
 */

//liczby doskonale to takie, ktorych suma podzielnikow wlasciwych jest im rowna, np. 6 jest liczba doskonala, bo:
// 6= 3*2*1 i 6 = 3+2+1

#include <iostream>

using namespace std;

const int N = 10e6;

int main(){

    int div=1, sum=0, k=1; //div -dzielnik, sum -suma dzielnikow wlasciwych, k -liczba z zakresu [1;10e6]

    while(k < N){
        k++;
        while(div*div <= k){
            if(k%div == 0){
                sum +=div;
                if(div!=k/div && div != 1){
                    sum += k/div;
                }
            }
            div++;
        }

        if(sum == k) cout<<k<<"\t";

        sum=0, div=1;
    }

    return 0;
}