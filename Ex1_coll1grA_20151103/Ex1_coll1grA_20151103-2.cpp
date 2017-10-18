#include <iostream>
using namespace std;

bool czy_pierwsza(int n){

    if(n<2)
    return false;

  for(int i=2;i*i<=n;i++)
    if(n%i==0)
      return false;
  return true;

}
//brzydszy sposób sprawdzania czy cyfra jest pierwsza,
bool isPrimeDigit(int d) {
    const int PRIMES[6] = {2, 3, 5, 7, 11, 13};
    for (int i = 0; i < 6; i++) {
        if (PRIMES[i] == d) {
            return true;
        }
    }
    return false;
}

bool czy_w_kazdym(int n){
    int podstawa=2;

    while(podstawa<=16){
             int allDigitsPrime=true;
        int tmp = n;
        while (tmp != 0 && allDigitsPrime) {
            allDigitsPrime = isPrimeDigit(tmp % podstawa);
            tmp /= podstawa;
        }
        if (allDigitsPrime) {
            return true;
        }
        podstawa++;
    }
    return false;
}

// zwraca true, jeśli liczba n spełnia warunki zadania
bool checkNumber(int n) {
    for (int base = 2; base <= 16; base++) {
        bool allDigitsPrime = true;
        int tmp = n;
        while (tmp != 0 && allDigitsPrime) {
            allDigitsPrime = isPrimeDigit(tmp % base);
            tmp /= base;
        }
        if (allDigitsPrime) {
            return true;
        }
    }
    return false;
}

int main(){
    int k;
    cin>>k;
    if(czy_w_kazdym(k))
        cout<<"TAAAK"<<endl;
   else
    cout<<"NIE"<<endl;
    if(checkNumber(k)){
        cout<<"TAAAK"<<endl;
    }
    else
    cout<<"NIE"<<endl;
}
