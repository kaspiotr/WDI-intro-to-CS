
#include <iostream>
using namespace std;

int mostcommon(int t[], int n){
    int p,l,sz,max_=1,j=0;
    int licz_max=t[0];
    int pocz_l;
    l=0;p=n-1;sz=t[l];
    int sr;
    while(l<n-1){
        pocz_l=l;
        while(l<=p){
            sr=(l+p)/2;
            if(sz>=t[sr])
                l=sr+1;
            else
                p=sr-1;
        }
        j=p-pocz_l+1;
        if(max_<j){
            max_=j;
            licz_max=t[p];

        }
        p=n-1;
        sz=t[l];
        pocz_l=l;

    }
    return licz_max;

}

int main(){
    int tab[20]={0,0,0,0,1,1,1,1,1,2,2,2,3,3,3,3,3,3,7,7};
    cout<<mostcommon(tab,20)<<"<= wynik"<<endl;

}
