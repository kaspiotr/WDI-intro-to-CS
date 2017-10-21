//author: @kaspiotr (Piotr Kasprzyk)

/*
16. Napisać program rozwiązujący równanie x^x^x=2017 metodą bisekcji.
 */

#include <iostream>
#include <cmath>

using namespace std;

const double E=0.001;

double f(double x){
    return exp(x*x*log(x))-2017;
}

int main(){
    double a=2, b=3; //wartosci poczatku i konca przedzialu [a,b] odczytujemy z wykresu funkcji f(x)=x^x^x-2017
    while(fabs(b-a)>E){
        if(f(a)*f(b)<0){
            if(f(a)*f((a+b)/2)<0){
                b=(a+b)/2;
            }

            if(f((a+b)/2)*f(b)<0){
                a=(a+b)/2;
            }
        }
        else{
            cout<<"Funckja nie spelnia warunkow zadania!"<<endl;
            break;
        }
    }
    cout<<(a+b)/2<<endl;

    return 0;
}