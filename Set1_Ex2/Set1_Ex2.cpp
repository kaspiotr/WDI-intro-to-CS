/*
2. Znaleźć najmniejsze wyrazy początkowe zamiast 1,1 aby w ciągu analogicznym do ciągu
Fibonacciego wystąpił w nim wyraz równy numerowi bieżącego roku.
*/

//Komentarz: nie wiem czy nie lepsze będzie zastosowanie najmniejszej sumy dwóch wyrazów, 
//oczywiście wszystko zależy od interpretacji zadania
#include <iostream>

using namespace std;
const int N = 2017;


int main(){
    int F1=1, F2=N-1, F3;

    int minProduct = F1*F2;

    int F1tmp, F2tmp, F1firstMin, F2firstMin; //zmienne pomocnicze (takie tmp uzywane w petlach ponizej)

    while((F2 - F1) != 1 && (F2 - F1) != 0) { //taki warunek, zeby przejrzec tylko polowe potencjalnych par F1 i F2
        F1tmp = F1;
        F2tmp = F2;
        F3 = F2 + F1;

        while (F1 > 0) { //cofamy sie do poczatku ciagu
            F3 = F2;
            F2 = F1;
            F1 = F3 - F2;
        }

        //robimy jeden "krok" do przodu, bo cofnelismy sie w poprzednim while'u o 1 za daleko
        F1 = F2;
        F2 = F3;

        if (F1 * F2 < minProduct) { //bo szukamy najmniejszych wyrazow poczatkowych
            minProduct = F1*F2;
            F1firstMin = F1;
            F2firstMin = F2;
        }

        F1 = F1tmp;
        F2 = F2tmp;
        F1++;
        F2--;
    }

    //if, ktory sprawia, ze F1 jest wieksze od F2 na wyjsciu -w sumie nie jest konieczny (kosmetyka)
    if(F1firstMin > F2firstMin){
        int tmp = F1firstMin;
        F1firstMin = F2firstMin;
        F2firstMin = tmp;
    }

    cout<<"F1="<<F1firstMin<<"\tF2="<<F2firstMin<<endl;

    return 0;
}

