/*11. Napisać funkcję, która dla tablicy int t[MAX] wypełnionej liczbami naturalnym wyznacza
długość najdłuższego, spójnego podciągu arytmetycznego*/
#include <iostream>
using namespace std;
const int MAX= 20;


int art(int t[MAX]){
    int max1=1;
    //int maxgeo2=1;
    int len=2;
    double pot=t[1]-t[0];
    for(int i=2;i<MAX;i++){
        if(t[i-1]+pot==t[i]) len++;

        else{
               max1=max(max1,len);
             //   cout<<" "<<pot<<endl;
            pot=t[i]-t[i-1];
            len=2;
        }
    }

     max1=max(max1,len);
    return max1;
}

int main(){
    int t[MAX]={1,1,1,3,6,9,12,15,625,125,25,5,1,0,4,8,16,32,64,128};
    cout<<art(t)<<endl;


}
