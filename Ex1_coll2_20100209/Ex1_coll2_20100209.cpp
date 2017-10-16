/*
ad-wdi kolokwium 2, wtorek, 9 lutego 2010 Nazwisko Imię
Zad. 1 Dana jest duża tablica typu tab=array[1..n] of integer. Proszę napisać funkcję, która
zwraca sumę cyfr elementów tablicy zapisanych w systemie o podstawie 7, których indeks nie jest
liczbą pierwszą. Wskazówka: rozważyć metodę sita.
Uwagi:
• Zawartość tablicy wejściowej nie może ulec zmianie.
• Czas na rozwiązanie zadania wynosi 25 minut, za zadanie można otrzymać 5 punktów.
• Oceniane będą: przejrzystość i czytelność kodu oraz efektywność rozwiązania.
 */

#include <iostream>

using namespace std;

//funckja uzupelniajaca tablice bool'i bedaca sitem Erastotenesa
void sitoE(bool *E, int size){

    E[0]=false;
    E[1]=false;

    for(int i=2; i*i<=size; i++){
        if(E[i]==true){
            for(int j=i*i; j<=size; j+=i){
                E[j]=false;
            }
        }
    }
}

int in7BaseSys(int a){
    int b=a; int pos=1;
    while(b != 0){
        b/=7;
        pos*=10;
    }

    pos /= 10;
    int result=0, rest;

    while(a != 0){
        rest = a%7;
        rest *= pos;
        result += rest;
        pos /= 10;
        a /= 7;
    }

    return result;
}

int sumOfDigits(int a){
    int sum=0, digit;
    while(a != 0){
        digit=a%10;
        sum += digit;
        a /= 10;
    }

    return sum;
}

int sumOfDigIn7(int tab[], int n){

    bool *E = new bool [n+1];

    for(int i=0; i<n+1; i++) E[i]=true;

    sitoE(E, n+1); //przesianie sita Erastotenesa

    int sum=0, in7BaseVal;

    for(int i=0; i<n; i++){
        if(E[i]==false){
            in7BaseVal = in7BaseSys(tab[i]);
            sum += sumOfDigits(in7BaseVal);
        }
    }

    delete [] E;

    return sum;
}

int main(){

    int n=4;

    int tab[]={13,14,15,16}; //dla zadanej tablicy program powinien wypisac "9" i wypisuje :)

    cout<<sumOfDigIn7(tab, n)<<endl;

    return 0;
}

