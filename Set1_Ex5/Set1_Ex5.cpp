//author: @kaspiotr (Piotr Kasprzyk)

/*
5. Napisać program obliczający pierwiastek całkowitoliczbowy z liczby naturalnej
korzystając z zależności 1+3+5+... = n^2.
 */

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int i=1;
    while(n>=0){
        n-=i;
        i+=2;
    }
    cout<<((i-1)/2)-1;

    return 0;
}
