//author: @kaspiotr (Piotr Kasprzyk)

/*
13. Dane są dwie liczby naturalne z których budujemy trzecią liczbę. W budowanej liczbie muszą wystąpić wszystkie cyfry
występujące  w liczbach wejściowych. Wzajemna kolejność cyfr każdej z liczb wejściowych musi być zachowana. Na przykład
mając liczby 123 i 75 możemy zbudować liczby 12375, 17523, 75123, 17253,itd. Proszę napisać funkcję która wyznaczy ile
liczb pierwszych można zbudować z dwóch zadanych liczb.
 */

#include <iostream>

using namespace std;

bool isPrime(int a){
    if(a <= 1) return false;
    if(a%2 == 0){
        if(a==2) return true;
        else return false;
    }
    if(a == 2) return true;
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

int main(){
    int no1, no2;
    cin>>no1>>no2;

    //teraz bedziemy tworzyc maski binarne dla no1 i no2
    /* np. jesli no1 = 123 a no2 = 75 i cyfry tworzonej liczby, ktore pochodza z no1 oznaczymy przez "0", a cyfry
     * ktore pochodza z liczby no2 przez "1", to otrzymamy maski od 00011 do 11000 wlacznie (beda to kolejne liczby
     * naturalne w zapisie dwojkowym od 00011 od 11000 wlacznie z pominieciem tych, w ktorych liczba jedynek nie
     * jest rowna 2)
     */

    int pow1, pow2;
    pow1 = pow2 = 1;

    int m1 = no1;
    no1 = 0;

    int digNo1 = 0, digNo2;

    while(m1 != 0){
        digNo1++;
        pow1 *= 2;
        no1 = 10*no1+m1%10;
        m1 /= 10;
    }

    int m2 = no2;
    no2 = 0;

    while(m2 != 0){
        digNo2++;
        pow2 *= 2;
        no2 = 10*no2+m2%10;
        m2 /= 10;
    }

    //pow2 to dolny zakres tworzonych masek -odpowiada liczbie 00011
    //pow2*pow1 - pow1 to gorny zakres tworzonych masek - odpowiada liczbie 11000

    //cout<<pow2<<endl;
    //cout<<pow2*pow1 - pow1<<endl;

    int j, k, counterOf1, number, counter, primeCounter=0;
    for(int i=pow2-1; i<=pow2*pow1 - pow1; i++){
        //pomijanie tych wartosci i, dla ktorych ilosc jednek jest inna niz digNo2
        k=i;
        counterOf1 = 0; //licznik jedynek
        while(k!=0){
            if(k%2 == 1) counterOf1++;
            k/=2;
        }
        if(counterOf1 - digNo2 != 0) continue; //pominiecie tych masek, dla ktorych nie zgadza sie liczba jedynek

        j=i;
        m1 = no1;
        m2 = no2;
        number = 0;
        counter = digNo1+digNo2;
        while(counter != 0){
            if(j%2 == 0){
                number = number*10 + m1%10;
                m1/=10;
            }
            else{
                number = number*10 + m2%10;
                m2/=10;
            }
            j/=2;
            counter--;
        }
        //cout<<number<<endl;
        if(isPrime(number)) primeCounter++;
    }

    cout<<primeCounter<<endl;

    return 0;
}
