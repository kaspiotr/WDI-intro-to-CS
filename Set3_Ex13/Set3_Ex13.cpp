/*13. Proszę napisać program, który wypełnia tablicę t[N] pseudolosowymi liczbami nieparzystymi z
zakresu [1..99], a następnie Wyznacza i wypisuje różnicę pomiędzy długością najdłuższego
znajdującego się w niej ciągu arytmetycznego o dodatniej różnicy, a długością najdłuższego
ciągu arytmetycznego o ujemnej różnicy, przy założeniu, że kolejnymi wyrazami ciągu są
elementy tablicy o kolejnych indeksach.*/
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

const int N=20;

int diff(int t[N]){

    int maxMal=1;
    int maxRos=1;
    int roz=t[1]-t[0];
    int len=2;
    for(int i=2;i<N;i++){
        if(t[i-1]+roz==t[i]) len++;
        else{
            if(roz>0){
                maxRos=max(maxRos,len);
            }
            else if(roz<0) maxMal=max(maxMal,len);
            roz=t[i]-t[i-1];
            len=2;
        }
    }
    if(roz>0) maxRos=max(maxRos,len);
    else
    if(roz<0) maxMal=max(maxMal,len);
    return maxRos-maxMal;
}


int main(){
    int t[N];
    int k;
    srand(time(NULL));
    for(int i=0;i<N;i++){
        k=rand()%49+1;
        t[i]=2*k+1;
        cout<<t[i]<<endl;
    }
    cout<<diff(t)<<endl;
}
