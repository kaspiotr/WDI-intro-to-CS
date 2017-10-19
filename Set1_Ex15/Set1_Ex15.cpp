/*
15. Zmodyfikować wzór Newtona aby program z poprzedniego zadania obliczał pierwiastek
stopnia 3.
*/

/*
Wzor Newtona do obliczania pierwiastka stopnia 3 z liczby:
x1 = 1
x(k+1)=(1/3)*(2*x(k)+a/x(k))
 */

#include <iostream>

using namespace std;

const double E=10e-3;

int main(){
    double sqr, a, b; //sqr -liczba z ktorej obliczamy pierwiastek szescienny; a=x(k+1); b=x(k)
    cin>>sqr;

    a=sqr; //przyjmujemy, ze pierwszym przyblizeniem jest liczba pierwiastkowana
    b=2;

    while(b-a<-E || b-a>E){ //zamiast while(fabs(b-a)>E)
        b=a;
        a=(sqr/(b*b)+2*b)/3;
    }

    cout<<a<<endl;

    return 0;
}