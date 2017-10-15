/*
Napisac program, ktory sprawdza czy podana liczba jest rowna sumie
elementow spojnego podciagu wyrazow ciagu Fibonnacciego.

Przykladowo dla liczby 42 program powinien zwrocic 'TAK', bo
42 = 8+13+21
 */

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int p1=1, p2=1, p3;
    int k1=1, k2=1, k3;
    int sum=0;

    while(sum != n && k1 <=n){
        if(sum<n){
            sum += k1;
            k3=k1+k2;
            k1=k2;
            k2=k3;
        }

        if(sum>n){
            sum -= p1;
            p3=p2+p1;
            p1=p2;
            p2=p3;
        }
    }

    //cout<< (sum==n) <<endl; //wtedy program zwraca 0 lub 1
    if(sum == n){
        cout<<"TAK"<<endl;
        //cout<<p1<<" "<<k1<<endl;
    }
    else cout<<"NIE"<<endl;

    return 0;
}