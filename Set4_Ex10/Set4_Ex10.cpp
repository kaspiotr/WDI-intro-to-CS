//author: @kaspiotr (Piotr Kasprzyk)

/*
10. Dana jest tablica int t[MAX][MAX][MAX]. Proszę napisać funkcję, do której przekazujemy tablicę wypełnioną
liczbami większymi od zera. Funkcja powinna zwracać wartość True, jeżeli na wszystkich poziomach tablicy
liczba elementów sąsiadujących (w obrębie poziomu) z co najmniej 6 liczbami złożonymi jest jednakowa albo wartość False
w przeciwnym przypadku.
MAX jest zdefiniowaną stałą.
*/

#include <iostream>
#include <math.h>

using namespace std;

const int MAX = 4;

bool isPrime(int a){
    if(a<=1) return false;
    if(a%2 == 0){
        if(a == 2) return true;
        else return false;
    }

    int div = 3;
    while(div <= sqrt(a)){
        if(a%div == 0){
            if(a == div) return true;
            else return false;
        } else div += 2;
    }

    return true;
}

int howManyComplexNeighbours(int t[MAX][MAX][MAX], int i, int j, int k){

    int dy[]={-1, 0, 1, 1, 1, 0, -1, -1};
    int dx[]={-1,-1,-1, 0, 1, 1, 1, 0};

    int neighbours = 0;

    for(int m=0; m<8; m++){
        if(!isPrime(t[i][j+dx[m]][k+dy[m]])) neighbours++;
    }

    return neighbours;
}


//funckja sprawdzajaca czy na wszystkich poziomach jest taka sama liczba elemetow sasiadujacych z 6-cioma
//liczbami zlozonymi
bool isInEveryLevelTheSameNoOfEls(int t[MAX][MAX][MAX]){

    //tablica lvls bedzie przechowywac ilosc elementow sasiadujacych z 6-cioma elementami zlozonymi
    //pod indeksem, ktory bedzie rowny poziomowi na ktorym sa te elementy
    int lvls[MAX];

    for(int i=0; i<MAX; i++) lvls[i]=0;

    //iterowanie po poziomach
    for(int i=0; i<MAX; i++){

        //iterowanie po kolumnach w kazdym z poziomow
        //od 1 do MAX-1, bo nie ma mozliwosci zeby na brzegach poziomu jakis element mial 6-ciu sasiadow
        for(int j=1; j<MAX-1; j++){

            //iterowanie po elementach w kazdej z kolumn
            //od 1 do MAX-1, bo nie ma mozliwosci zeby na brzegach poziomu jakis element mial 6-ciu sasiadow
            for(int k=1; k<MAX-1; k++){
                if(howManyComplexNeighbours(t, i, j, k) >= 6) lvls[i]++;
            }
        }
    }

    int val = lvls[0];
    for(int i=1; i<MAX; i++){
        if(val != lvls[i]){
            return false;
        }
    }

    return true;

}

int main(){

    //inicjalizacja tablicy testowej

    srand(time(NULL));
    int tab[MAX][MAX][MAX];
    int number;

    //wypelnienie tablicy 3D liczbami pierwszymi
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            for(int k=0; k<MAX; k++){
                number = rand() % 100;
                while(!isPrime(number)) number = rand() % 100;
                tab[i][j][k] = number;
            }
        }
    }


    //przyklad dla jednego elementu w kazdym z poziomow
    //ustalenie elementow sasiadujacych w poziomach
    //poziom 0: element tab[0][2][2] -6-ciu sasiadow zlozonych:
    tab[0][2][1] = 4;
    tab[0][1][2] = 22;
    tab[0][1][3] = 15;
    tab[0][2][3] = 6;
    tab[0][3][3] = 10;
    tab[0][3][2] = 35;

    //poziom 1: element tab[1][1][2] -6-ciu sasiadow zlozonych:
    tab[1][0][1] = 4;
    tab[1][1][1] = 22;
    tab[1][2][1] = 15;
    tab[1][0][3] = 6;
    tab[1][1][3] = 10;
    tab[1][2][3] = 35;

    //poziom 2: element tab[2][2][1] -6-ciu sasiadow zlozonych:
    tab[2][1][2] = 4;
    tab[2][2][2] = 22;
    tab[2][3][2] = 15;
    tab[2][3][1] = 6;
    tab[2][3][0] = 10;
    tab[2][2][0] = 35;
/*
    //poziom 3: element tab[3][1][1] -6-ciu sasiadow zlozonych:
    tab[3][0][2] = 4;
    tab[3][0][1] = 22;
    tab[3][0][0] = 15;
    tab[3][1][0] = 6;
    tab[3][2][0] = 10;
    tab[3][2][1] = 35;
*/
    cout<<isInEveryLevelTheSameNoOfEls(tab)<<endl;

    return 0;
}

