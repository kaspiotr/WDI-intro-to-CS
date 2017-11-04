//author: @kaspiotr (Piotr Kasprzyk)

/*
9. Sprawdzanie czy liczba naturalna jest palindromem, a następnie czy jest palindromem w systemie dwójkowym.
 */

#include <iostream>

using namespace std;

//funkcja odwracajaca podana liczbe
int reverse(int m){
    int p=m;
    int pos=1;

    while(p != 0){
        pos*=10;
        p/=10;
    }
    pos/=10;

    int reversed=0, digit;
    while(m != 0){
        digit = m%10;
        reversed+=digit*pos;
        pos/=10;
        m/=10;
    }

    return reversed;
}

//funckja zapisujaca poddana liczbe dziesiatkowa w systemie dwojkowym
int dec2bin(int m){
    int rest, result=0, pos=1;

    while(m != 0){
        rest=m%2;
        result+=pos*rest;
        pos*=10;
        m/=2;
    }

    return result;
}

int main(){
    int n;
    cin>>n;

    if(n == reverse(n)) cout<<"Podana liczba jest palindromem"<<endl;
    else cout<<"Podana liczba nie jest palindromem"<<endl;

    int bin = dec2bin(n);

    if(bin == reverse(bin)) cout<<"Podana liczba jest palindromem w systemie dwojkowym"<<endl;
    else cout<<"Podana liczba nie jest palindromem w systemie dwojkowym"<<endl;

    return 0;
}