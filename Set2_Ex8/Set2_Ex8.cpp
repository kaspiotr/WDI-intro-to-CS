//author: @kaspiotr (Piotr Kasprzyk)

/*
8. Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy liczba zakończona jest
unikalną cyfrą.
 */

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int lastDig;
    bool found = false; //flaga do zapisania ostatniej cyfry, bo odcinamy od cyfry jednoci poczawszy

    int digs[10];

    for(int i=0; i<10; i++) digs[i]=0;

    while(n != 0){
        if(!found){
            lastDig = n%10;
            found = true;
        }
        digs[n%10]++;
        n/=10;
    }

    if(digs[lastDig] == 1) cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;

    return 0;
}
