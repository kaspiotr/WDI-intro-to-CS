//author: @kaspiotr (Piotr Kasprzyk)

/*
10. Napisać program wyznaczający największy wspólny dzielnik 3 zadanych liczb.
*/

#include <iostream>

using namespace std;

int Euklides(int a, int b){
    while(a*b != 0){
        if(a>b) a=a%b;
        else b=b%a;
    }

    if(a == 0) return b;
    return a;
}

int main(){

    int a,b,c;
    cin>>a>>b>>c;

    int nwd = Euklides(a,b);

    cout<<Euklides(nwd,c)<<endl;

    return 0;
}
