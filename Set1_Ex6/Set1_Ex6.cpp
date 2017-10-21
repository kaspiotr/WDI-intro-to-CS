//author: @kaspiotr (Piotr Kasprzyk)

/*
6. Napisać program wypisujący podzielniki liczby.
 */

#include <iostream>

using namespace std;

int main(){
    int n, div=1;
    cin>>n;

    while(n > div){
        if(n%div == 0){
            cout<<div<<"\t";
        }
        div += 1;
    }

    cout<<n<<endl;

    return 0;
}
