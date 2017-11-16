//author: @kaspiotr (Piotr Kasprzyk)

/*
1. Dwie liczby naturalne sa rozno-cyfrowe jezeli nie posiadaja zadnej wspolnej cyfry. Prosze napisac program, ktory
   wczytuje dwie liczby naturalne i poszukuje najmniejszej podstawy systemu (w zakresie 2-16) w ktorym liczby sa
   rozno-cyfrowe. Program powinien wypisac znaleziona podstawe, jezeli podstawa taka nie istnieje nalezy wypisac
   komunikat o jej braku. Na przyklad: dla liczb 123 i 522 odpowiedzia jest podstawa 11 bo
   123(10)=102(11) i 522(10)=435(11).
*/

//rozwiazanie z wykorzystaniem tablicy

#include <iostream>

using namespace std;

//funkcja sprawdzajaca czy podane dwie liczby maja rozne cyfry w podanym systemie liczbowym
bool areDigsDiffInNumSys(int no1, int no2, int sysBase){
    int digNo1 = 0, digNo2 = 0;
    int no1copy = no1, no2copy = no2;

    while(no1copy != 0){
        digNo1++;
        no1copy /= sysBase;
    }

    while(no2copy != 0){
        digNo2++;
        no2copy /= sysBase;
    }

    int *number1 = new int [digNo1];
    int *number2 = new int [digNo2];

    int idx = digNo1-1;

    while(no1 != 0){
        number1[idx--] = no1%sysBase;
        no1 /= sysBase;
    }

    idx = digNo2-1;

    while(no2 != 0){
        number2[idx--] = no2%sysBase;
        no2 /= sysBase;
    }

    int *digits = new int [sysBase];

    for(int i=0; i<sysBase; i++) digits[i]=0;

    for(int i=0; i<digNo1; i++) digits[number1[i]]=1;

    for(int i=0; i<digNo2; i++){
        if(digits[number2[i]] == 1){
            delete [] number1;
            delete [] number2;
            delete [] digits;
            return false;
        }
    }

    delete [] number1;
    delete [] number2;
    delete [] digits;
    return true;
}

int main(){
    int a, b;
    cin>>a>>b;

    int areThereAnyNumSys = false; //flaga, ktora mowi czy jest choc jeden taki system liczbowy o podstawie od 2 do 16
                                   //w ktorym dwie podane liczby maja rozny zbior cyfr
    for(int i=2; i<=16; i++){
        if(areDigsDiffInNumSys(a,b,i)){
            cout<<i<<endl;
            areThereAnyNumSys = true;
            break;
        }
    }

    if(!areThereAnyNumSys) cout<<0<<endl;

    return 0;
}
