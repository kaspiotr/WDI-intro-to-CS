/*18. Dana jest tablica typu
int t[MAX][MAX]
wypełniona liczbami całkowitymi. Proszę napisać funkcję, która wyszuka spójny podciąg elementów leżący poziomo
lub pionowo o największej sumie. Maksymalna długość podciągu może wynosid 10 elementów. Do funkcji należy przekazać
tablicę typu tab, funkcja powinna zwrócić sumę maksymalnego podciągu.
MAX jest zdefiniowaną stałą.
*/


#include <iostream>
using namespace std;

//problem: możemy mieć ujemne wartosci , będzie ostro
const int MAX =4;
const int N =10; //max dlugosc podciagu

int sum(int t[MAX][MAX]){

    int sum_w=0;
    int sum_k=0;
    int max_sum=0;
    int sum1=0;
    int licznik=0; //nie moze przekroczyc 10;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
              //  cout<<"Ble"<<endl;
            for(int k=j;k<MAX && k <=10;k++){
                    sum_w+=t[i][k];
                    sum_k+=t[k][i];
              //      cout<<"ble"<<sum_w<<" "<<sum_k<<endl;

            }
             sum1=max(sum_w,sum_k);
            if(max_sum<sum1){
                max_sum=sum1;
            }
            sum_w=0;
            sum_k=0;

        }

    }
     return max_sum;

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

    int t[MAX][MAX]={-3,4,2,1,
                     -4,0,1,-2,
                     1,3,0,-1,
                     0,1,-2,-3,};
    print2DTab(t);
    cout<<sum(t)<<endl;
}
