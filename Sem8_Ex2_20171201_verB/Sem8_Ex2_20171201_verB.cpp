//author: @kaspiotr (Piotr Kasprzyk)

/*
Mamy dana liczbe naturalna i chcemy wypisac wszystkie mozliwosci zapisu tej liczby jako iloczyny skladnikow liczb
naturalnych. Np. dla liczby 12 program powinien wypisac:
2*2*3
3*4
2*6
12
*/

#include <iostream>

using namespace std;

string iToa(int n){
    string r = "";
    while(n > 0){
        char digit = n%10 +'0';
        r = digit + r;
        n/=10;
    }

    return r;
}

void iloczyny(int n, int p, string wynik){
    if(n == 1) cout<<wynik<<endl;
    for(int i=p; i<=n; i++)
        if(n%i==0) iloczyny(n/i, i, wynik + " * " + iToa(i));
}

int main(){
    int number;
    cin>>number;

    iloczyny(number, 2, "1");

    return 0;
}