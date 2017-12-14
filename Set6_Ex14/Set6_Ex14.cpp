#include <iostream>
using namespace std;
const int MAX =8;
//skoro nie mogę oddalać się od celu, nie mogę wykonywać ruchów
//takich jak ruch w lewo, w górę i pokrewnych
// z tego wynika że mogę wykonywać ruchy: w dól, w prawo i prawo-dół

bool ruch(int t[8][8],int w,int k,int w1,int k1){
     if(w1<8 && w1 >0 &&k1<8 && k1>0){
      int a = t[w1][k1];
      int c = a;
      while(a>0){
        c=a%10;
        a/=10;
      }

      if(t[w][k]%10 <c)
        return true;

    }
     return false;
}


bool naroznik(int t[8][8],int w, int k){
    if(w==7 && k==7){
        return true;
    }

    if(ruch(t,w,k,w+1,k+1)) naroznik(t,w+1,k+1);
    if(ruch(t,w,k,w+1,k)) naroznik(t,w+1,k);
    if(ruch(t,w,k,w,k+1)) naroznik(t,w,k+1);


}

void print2DTab(int tab[MAX][MAX]){
    int row, col;

    for(int i=0; i<MAX*MAX; i++){
        row = i/MAX;
        col = i%MAX;

        cout<<tab[row][col]<<"\t";
        if(col == MAX-1) cout<<endl;
    }
    cout<<endl;
}

int main() {


    int t[8][8]={1,1,1,1,1,1,1,1,
                 1,2,2,2,2,2,2,2,
                 1,3,3,3,3,3,3,3,
                 1,4,4,4,4,4,4,4,
                 1,2,2,2,2,2,2,2,
                 1,2,2,2,2,2,2,2,
                 1,6,6,6,6,6,6,6,
                 500,9,9,9,9,9,89,29};
    if(naroznik(t,7,6)) cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;                     //nie można bo 89%10>2 

        int t1[8][8]={1,1,1,1,1,1,1,1,
                 1,2,2,2,2,2,2,2,
                 1,3,3,3,3,3,3,3,
                 1,4,4,4,4,4,4,4,
                 1,2,2,2,2,2,2,2,
                 1,2,2,2,2,2,2,2,
                 1,6,6,6,6,6,6,6,
                 500,9,9,9,9,9,81,9};
    if(naroznik(t1,7,6)) cout<<"TAK"<<endl; //TAK
    else cout<<"NIE"<<endl;
    
    


    //print2DTab(t);
}
