//author: @kaspiotr (Piotr Kasprzyk)

/*
20. Napisać program wczytujący liczbę naturalną z klawiatury i rozkładający ją na iloczyn 2 liczb o najmniejszej
różnicy. Np. 30=5*6, 120=10*12.
*/

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int div1=1, div2=n;
    int div=2;

    int m=n;

    while(div <= n/div){
        if(m%div == 0){
            while(m%div==0) m/=div;

            //ostatnie wartosci tutaj podstawione, to bedzie nasz wynik
            div1=div;
            div2=n/div;
        }
        else{
            div++;
            m=n;
        }
    }

    cout<<div1<<"\t"<<div2<<endl;

    return 0;
}

