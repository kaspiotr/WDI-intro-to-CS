/*16. Dana jest tablica int t[MAX][MAX] wypełniona liczbami całkowitymi. Proszę napisad funkcję która zwraca
wiersz i kolumnę dowolnego elementu, dla którego iloraz sumy elementów w kolumnie w którym leży element do sumy
elementów wiersza w którym leży element jest największa.
MAX jest zdefiniowaną stałą.*/


#include <iostream>

using namespace std;

const int MAX=3;
int sum(int t[MAX][MAX]){

    int sw[MAX];
    int sk[MAX];
    int mw=0;
    int mk=0;
    int maxls=0;
    int ilo=0;
     for(int i=0;i<MAX;i++){

         sw[i]=0;
         sk[i]=0;

     }
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++){
            sw[i]+=t[i][j];

            sk[i]+=t[j][i];

        }
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++){
            if(sw[j]!=0){
             ilo=sk[i]/sw[j];
            // cout<<ilo<<" "<<sk[i]<<" "<<sw[j]<<" "<<j<<" "<<i<<endl;

            }
            if(maxls<ilo){
                maxls=ilo;
                mw=i;
                mk=j;
        }
        ilo=0;

    }
    cout<<maxls<<" "<<mw<<" "<<mk<<endl;
}
void print2DTab(int tab[MAX][MAX]){
    int row, col;

    for(int i=0; i<MAX*MAX; i++){
        row = i/MAX;
        col = i%MAX;

        cout<<tab[row][col]<<"\t";
        if(col == MAX-1) cout<<endl;
    }
    cout<<endl;
}

int main(){

    int t[MAX][MAX]={1,44,0,
                     22,0,1,
                     2,1,1};
    sum(t);
    print2DTab(t);
    int t1[MAX][MAX]={1,44,0,
                      22,0,-22,
                      2,10,1};
    sum(t1);
    print2DTab(t1);
}
