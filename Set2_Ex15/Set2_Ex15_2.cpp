//15. Liczba Smitha to taka, której suma cyfr jest równa sumie cyfr wszystkich liczb występujących w jej rozkładzie na
//czynniki pierwsze. Na przykład: 85=5*17, 8+5=5+1+7. Napisać program wypisujący liczby Smitha mniejsze od 1000000.
#include <iostream>

using namespace std;
const int N =100;

int scyfr(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
  // cout<<sum<<" ";
    return sum;

}

int sczynniki(int n){
    int tmp=n;
    int k=2;
    int sum=0;
    while(tmp*tmp>=k && tmp>1){
            while(tmp%k==0){
           //   cout<<k<<" "<<endl;
                sum+=scyfr(k);
//              while(tmp%k==0)
                tmp/=k;
            }

            k++;
    }
  //  cout<<sum<<" ";
    return sum;
}
bool isPrime(int a){
    if(a <= 1) return false;
    if(a%2 == 0){
        if(a == 2) return true;
        else return false;
    }

    int div = 3;
    while(div*div <= a){
        if(a%div == 0){
            if(a == div) return true;
            else return false;
        }
        else div+=2;
    }

    return true;
}

int main(){

        for(int i=1;i<N;i++)
        if(!isPrime(i)&&sczynniki(i)==scyfr(i))
                    cout<<"i: "<<i<<endl;
        //cout<<sczynniki(27)<<"  "<<scyfr(27)<<endl;
}
