//author: @kaspiotr (Piotr Kasprzyk)

/*
5.Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy jej cyfry stanowią ciąg
rosnący.
 */

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    if(n/10 == 0){
        cout<<"Liczba musi miec co najmniej dwie cyfry!"<<endl;
        return 0;
    }
    int digit1, digit2;

    while(n > 0){
        digit1 = n%10;
        n/=10;
        digit2 = n%10;
        if(digit1 <= digit2){ //">=" a nie "<=" bo przegladamy cyfry od cyfry jednosci poczawszy
            cout<<"Cyfry podanej liczby nie stanowia ciagu rosnacego"<<endl;
            return 0;
        }
    }

    cout<<"Cyfry podanej liczby stanowia ciag rosnacy"<<endl;
    return 0;
}