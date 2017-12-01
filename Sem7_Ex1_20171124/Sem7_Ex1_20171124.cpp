//author: @kaspiotr (Piotr Kasprzyk)

/*
Napisac funckje rekurencyjna obliczajaca sume cyfr podanej liczby.
*/

#include <iostream>

using namespace std;

int sumRek(int n){
    if(n == 0) return 0;
    return n%10 + sumRek(n/10);
}

int main(){
    int number;
    cin>>number;

    cout<<sumRek(number)<<endl;

    return 0;
}

