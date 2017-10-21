//author: @kaspiotr (Piotr Kasprzyk)

/*
19. Napisać program obliczający wartości cos(x) z rozwinięcia w szereg Maclaurina.
*/

/*
 * Rozwiniecie funckji cos(x) w szereg Maclaurina ma postac:
 *
 * cos(x) = 1 - x^2/2! + x^4/4! - ...
 */
#include <iostream>

using namespace std;

const int E = 10e-3;

int main(){

    double x;
    cin>>x; //wartosc, dla ktorej bedzie liczona funckja cosx

    int sign = -1; //znak koleojnego wyrazu w sumie szeregu Maclaurina
    int i = 2;//najwiekszy czynnik iloczynu mianownika skladnika sumy szeregu rozpatrywanego w danej iteracji
    int derivative = 2;//mianownik skladnika sumy (wyrazu) szeregu Maclaurina rozpatrywany w danej iteracji
    int numerator = x*x; //licznik skladnika sumy szeregu rozpatrywanego w danej iteracji


    double prevCosx = 1;
    double cosx = prevCosx + sign*numerator/derivative;

    while(cosx - prevCosx < -E || cosx - prevCosx > E){
        prevCosx = cosx;
        sign*=-1;
        numerator*=(x*x);
        i++;
        derivative*=i;
        i++;
        derivative*=i;

        cosx +=(sign*numerator/derivative);
    }

    cout<<cosx<<endl;

    return 0;
}
