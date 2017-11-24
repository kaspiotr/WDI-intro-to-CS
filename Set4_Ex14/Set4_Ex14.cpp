/*14. Dana jest tablica
int t[MAX][MAX],
wypełniona liczbami naturalnymi. Proszę napisać funkcję która odpowiada na pytanie, czy w tablicy każdy wiersz zawiera
co najmniej jedną liczbą złożoną wyłącznie z cyfr będących liczbami pierwszymi?
MAX jest zdefiniowaną stałą.*/


#include <iostream>

using namespace std;

const int MAX=3;

bool isPrime(int a){
    if(a <= 1) return false;
    if(a%2 == 0){
        if(a==2) return true;
        else return false;
    }
    if(a == 2) return true;
    int div = 3;
    while(div*div <= a){
        if(a%div == 0){
            if(a == div) return true;
            else return false;
        }
        else div+=2;
    }

    return true;
}

bool warunek(int t[MAX][MAX]){
        bool czyP=true;
        int l=0;
        int k;
        for(int i=0;i<MAX;i++){
            for(int j=0,k=0;j<MAX && k!=1;j++){  //k jest flaga
                    l=t[i][j];
                    cout<<l<<" ";
                    czyP=true;
                    while(l>0 && czyP){
                        if(!isPrime(l%10))
                            czyP=false;

                        l/=10;
                    }

                    if(czyP) k=1;  //jezeli znalezliśmy juz jakąs pasujaca liczbe to nie ma sensu szukac dalej w wierszu


        }

         if(!czyP) return false;

    }

    return true;

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

int main(){

    int t[MAX][MAX]={1,44,7,
                     22,5,1,
                     2,1,3};
    if(warunek(t)) cout<<"tak"<<endl;
    else cout<<"NIE"<<endl;
    print2DTab(t);
    int t1[MAX][MAX]={1,1,1,
                      3,8,-22,
                      4,10,1};
    if(warunek(t1)) cout<<"tak"<<endl;
    else cout<<"NIE"<<endl;
    print2DTab(t1);


   // cout<<isPrime(7)<<endl;
}
