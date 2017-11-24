/*17. Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisad funkcję która zwraca wiersz
i kolumnę dowolnego elementu, dla którego suma otaczających go elementów jest największa.
MAX jest zdefiniowaną stałą.*/

#include <iostream>
using namespace std;
const int MAX =3;
int suma(int t[MAX][MAX],int i,int j){

    int sum=0;
    for(int a=i-1;a<=i+1&& a<MAX;a++)
        for(int b=j-1;b<=j+1 && b<MAX;b++){
            if(a<0) a++;
            if(b<0) b++;
            sum+=t[a][b];
        }
    return sum-t[i][j];
}

void msuma(int t[MAX][MAX]){

    int maxsum=0;
    int sum=0;
    int mw=0;
    int mk=0;
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++){
            sum=suma(t,i,j);
          //  cout<<sum<<endl;
        if(maxsum<sum){
            maxsum=sum;
            mw=i;
            mk=j;
        }
    }
    cout<<"w: "<<mw<<" k: "<<mk<<endl;
}

int main(){

    int t[MAX][MAX]={1,44,0,
                     22,0,1,
                      2,1,1};
    msuma(t);
        int t1[MAX][MAX]={1,44,0,
                          22,0,-22,
                          2,1,1};
     msuma(t1);
}
