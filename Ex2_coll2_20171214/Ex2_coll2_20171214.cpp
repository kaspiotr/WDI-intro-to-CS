//author: @kaspiotr (Piotr Kasprzyk)

/*
Dana jest tablica int t[N], gdzie N%2==0. Napisac funckje, ktora stwierdzi czy mozliwy jest podzial elementow tej
tablicy na dwa rownoliczne zbiory o takiej samej sumie elementow.
*/

#include <iostream>

using namespace std;

const int N = 10;

bool inTwoSetsRec(int t[N], int setNo[N], int idx, int set1Size, int set2Size){
    if(idx == N){
        if(set1Size == set2Size){
            int sum1=0, sum2 = 0;

            for(int i=0; i<N; i++){
                if(setNo[i]==1) sum1 += t[i];
                if(setNo[i]==2) sum2 += t[i];
            }

            if(sum1 == sum2) return true;
            return false;
        } else return false;
    }

    bool result;
    setNo[idx] = 1;
    result = inTwoSetsRec(t, setNo, idx+1, set1Size+1, set2Size);
    if(result) return true;
    setNo[idx] = 2;
    result = inTwoSetsRec(t, setNo, idx+1, set1Size, set2Size+1);
    if(result) return true;
    setNo[idx]=0;

    return false;
}

bool inTwoSets(int t[N]){
    int setNo[N];
    for(int i=0; i<N; i++) setNo[i]=0;
    bool result;
    setNo[0] = 1; int set1Size=0, set2Size =0;
    result = inTwoSetsRec(t, setNo, 0, set1Size+1, set2Size);
    if(result) return true;
    setNo[0] = 2;
    result = inTwoSetsRec(t, setNo, 0, set1Size, set2Size);
    if(result) return true;
    setNo[0]=0;
    return false;
}


int main(){

    int tab1[]={31,10,12, 2,18, 8,15,11, 9, 4};
    int tab2[]={100,200,300,400,500,1,2,3,4,5};

    cout<<inTwoSets(tab1)<<endl;
    cout<<inTwoSets(tab2)<<endl;

    return 0;
}



