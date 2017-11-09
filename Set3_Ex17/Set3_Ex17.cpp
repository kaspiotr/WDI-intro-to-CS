/*17. Mamy zdefiniowaną n-elementową tablicę liczb całkowitych. Proszę napisać funkcję
zwracającą wartość typu bool oznaczającą, czy w tablicy istnieje dokładnie jeden element
najmniejszy i dokładnie jeden element największy (liczba elementów najmniejszych oznacza
liczbę takich elementów o tej samej wartości).
*/

#include <iostream>

using namespace std;

const int N=5;
bool max_min(int t[N]){

    int licz1=0,licz2=0;
    int varmin=t[0],varmax=t[0];
    for(int i=1;i<N;i++){

        if(varmin==t[i]) licz1=1;
        if(varmax==t[i]) licz2=1;

        if(varmin>t[i]){
            varmin=t[i];
            licz1=0;
        }
        if(varmax<t[i]){
            varmax=t[i];
            licz2=0;
        }

    }
    cout<<varmin<<"  "<<varmax<<endl;
    if(licz1==1 || licz2==1) return false;
        return true;
}

int main(){

    int t[5]={1,1,4,5,6};
    int t2[5]={0,1,2,5,5};
    int t3[5]={0,1,2,3,4};

    if (max_min(t)) cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
    if (max_min(t2)) cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
    if (max_min(t3)) cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
}
