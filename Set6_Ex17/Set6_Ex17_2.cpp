#include <iostream>
#include <ctime>

using namespace std;

const int N = 6;

bool isPrime(int n) {

    if(n < 2)
        return false;

    if(n % 2 == 0 && n != 2) return false;
    for(int i = 3; i * i <= n; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

bool podziel(int t[], int i) {
    int a = t[i];
    for(int j = 1; j < min(N-i, 30); j++) {
        if(isPrime(a))
            if(podziel(t, i+j))
                return true;
        a *= 2;
        a += t[i + j];
    }
    if(N-i > 30) return false;
    return isPrime(a);
}

int main() {

    int t1[6]={1,1,1,0,1,1}; //TAK
    int t2[6]={1,1,0,1,0,0};//NIE

    cout << endl << podziel(t1, 0);
    cout << endl << podziel(t2, 0);
}
