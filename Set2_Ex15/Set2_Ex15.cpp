//author: @kaspiotr (Piotr Kasprzyk)

/*
15. Liczba Smitha to taka, której suma cyfr jest równa sumie cyfr wszystkich liczb występujących w jej rozkładzie na
czynniki pierwsze. Na przykład: 85=5*17, 8+5=5+1+7. Napisać program wypisujący liczby Smitha mniejsze od 1000000.
 */

#include <iostream>

using namespace std;

const int N=1000000;

int main(){

    bool sitoE[N];

    for(int i=0; i<N; i++) sitoE[i]=true;
    sitoE[0]=false;
    sitoE[1]=false;

    for(int i=2; i*i<=N; i++){
        if(sitoE[i]){
            for(int j=i*i; j<=N; j+=i)
                sitoE[j]=false;
        }
    }

    int j, div, k, digSum, PFSum; //PFSum -suma cyfr czynnikow pierwszych liczby

    for(int i=2; i<N; i++){
        digSum=0, PFSum=0;
        j=i;
        while(j != 0){
            digSum+=j%10;
            j/=10;
        }
        j=i;
        div=2;
        while(j>1){
            if(j%div == 0 && sitoE[div]){
                k=div;
                while(k!=0){
                    PFSum+=k%10;
                    k/=10;
                }
                j/=div;
            }
            else div++;
        }

        if(digSum == PFSum) cout<<i<<endl;
    }

    return 0;
}