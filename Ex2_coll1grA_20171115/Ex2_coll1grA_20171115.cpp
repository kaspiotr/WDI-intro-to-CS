
/*2. Dane sa deklaracje:
   const int N=1000;
   int tab[N];
   Tablica tab jest wypelniona liczbami naturalnymi. Prosze napisac funkcje, ktora zwraca dlugosc najdluzszego, spojnego
   podciagu rosnacego dla ktorego suma jego elementow jest rowna sumie indeksow tych elementow. Do funkcji nalezy
   przekazac tablice, funckja powinna zwrocic dlugosc znalezionego podciagu lub wartosc 0 jezeli taki podciag nie
   istnieje.
*/



#include <iostream>

using namespace std;

const int N=6;
int suma(int t[N]){

    int licz=1;
    int sumind=0,sum=t[0];
    int maxlicz=1, maxsum=0,maxsumind=0;
    for(int j=1;j<N;j++){

        for(int i=j;i<N;i++){

            if(t[i-1]<t[i]){
               // cout<<"ind "<< i<<" "<<t[i]<<endl;
                sumind+=i;
                sum+=t[i];
                licz++;
                //cout<<"sumind: "<<sumind<<" sum: "<<sum<<endl;
                if(sum>sumind){
                  // cout<<sum<< " "<<sumind<<endl;
                    sumind=i;
                    sum=t[i];
                    licz=1;
                }
                 if(sum==sumind){
                 //       cout<<"dupa"<<endl;
                    if(maxlicz<licz){
                        maxlicz=licz;
                        maxsum=sum;
                        maxsumind=sumind;

                    }
            }

        }
        else {
            sumind=i;
            sum=t[i];
            licz=1;
        }
    }
    }
    cout<<maxsumind<<" : "<<maxsum<<endl;
    return maxlicz;

}

int main(){
    int t[6]={1,2,3,4,5,6};   //wynik=1
    int t1[6]={0,1,2,3,4,16}; //wynik=5
    int t2[6]={0,9,0,2,4,8};    //wynik=4
    int t3[6]={0,9,2,3,4,8};    //wynik =3
    cout<<suma(t)<<" :wynik"<<endl;
    cout<<suma(t1)<<" :wynik"<<endl;
    cout<<suma(t2)<<" :wynik"<<endl;
    cout<<suma(t3)<<" :wynik"<<endl;
}
