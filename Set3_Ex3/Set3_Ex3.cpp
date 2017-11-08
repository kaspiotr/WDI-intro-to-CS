//author: @kaspiotr (Piotr Kasprzyk)

/*
3. Napisać program generujący i wypisujący liczby pierwsze mniejsze od N metodą Sita Eratostenesa
*/

#include <iostream>

using namespace std;

void sitoE(bool *E, int size){
    E[0]=false;
    E[1]=false;

    for(int i=2; i*i<size; i++)
        if(E[i])
            for(int j = i * i; j < size; j += i)
                E[j]=false;



}

int main(){
    int n;
    cin>>n;

    bool *E = new bool [n];

    for(int i=0; i<n; i++) E[i]=true;

    sitoE(E, n); //przesianie sita Erastotenesa

    for(int i=0; i<n; i++)
        if(E[i]) cout<<i<<endl;

    delete [] E;

    return 0;
}
