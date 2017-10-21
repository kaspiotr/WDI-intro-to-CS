//author: @kaspiotr (Piotr Kasprzyk)

/*
9. Napisać program wyszukujący liczby zaprzyjaźnione mniejsze od miliona.
*/

//liczby zaprzyjaznione a i b, to takie, ktorych suma dzielnikow wlasciwych
//(dzielnikow, ktore sa mniejsze od tej liczby) sa rowne drugiej liczbie
//i na odwrot
#include <iostream>

using namespace std;

const int N = 1000000; //przy N=10e6 glowna petla while iterowala w nieskonczonosc

int main(){

    int i=1; //i -liczba z przedzialu [1;999999], dla ktorej szukamy liczby zaprzyjaznionej
    int a; //pierwsza z pary liczb zaprzyjaznionych
    int b = 1; //suma dzielnikow wlasciwych liczby a (zaczynamy od 1 bo 1|a)
    int div = 2; //aktualnie rozpatrywany dzielnik

    int sum = 1; //suma dzielnikow liczby b (od 1 bo 1|b)
    while(i < N){
        a = i;
        b = 1;
        div = 2;
        //sumowanie dzielnikow pierwszej z pary liczb
        while(div*div < a){ //iterujemy po pierwszej polowie dzielnikow -dlatego potem jest b+=(div+a/div)
            if(a%div == 0){
                b += (div + a/div); //jeszcze a/div bo dodajemy oprocz div dzielnik mu odpowiadajacy,
                                    //tzn. taki, że div * (a/div) = a
            }
            div++;
        }

        //sumowanie dzielnikow liczby b, ktora jest suma dzielnikow liczby a
        div = 2;
        sum = 1;

        while(div*div < b){ //ostra nierownosc, bo interesuja nas tylko dzielniki wlasciwe, b<N -bo obie
            if(b>N) break;
            if(b%div == 0){        //liczby maja byc mniejsze od miliona
                sum += (div + b/div);
            }
            div++;
        }

        if(a == sum && a<b){
            cout<<a<<"\ti "<<b<<endl;
        }
        i++;
    }

    return 0;
}



