
/*1. Dwie liczby naturalne sa rozno-cyfrowe jezeli nie posiadaja zadnej wspolnej cyfry. Prosze napisac program, ktory
   wczytuje dwie liczby naturalne i poszukuje najmniejszej podstawy systemu (w zakresie 2-16) w ktorym liczby sa
   rozno-cyfrowe. Program powinien wypisac znaleziona podstawe, jezeli podstawa taka nie istnieje nalezy wypisac
   komunikat o jej braku. Na przyklad: dla liczb 123 i 522 odpowiedzia jest podstawa 11 bo
   123(10)=102(11) i 522(10)=435(11).*/


#include <iostream>
using namespace std;

bool zamienisprawdz(int x, int y,int podstawa){ //funkcja sprawdza czy dla danej podstawy liczby są roznoliczbowe

    int licz=0;
    int a,b;
        for(int j=0;j<podstawa;j++){
                a=x,b=y;
            while(a>0 || b>0){
                   // cout<<a%podstawa<<" "<<b%podstawa<<endl;
                if(a%podstawa==j) licz++;
                if(b%podstawa==j) licz++;
                if(licz>1) return false;
                a/=podstawa;b/=podstawa;
            }
            licz=0;

        }
        return true;
}

int main(){

 //   if(!zamienisprawdz(123,123,11)) cout<<"Nie są roznoliczbowe"<<endl;
  //  else cout<<"Są roznoliczbowe"<<endl;
  int x,y;
  cin>>x;
  cin>>y;
  int a,b;
    bool s= false; //zmienna która powie ze w zadnym z systemów dwie liczby nie spełniaja tej zaleznosci
    for(int i=2;i<16;i++){
            a=x,b=y;
            if(zamienisprawdz(a,b,i)){
                cout<<"W systemie "<<i<<" liczby sa roznoliczbowe"<<endl;
                s=true;
            }
    }
    if(!s) cout<<"Zaden system nie dziala"<<endl;
}
