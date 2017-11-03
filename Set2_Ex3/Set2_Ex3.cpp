//author: @kaspiotr (Piotr Kasprzyk)

/*
3. Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy liczba ta jest
wielokrotnością dowolnego wyrazu ciągu danego wzorem A(n)=n*n+n+1.
 */

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int an;
    for(int i=1; an<=n; i++){
        an = i*i+i+1;
        //cout<<an<<endl;

        if(n%an == 0){
            cout<<"TAK"<<endl;
            return 0;
        }
    }

    cout<<"NIE"<<endl;

    return 0;
}
