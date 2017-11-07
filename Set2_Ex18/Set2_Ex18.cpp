//auhtor: @kaspiotr (Piotr Kasprzyk)

/*
18. Napisać program wyliczający pierwiastek równania x^x=2017 metodą stycznych.
*/

#include <iostream>
#include <cmath>

using namespace std;

const double E=0.001;

double f(double x){
    return exp(log(x)*x)-2017;
}

int main(){
    double a=4, b=5;

    while(fabs(b-a)>E){
        if(f(a)*f(b)<0) {
            if (f(a) * f((a + b) / 2) < 0)
                b = (a + b) / 2;

            if (f((a + b) / 2) * f(b) < 0)
                a = (a + b) / 2;
        }
        else{
            cout<<"Funckja nie spelnia warunkow zadania!"<<endl;
            break;
        }
    }

    cout<<(a+b)/2<<endl;

    return 0;
}

