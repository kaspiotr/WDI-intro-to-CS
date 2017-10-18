/*
14. Napisać program wyznaczający pierwiastek kwadratowy ze wzoru Newtona
 */

/*
Wzor Newtona:
x1 = 1
x(k+1)=(1/2)*(x(k)+a/x(k))
 */

#include <iostream>

using namespace std;

const double E=10e-3;

int main(){
    double sqr, a, b;
    cin>>sqr;

    a=1, b=2;

    while(b-a<-E || b-a>E){ //zamiast while(fabs(b-a)>E)
        b=a;
        a=(sqr/b+b)/2;
    }

    cout<<a<<endl;

    return 0;
}