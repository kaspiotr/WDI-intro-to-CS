//author: @kaspiotr (Piotr Kasprzyk)

/*
12. Dany jest ciąg określony wzorem: A(n+1) = (A(n)%2)*(3*A(n)+1)+(1-A(n)%2)*A(n)/2
Startując z dowolnej liczby naturalnej >1 ciąg ten osiąga wartość 1. Napisać program,
który znajdzie wyraz początkowy z przedziału 2-10000 dla którego wartość 1 jest
osiągalna po największej liczbie kroków.
*/

#include <iostream>

using namespace std;

int main(){

    int anMax = 2;
    int steps = 0;
    int stepsMax = 0;
    int an;

    for(int a1=2; a1<=10000; a1++){
        steps = 0;
        an=a1;

        while(an != 1){
            an = (an%2)*(3*an+1)+(1-an%2)*an/2;
            steps++;
        }

        if(stepsMax<steps){
            stepsMax = steps;
            anMax = a1;
        }
    }

    cout<<"a1="<<anMax<<", bo po: "<<stepsMax<<" krokach"<<endl;

    return 0;
}

