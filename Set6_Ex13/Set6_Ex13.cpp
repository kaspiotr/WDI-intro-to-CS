
// to zadanie jest głupie, bo skoro mamy dokonać tylko 7 ruchów aby dotrzeć do 7 wiersza, tak naprawdę poruszamy się tylko po kolumnie w dół
// to zadanie miałoby sens dla uniwersalnych danych, ale jakby co to działa :P

#include <iostream>
using namespace std;
const int MAX =8;
void ruchy(int t[8][8],int w, int k, int n, int &min_koszt,int koszt){
    if(w==7 && n==7){
            cout<<koszt<<" w: "<<w<<" k: "<<k<<" n: "<<n<<endl;
        if(koszt<min_koszt){
            min_koszt=koszt;
        }
    }
    if(w<8 && k<8 && n<7){
        ruchy(t,w+1,k,n+1,min_koszt,koszt+t[w+1][k]);
        ruchy(t,w,k+1,n+1,min_koszt,koszt+t[w][k+1]);
    }

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
    int w=0;
    int k=1;

    int t[8][8]={1,1,1,1,1,1,1,1,
                 1,2,2,2,2,2,2,2,
                 1,3,3,3,3,3,3,3,
                 1,4,4,4,4,4,4,4,
                 1,2,2,2,2,2,2,2,
                 1,2,2,2,2,2,2,2,
                 1,6,6,6,6,6,6,6,
                 500,9,9,9,9,9,9,9};
    int min_koszt=10000000;
    int koszt=t[w][k];
    ruchy(t,w,k,0,min_koszt,koszt);
    cout<<min_koszt<<endl;
    print2DTab(t);
}
