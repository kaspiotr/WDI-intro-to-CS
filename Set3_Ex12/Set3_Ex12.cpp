/*12. Napisać funkcję, która dla tablicy int t[MAX] wypełnionej liczbami naturalnym wyznacza długość
najdłuższego, spójnego podciągu geometrycznego.
MAX jest zdefiniowaną stałą.*/
#include <iostream>
using namespace std;
const int MAX= 20;


int geo(int t[MAX]){
    int maxgeo1=1;
    int maxgeo2=1;
    int len=2;
    double pot=t[1]-t[0];
    for(int i=2;i<MAX;i++){
        if(t[i-1]*pot==t[i]) len++;

        else{
            if(pot>1){

                maxgeo1=max(maxgeo1,len);
             //   cout<<" "<<pot<<endl;
            }
            if(pot<1){
                maxgeo2=max(maxgeo2,len);
             //   cout<<" "<<pot<<endl;
            }
            if(t[i-1]!=0)//zeby nie dzielic przez 0
            pot=t[i]/t[i-1];
            len=2;
        }
    }
     if(pot>1) maxgeo1=max(maxgeo1,len);
     if(pot<1) maxgeo2=max(maxgeo2,len);
     maxgeo1=max(maxgeo1,maxgeo2);
    return maxgeo1;
}

int main(){
    int t[MAX]={1,1,1,3,9,27,81,1025,625,125,25,5,1,0,4,8,16,32,64,128};
    cout<<geo(t)<<endl;


}
