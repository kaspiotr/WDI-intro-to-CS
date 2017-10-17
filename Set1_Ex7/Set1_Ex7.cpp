/*
7. Napisać program sprawdzający czy zadana liczba jest pierwsza.
*/

#include <iostream>

using namespace std;

bool isPrime(int a){
    if(a <= 1) return false;
    if(a%2 == 0){
        if(a==2) return true;
        if(a!=2) return false;
    }
    int div = 3;

    while(div*div <= a){
        if(a%div == 0){
            if(a == div) return true;
            if(a != div) return false;
        }
        else div += 2;
    }

    return true;
}

int main(){

    int n;
    cin>>n;

    bool result = isPrime(n);

    if(result == true) cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;

    return 0;
}
