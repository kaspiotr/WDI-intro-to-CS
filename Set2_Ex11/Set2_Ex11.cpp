//author: @kaspiotr (Piotr Kasprzyk)

/*
11. Napisać program, który wyznacza ostatnia niezerową cyfre N! Program powinien działać dla N rzędu 1000000.
 */

#include <iostream>

using namespace std;

int main(){

    int noOf2 = 0; //zmienna, ktora bedzie przechowywac ilosc dwojek w rozkladzie na czynniki pierwsze liczby N
    int noOf5 = 0; //zmienna, ktora bedzie przechowywac ilosc piatek w rozkladzie na czynniki pierwsze liczby N

    int n;
    cin>>n;

    if(n==0 || n==1){ //bo inaczej wyswietli sie 6 (jedyne dwa wyjatki od reguly)
        cout<<"1"<<endl;
        return 0;
    }

    int lastDig = 1;
    int whichOptOf2Pow; //zmienna, ktora bedzie przechowywac nr jednej z opcji na jaka moze sie zakonczyc potega
                        //liczby 2 (opcja 1: cyfra 2, opcja 2: cyfra 4, opcja 3: cyfra 8, opcja 0: cyfra 6)

    int j;
    for(int i=2; i<=n; i++){
        j=i;

        while(j%2 ==  0){
            noOf2++;
            j/=2;
        }

        while(j%5 == 0){
            noOf5++;
            j/=5;
        }

        //zapamietuje ostatnia niezerowa cyfre
        lastDig = (lastDig*(j%10))%10;
    }

    //sprawdzamy o ile jest wiecej 2 niz 5 w rozkladzie liczby na czynniki pierwsze
    //i sprawdzamy, ktora z 4-ech mozliwosci wustepuje (4-ech bo dowolna potega liczby 2
    //ma cyfre jednosci rowna 2,4,8,6 (cyfre 0 rozwazylismy wczesniej), ktore to cyfry powtarzaja
    //sie w cyklu (2,4,8,6)
    whichOptOf2Pow = (noOf2-noOf5)%4;

    if(whichOptOf2Pow == 1) lastDig *= 2;
    if(whichOptOf2Pow == 2) lastDig *= 4;
    if(whichOptOf2Pow == 3) lastDig *= 8;
    if(whichOptOf2Pow == 0) lastDig *= 6;

    lastDig %= 10;

    cout<<lastDig<<endl;

    return 0;
}