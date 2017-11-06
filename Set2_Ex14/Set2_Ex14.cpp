//author: @kaspiotr (Piotr Kasprzyk)

/*
14. Napisać program znajdujący wszystkie liczby N-cyfrowe dla których suma N-tych potęg cyfr liczby jest równa tej
liczbie, np. 153=1^3+5^3+3^3.
 */

#include <iostream>

using namespace std;

//funckja podnoszaca liczbe n do potegi index
int pow(int n, int index){
    int result = 1;
    while(index != 0){
        result*=n;
        index--;
    }

    return result;
}

int main(){
    int n;
    cin>>n;

    int m=n, pos=1;

    while(m!=0){
        pos*=10;
        m--;
    }
    pos/=10;

    int max = pos*9;
    m=pos/10;


    while(m!=0){
        max+=m*9;
        m/=10;
    }
    m*=9;

    int j, sum;

    for(int i=pos; i<=max; i++){
        j=i;
        sum=0;

        while(j != 0){
            sum+=pow(j%10, n);
            j/=10;
        }

        if(i == sum) cout<<i<<endl;
    }

    return 0;
}