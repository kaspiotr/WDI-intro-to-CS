//author: @kaspiotr (Piotr Kasprzyk)

/*
2. Napisać program wczytujący dwie liczby naturalne i odpowiadający na pytanie czy są one
zbudowane z takich samych cyfr, np. 123 i 321, 1255 i 5125, 11000 i 10001.
 */

#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;

    int *digs = new int [10];

    for(int i=0; i<10; i++) digs[i]=0;

    while(a != 0){
        digs[a%10]++;
        a/=10;
    }

    while(b != 0){
        digs[b%10]--;
        b/=10;
    }

    for(int i=0; i<10; i++){
        if(digs[i] != 0){
            cout<<"NIE"<<endl;
            delete [] digs;
            return 0;
        }
    }

    cout<<"TAK"<<endl;
    delete [] digs;
    return 0;
}
