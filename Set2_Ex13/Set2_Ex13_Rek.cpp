//author: @kaspiotr (Piotr Kasprzyk)

/*
13. Dane są dwie liczby naturalne z których budujemy trzecią liczbę. W budowanej liczbie muszą wystąpić wszystkie cyfry
występujące  w liczbach wejściowych. Wzajemna kolejność cyfr każdej z liczb wejściowych musi być zachowana. Na przykład
mając liczby 123 i 75 możemy zbudować liczby 12375, 17523, 75123, 17253,itd. Proszę napisać funkcję która wyznaczy ile
liczb pierwszych można zbudować z dwóch zadanych liczb.
 */

//rozwiazanie rekurencyjne

#include <iostream>

using namespace std;

bool isPrime(int a){
    if(a < 2) return false;
    if(a%2 == 0) {
        if (a == 2) return true;
        if (a != 2) return false;
    }

    int div = 3;
    while(div*div <= a){
        if(a%div == 0){
            if(a == div) return true;
            else return false;
        }
        else div += 2;
    }

    return true;
}

//funckja pomocnicza odwracajaca kolejnosc cyfr podanej liczby
int reverse(int a){
    int pos=1, b=a;
    while(b != 0){
        pos *= 10;
        b /= 10;
    }
    pos /= 10;

    int reverse=0, digit;

    while(a != 0){
        digit = a%10;
        reverse += pos*digit;
        pos /= 10;
        a /= 10;
    }

    return reverse;
}

//number -utworzona w danym wywolaniu funkcji rekurencyjnej
//option -zmienna, ktora mowi z ktorej liczby ucinamy cyfre "1" -z pierwszej, "2" -z drugiej
int genNumRek(int number, int no1, int no2, int option){
    //warunek konca rekurencji: uzylismy wszystkich cyfr jednej z liczb
    if((no1 == 0 || no2 == 0) && option == 1){ //...&& option==1 -zeby dwa razy nie drukowac i zliczac tej samej liczby

        while(no1 != 0){
            number *= 10;
            number += no1%10;
            no1 /= 10;
        }

        while(no2 != 0){
            number *= 10;
            number += no2%10;
            no2 /= 10;
        }

        if(isPrime(number)){
            cout<<number<<endl;
            return 1; //otrzymana liczba byl pierwsza -zliczamy ja
        }
        else{
            //cout<<number<<endl;
            return 0; //otrzymana liczba nie byla pierwsza -nie zliczamy jej
        }

    }

    if((no1 == 0 || no2 == 0) && option == 2) return 0; //gdy option==2 -nie zliczamy i wyswietlamy, bo zrobilismy to
                                                        //juz dla option==1
    if(option == 1){
        number *= 10;
        number += no1%10;
        no1 /= 10;
    }

    if(option == 2){
        number *= 10;
        number += no2%10;
        no2 /= 10;
    }

    return genNumRek(number, no1, no2, 1) + genNumRek(number, no1, no2, 2);

}

int howManyPrimes(int no1, int no2){

    //odwracamy cyfry liczb no1 i no2
    no1 = reverse(no1);
    no2 = reverse(no2);

    return genNumRek(0, no1, no2, 1) + genNumRek(0, no1, no2, 2);
}

int main(){
    int no1, no2;
    cin>>no1>>no2;

    cout<<howManyPrimes(no1, no2)<<endl;

    return 0;
}
