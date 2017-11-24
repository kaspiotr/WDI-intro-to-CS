/*22. Dana jest tablica int t[N][N] wypełniona przypadkowymi wartościami. Proszę napisad funkcję, która dla
zmiennej typu tablica zwraca numer wiersza w którym występuje najdłuższy spójny fragment złożony z liczb
o tej samej wartości. W przypadku kilku fragmentów o tej samej długości należy zwrócid pozycję pierwszego
z nich*/

#include <iostream>
using namespace std;

const int N = 3;

int spojny_pod(int t[N][N]){

    int max_licz=0;
    int licz=0;
    int max_wers=0;
    int wers=0;
    int liczba=0;
     int mliczba=0;
    for(int i=0 ;i<N;i++)
        for(int j=1;j<N;j++){
        if(t[i][j]==t[i][j-1]){

            licz++;
            wers=i;
            liczba=t[i][j];

         if(max_licz<licz){
                    max_licz=licz;
                    max_wers=wers;
                    mliczba=liczba;
                }
        }
        else{

                licz=0;
                wers=0;
        }
    }
    cout<<mliczba<<endl;
    return max_wers;

}

int main(){

    int t[N][N]={0,1,5,
                 1,1,2,
                 5,5,5};
    cout<<spojny_pod(t);

}
