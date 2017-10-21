//author: @kaspiotr (Piotr Kasprzyk)

/*
1. Napisać program generujący elementy ciągu Fibonaciego mniejsze od miliona.
 */

#include <iostream>

using namespace std;

const int N = 1000000;

int main(){

    int F1=1, F2=1, F3;

    while(F1<N){
        cout<<F1<<endl;

        F3 = F1 + F2;
        F1 = F2;
        F2 = F3;
    }

    return 0;
}

