/*
ad-wdi kolokwium 1, czwartek, 28 stycznia 2010 Nazwisko Imię
Zad. 1 Dana jest duża tablica typu tab=array[1..n] of integer. Proszę napisać funkcję, która
zwraca informację, czy w tablicy zachodzi następujący warunek: „wszystkie elementy, których
indeks jest elementem ciągu Fibonacciego są liczbami złożonymi, a wśród pozostałych
przynajmniej jedna jest liczbą pierwszą”.
Uwagi:
• Czas na rozwiązanie zadania wynosi 25 minut, za zadanie można otrzymać 5 punktów.
• Oceniane będą: przejrzystość i czytelność kodu oraz efektywność rozwiązania.
*/
//Zadanie bez użycia pomocniczej tablicy


#include <iostream>
#include <cstdlib>

using namespace std;

const int N = 10;

bool isPrime(int n){

  if(n<2) return false;
  for(int i=2;i*i<=n;i++)
    if(n%i==0) return false;
  return true;
}


bool doesItOccur(int tab[], int n){
    int F1=1,F2=1, F3=F1+F2;
    bool czy_pierwsza=false;
    int licznik_prawdy=0;
    for(int i=0;i<n && czy_pierwsza==false;i++){
        if(i==F1){
        czy_pierwsza=isPrime(tab[i]);
        F1=F2;
        F2=F3;
        F3=F1+F2;
        }
        else if(isPrime(tab[i])) licznik_prawdy=1;
    }
    if(czy_pierwsza==true || licznik_prawdy==0){
        cout<<"Dane nie spelniaja warunkow zadania"<<endl;
        return false;
    }
    else cout<<"Dane sa poprawne"<<endl;
    return true;
}


int main(){
    //           0, F, F, F, 4, F, 6, 7, F, 9,10,11,12, F
    int tab1[]={ 7, 4, 6, 8,12,16, 6, 8,34, 4}; //->tak
    int tab2[]={ 1, 2, 3, 5, 4, 7, 8,13,14,15}; //->nie
    int tab3[]={ 1, 4, 6, 8,12,16, 6, 8,34, 4}; //->nie

    if(doesItOccur(tab1, N) == true) cout<<"tab1 TAK"<<endl;
    else cout<<"tab1 NIE"<<endl;
    if(doesItOccur(tab2, N) == true) cout<<"tab2 TAK"<<endl;
   else cout<<"tab2 NIE"<<endl;
   if(doesItOccur(tab3, N) == true) cout<<"tab3 TAK"<<endl;
   else cout<<"tab3 NIE"<<endl;

    return 0;
}
