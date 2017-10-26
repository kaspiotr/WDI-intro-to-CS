//author: @kaspiotr (Piotr Kasprzyk)

/*
ad-wdi k2b, środa, 14 grudnia 2016

2. Dana jest tablica int t[N][N] (reprezentująca szachownicę) wypełniona liczbami naturalnymi.
W każdej kolumnie znajduje się dokładnie jedna wieża, której numer wiersza zawiera tablica
int w[N]. Proszę napisać funkcję która wybiera do usunięcia z szachownicy dwie wieże, tak aby
suma liczb na polach szachowanych przez pozostałe wieże była najmniejsza. Do funkcji należy
przekazać tablice t i w, funkcja powinna zwrócić numery kolumn z których usunięto wieże.
Uwagi:
- zakładamy, że wieża szachuje cały wiersz i kolumnę z wyłączeniem pola na którym stoi
- czas na rozwiązanie obu zadań wynosi 45 minut
- za każde zadanie można otrzymać maksymalnie 5 pkt
- oceniane będą: czytelność, poprawność i efektywność rozwiązań
 */

#include <iostream>

using namespace std;

const int N = 8;

int tab[N][N]={{1,1,1,9,1,9,1,1},
               {1,1,1,9,1,9,1,1},
               {9,9,9,9,9,9,9,9},
               {1,1,1,9,1,9,1,1},
               {9,9,9,9,9,9,9,9},
               {1,1,1,9,1,9,1,1},
               {1,1,1,9,1,9,1,1},
               {1,1,1,9,1,9,1,1}};

int w[N]   =   {0,1,3,2,5,4,6,7};

void eraseTwoTowers(int t[N][N], int w[N], int &col1, int &col2){

    int option; //flaga, ktora pozwala na odjecie odpowiedniej ilosci pol od ostatcznej sumy w zaleznosci od
    //trzech przypadkow wzajemnego ustawienia dwoch wiez w tablicy
    int currSumOf1 = 0; //zmianna mowiaca o biezacej wartosci sumy szachowanych pol przez jedna wieze
    int currSumOf2 = 0; //zmienna, mowiaca o biezacej wartosci sumy szachowanych pol przez dwie wieze
    int maxSumOf2 = 0; //maksymalna suma szchowanych pol przez dwie wieze w danej tablicy -na jej podstawie zostana
    //ustalone wspolrzedne dwoch wierz: row1, col1, row2, col2, ktore potem zwroci funckja
    //w zmiennej result

    for(int i=0; i<N-1; i++){

        currSumOf1=0;

        for(int k=0; k<N; k++){
            currSumOf1 += t[w[i]][k]+t[k][i];
        }

        currSumOf1 -= 2*t[w[i]][i]; //odejmujemy wartosc pola, na ktorym stoi wieza
                                    //(2* -bo wartosc zostala policzona 2 razy)

        //teraz biezemy pod uwage druga wieze
        for(int j=i+1; j<N; j++) {

            currSumOf2 = currSumOf1;

            for (int m = 0; m < N; m++) {
                if (w[i] == w[j]) { //przypadek, gdy wierze sa w tym samym wierszu
                    option = 1;
                    currSumOf2 += t[w[j]][m];
                }

                if (w[i] != w[j]) { //przypadek, gdy wierze nie sa w tym samym wierszu i kolumnie
                    option = 2;
                    currSumOf2 += t[w[j]][m] + t[m][j];
                }

                //przypadku, gdy wieze sa w tej samej kolumnie nie ma, bo tak wynika z tresci zadania
            }


            if (option == 1) {
                currSumOf2 -= t[w[j]][j];
            }

            if (option == 2) {
                currSumOf2 -= 2 * t[w[j]][j];
            }

            if (currSumOf2 > maxSumOf2) {
                maxSumOf2 = currSumOf2;
                col1 = i;
                col2 = j;
            }
        }
    }
}

int main(){

    int col1=0, col2=0;
    eraseTwoTowers(tab, w, col1, col2);

    cout<<col1<<"\t"<<col2<<endl;

    return 0;
}