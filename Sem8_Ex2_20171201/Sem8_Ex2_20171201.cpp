//author: @kaspiotr (Piotr Kasprzyk)

/*
Mamy dana liczbe naturalna i chcemy wypisac wszystkie mozliwosci zapisu tej liczby jako sumy skladnikow liczb
naturalnych. Np. dla liczby 4 program powinien wypisac:
1+1+1+1
1+1+2
2+2
1+3
4
*/

#include <iostream>
#include <string>

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

void skladniki(int n, int p, string wynik){
    if(n == 0) cout<<wynik<<endl;

    for(int i=p; i<=n; i++) skladniki(n-i, i, wynik + " + " + iToa(i));
}

int main(){
    int number;
    cin>>number;

    skladniki(number, 1, "");
}