#include <iostream>
#include <cstdlib>

using namespace std;

const int N = 10;

bool isPrime(int n){

  if(n<2) return false;
  for(int i=2;i*i<=n;i++)
    if(n%i==0) return false;
  return true;
}

int in7BaseSys_digit_sum(int a){
    int b=a;
    int sum=0;
    while(b>0){
        sum+=b%7;
        b/=7;
    }
    return sum;
}


int doesItOccur(int tab[], int n){

    bool czy_pierwsza=false;
    int suma=0;
    int licznik_prawdy=0;
    for(int i=0;i<n ;i++){
        if(!isPrime(i))
            suma+=in7BaseSys_digit_sum(tab[i]);

    }
    return suma;
}


int main(){
    //           0, F, F, F, 4, F, 6, 7, F, 9,10,11,12, F
    int tab1[]={ 7, 4, 6, 8,12,16, 6, 8,34, 4}; //->tak
    int tab2[]={ 1, 2, 3, 5, 4, 7, 8,13,14,15}; //->nie
    int tab3[]={ 1, 4, 6, 8,12,16, 6, 8,34, 4}; //->nie
    int n=4;

    int tab[]={13,14,15,16};
    cout<<doesItOccur(tab,n)<<endl;
    cout<<doesItOccur(tab1,N);
    return 0;
}
