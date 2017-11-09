#include <iostream>

using namespace std;
/*Dane s¹ dwie tablice t1[N] i t2[N] zawieraj¹ce liczby naturalne. Z wartoœci w obu tablicach
mo¿emy tworzyæ sumy. „Poprawna” suma to taka, która zawiera co najmniej jeden element (z
tablicy t1 lub t2) o ka¿dym indeksie. Na przyk³ad dla tablic: t1 = [1,3,2,4] i t2 = [9,7,4,8]
poprawnymi sumami s¹ na przyk³ad 1+3+2+4, 9+7+4+8, 1+7+3+8, 1+9+7+2+4+8. Proszê
napisaæ funkcje generuj¹c¹ i wypisuj¹ca wszystkie poprawne sumy, które s¹ liczbami
pierwszymi. Do funkcji nale¿y przekazaæ dwie tablice, funkcja powinna zwróciæ liczbê
znalezionych i wypisanych sum.*/

const int N=4;

bool isPrime(int a){
    if(a <= 1) return false;
    if(a%2 == 0){
        if(a == 2) return true;
        else return false;
    }

    int div = 3;
    while(div*div <= a){
        if(a%div == 0){
            if(a == div) return true;
            else return false;
        }
        else div+=2;
    }

    return true;
}
int sum(int t1[N],int t2[N],int s,int i){ //s-suma, i-numer aktualnego indeksu


   // cout<<s-p<<endl;

        if(i==N && isPrime(s)){

      //  cout<<i<<endl;

        cout<<s<<" :suma "<<endl;
        return 0;

    }
    if(i<N){
        sum(t1,t2,s+t2[i],i+1); //z pierwszej tablicy
        sum(t1,t2,s+t1[i],i+1); // z drugiej tablicy
        sum(t1,t2,s+t1[i]+t2[i],i+1); // z obu tablic

    }

}


int main(){

    int t1[4]={1,3,2,4};
    int t2[4]={9,7,4,8};
    sum(t1,t2,0,0);





}
