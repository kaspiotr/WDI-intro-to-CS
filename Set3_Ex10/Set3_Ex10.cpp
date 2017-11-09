/*10. Napisać funkcję, która dla tablicy int t[MAX] wypełnionej liczbami naturalnym wyznacza długość
najdłuższego, spójnego podciągu rosnącego.
MAX jest zdefiniowaną stałą.*/
#include <iostream>
using namespace std;
const int MAX= 20;


int roz(int t[MAX]){
    int maxgeo1=1;

    int len=1;

    for(int i=1;i<MAX;i++){
        if(t[i-1]<t[i]) len++;

        else{
            max1=max(max1,len);
            len=1;
        }
    }

     max1=max(max1,len);
    return max1;
}

int main(){
    int t[MAX]={1,1,1,3,9,27,81,1025,625,125,25,5,1,3,4,8,16,32,64,128};
    cout<<roz(t)<<endl;


}
