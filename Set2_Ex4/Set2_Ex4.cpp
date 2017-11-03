//author: @kaspiotr (Piotr Kasprzyk)

/*
4.Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy liczba ta jest wielokrotnością
dowolnego wyrazu ciągu danego wzorem A(n)=3*A(n-1)+1, a pierwszy wyraz jest równy 2.
 */

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int a1 = 2, a2;

    while(a1 < n){
        cout<<a1<<endl;
        if(n%a1==0){
            cout<<"Podana liczba jest wielokrotnoscia wyrazu ciagu"<<endl;
            return 0;
        }

        a2 = 3*a1 + 1;
        a1 = a2;
    }

    cout<<"Podana liczba nie jest wielokrotnoscia wyrazu ciagu"<<endl;
    return 0;
}