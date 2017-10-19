/*
20. Dane są ciągi: A(n+1)=sqrt(A(n)*B(n)) oraz B(n+1)=(A(n)+B(n))/2.0
Ciągi te są zbieżne do wspólnej granicy nazywanej średnią arytmetyczno-geometryczną.
Napisać program wyznaczający średnią arytmetyczno-geometryczną dwóch liczb.
 */

#include <iostream>
#include <math.h>

using namespace std;

const int E = 10e-3;

int main(){
    double a, b;
    cin>>a>>b;

    double a1, b1;
    a1 = (a+b)/2.0;
    b1 = sqrt(a*b);

    double a2, b2;
    a2 = (a1+b1)/2.0;
    b2 = sqrt(a1*b1);

    while(a2-b2<-E || a2-b2>E){
        a1 = a2;
        b1 = b2;

        a2 = (a1+b1)/2.0;
        b2 = sqrt(a1*b1);
    }


    cout<<a2<<endl; //moze byc tez cout<<b2<<endl;

    return 0;
}