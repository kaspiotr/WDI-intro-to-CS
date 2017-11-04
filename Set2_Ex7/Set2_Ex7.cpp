//author: @kaspiotr (Piotr Kasprzyk)

/*
7. Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy liczba ta zawiera cyfrę równą
liczbie swoich cyfr.
 */

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int m = n, digNo = 0;

    while(m != 0){
        digNo++;
        m/=10;
    }

    int digit;
    while(n != 0){
        digit = n%10;
        if(digit == digNo){
            cout<<"TAK"<<endl;
            return 0;
        }
        n/=10;
    }

    cout<<"NIE"<<endl;
    return 0;
}
