//author: @kaspiotr (Piotr Kasprzyk)

/*
20. Dane są dwie tablice t1[N] i t2[N] zawierające liczby naturalne. Z wartości w obu tablicach
możemy tworzyć sumy. „Poprawna” suma to taka, która zawiera co najmniej jeden element (z tablicy
t1 lub t2) o każdym indeksie. Na przykład dla tablic:
t1 = [1,3,2,4] i t2 = [9,7,4,8] poprawnymi sumami są na przykład 1+3+2+4, 9+7+4+8, 1+7+3+8,
1+9+7+2+4+8. Proszę napisać funkcje generującą i wypisująca wszystkie poprawne sumy, które są
liczbami pierwszymi. Do funkcji  należy przekazać dwie tablice, funkcja powinna zwrócić liczbę
znalezionych i wypisanych sum.
*/

#include <iostream>

using namespace std;

const int N = 4;

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

//idx -analizowany w danym wywolaniu funckji rekurencyjnej indeks tablic t1[] i t2[]
//option -"0"(bierzemy do sumy t1[idx] i t2[idx]), "1"(bierzemy do sumy tylko t1[idx],
//        "2"(bierzemy do sumy tylko t2[idx])
int legitSumRek(int t1[N], int t2[N], int idx, int option, int result[N]){
    if(idx == N){ //warunek konca -przejrzelismy wszystkie indeksy w tablicach t1 i t2
        //obliczamy sume na podstawie zawartosci tablicy result[N]
        int sum = 0;
        for(int i=0; i<N; i++) {
            if(result[i] == 0) sum += t1[i] + t2[i];
            if(result[i] == 1) sum += t1[i];
            if(result[i] == 2) sum += t2[i];
        }

        //wyswietlenie uzyskanej sumy -jesli okazala sie byc liczba pierwsza
        if(isPrime(sum)){
            for(int i=0; i<N; i++){
                if(result[i] == 0) cout<<t1[i]<<" + "<<t2[i]<<" + ";
                if(result[i] == 1) cout<<t1[i]<<" + ";
                if(result[i] == 2) cout<<t2[i]<<" + ";
            }
            cout<<endl;

            return 1; //dodajemy uzyskana sume do wyniku
        }
        else return 0; //nie dodajemy uzyskanej sumy do wyniku -bo nie byla liczba pierwsza
    }

    if(option == 0) result[idx]=0;
    if(option == 1) result[idx]=1;
    if(option == 2) result[idx]=2;
    idx++;

    return legitSumRek(t1,t2,idx,0,result)+legitSumRek(t1,t2,idx,1,result)+legitSumRek(t1,t2,idx,2,result);
}

int legitSum(int t1[N], int t2[N]){
    int result[N]; //tablica, ktora pod kazdym z indeksow bedzie miala zapisana decyzje co do elementu, ktory sie
                   //pod tym indeksem znajduje, tzn. jesli pod indeksem idx bedzie liczba:
                   //"0"-do sumy wzieto elementy tablicy t1[idx] i t2[idx]
                   //"1"-do sumy wzieto tylko element z talbicy t1[idx]
                   //"2"-do sumy wzieto tylko element z tablicy t2[idx]
    return legitSumRek(t1,t2,0,0,result)+legitSumRek(t1,t2,0,1,result)+legitSumRek(t1,t2,0,2,result);
}

int main(){
    int t1[] = {1,3,2,4};
    int t2[] = {9,7,4,8};

    cout<<legitSum(t1,t2)<<endl;

    return 0;
}

