#include <iostream>

using namespace std;
/*Dane są dwie tablice t1[N] i t2[N] zawierające liczby naturalne. Z wartości w obu tablicach
możemy tworzyć sumy. „Poprawna” suma to taka, która zawiera co najmniej jeden element (z
tablicy t1 lub t2) o każdym indeksie. Na przykład dla tablic: t1 = [1,3,2,4] i t2 = [9,7,4,8]
poprawnymi sumami są na przykład 1+3+2+4, 9+7+4+8, 1+7+3+8, 1+9+7+2+4+8. Proszę
napisać funkcje generującą i wypisująca wszystkie poprawne sumy, które są liczbami
pierwszymi. Do funkcji należy przekazać dwie tablice, funkcja powinna zwrócić liczbę
znalezionych i wypisanych sum.*/

const int N=4;
int sum(int t1[N],int t2[N],int s,int i){ //s-suma, i-numer aktualnego indeksu


   // cout<<s-p<<endl;

        if(i==N){

      //  cout<<i<<endl;

        cout<<s<<" :suma "<<endl;
        return 0;

    }
    if(i<N){
        sum(t1,t2,s+t1[i],i+1); //z pierwszej tablicy
        sum(t1,t2,s+t2[i],i+1); // z drugiej tablicy
        sum(t1,t2,s+t1[i]+t2[i],i+1); // z obu tablic

    }

}


int main(){

    int t1[4]={1,3,2,4};
    int t2[4]={9,7,4,8};
    sum(t1,t2,0,0);



}
