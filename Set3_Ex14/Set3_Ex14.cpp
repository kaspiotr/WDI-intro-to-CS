/*14. Proszę napisać program, który wypełnia tablice int tab[MAX] trzycyfrowymi liczbami
pseudolosowymi, a następnie wyznacza i wypisuje długość najdłuższego podciągu spójnego
znajdującego się w tablicy dla którego w tablicy występuje również rewers tego ciągu.
Na przykład dla tablicy: 2,9,3,1,7,11,9,6,7,7,1,3,9,12,15 odpowiedzią jest liczba 4.
MAX jest zdefiniowaną stałą.*/
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
const int MAX=1000;


int dupa(int tab[MAX]){

    srand(time(NULL));
    int res=0;
    int ind;
    for(int i=0;i<MAX;i++){
        tab[i]=rand()%900+100;
        cout<<tab[i]<<" ";
    }
    for(int i=0;i<MAX;i++){
        for(int j=MAX-1;j>=0;j--){
        ind=0;
        while(i+ind<MAX && j-ind>=0 && tab[i+ind]==tab[j-ind])
            ind++;
        res=max(ind,res);

        }
    }
    return res;

}
int main(){
    int t[MAX];
    cout<<endl<<"WYNIK:"<<dupa(t);


}
