//author: @kaspiotr (Piotr Kasprzyk)

/*
11. Napisać program wyznaczający najmniejszą wspólną wielokrotność 3 zadanych liczb.
 */

#include <iostream>

using namespace std;

//algorytm Euklidesa obliczania NWD
int nwd(int a, int b){
    while(a*b != 0){
        if(a>b) a=a%b;
        else b=b%a;
    }

    if(a==0) return b;
    return a;
}

int main(){

    int a,b,c;
    cin>>a>>b>>c;

    /*
     * 1)NWW(a2,a3)=(a2*a3)/NWD(a2,a3)
     *
     * NWW(a1,a2,a3) = NWW(a1,NWW(a2,a3))
     *
     * 2)a1*NWW(a2,a3)=NWD(a1,NWW(a2,a3))*NWW(a1,NWW(a2,a3))
     *
     * 3)a1*NWW(a2,a3)=NWD(a1,NWW(a2,a3))*NWW(a1,a2,a3)
     *
     * NWW(a1,a2,...,an)=NWW(a1,NWW(a2,a3,...,an))
     */

    int nwdBC = nwd(b,c);
    int nwwBC = (b*c)/nwdBC; //z 1)

    int nwdAnwwBC = nwd(a,nwwBC);
    int nwwAnwwBC = (a*nwwBC)/nwdAnwwBC; //z 2)

    cout<<nwwAnwwBC<<endl; //bo 3)

    return 0;
}