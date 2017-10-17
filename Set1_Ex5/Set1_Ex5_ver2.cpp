/*
5. Napisać program obliczający pierwiastek całkowitoliczbowy z liczby naturalnej
korzystając z zależności 1+3+5+... = n^2.
 */

#include <iostream>

using namespace std;

int main(){
    int number, sqr, sum, el;
    cin>>number;

    sqr = 0, sum = 0; el = 1;

    while(sum <= number){
        sum += el;
        el += 2;
        sqr += 1;
    }

    cout<<sqr-1<<endl;

    return 0;
}


