//author: @kaspiotr (Piotr Kasprzyk)

/*
ad-wdi k2a, wtorek, 13 grudnia 2016
2. Dana jest tablica t[N][N] (reprezentująca szachownicę) wypełniona liczbami naturalnymi.
Proszę napisać funkcję która ustawia na szachownicy dwie wieże, tak aby suma liczb na
„szachowanych” przez wieże polach była największa. Do funkcji należy przekazać tablicę,
funkcja powinna zwrócić położenie wież.
Uwagi:
- zakładamy, że wieża szachuje cały wiersz i kolumnę z wyłączeniem pola na którym stoi
- czas na rozwiązanie obu zadań wynosi 45 minut
- za każde zadanie można otrzymać maksymalnie 5 pkt
- oceniane będą: czytelność, poprawność i efektywność rozwiązań
 */

#include <iostream>

using namespace std;

//struktura, dzieki ktorej fynckja zwroci cztery wartosci int opisujace szukane pozycje dwoch wiez
struct PosOf2Tow{
    int row1;
    int col1;
    int row2;
    int col2;
};

PosOf2Tow twoTowers(int **t, int N) {
    PosOf2Tow result; //zmianna, ktora zwroci funckja
    int option; //flaga, ktora pozwala na odjecie odpowiedniej ilosci pol od ostatcznej sumy w zaleznosci od
    //trzech przypadkow wzajemnego ustawienia dwoch wiez w tablicy
    int row1, col1, row2, col2;
    int currSumOf1 = 0; //zmianna mowiaca o biezacej wartosci sumy szachowanych pol przez jedna wieze
    int currSumOf2 = 0; //zmienna, mowiaca o biezacej wartosci sumy szachowanych pol przez dwie wieze
    int maxSumOf2 = 0; //maksymalna suma szchowanych pol przez dwie wieze w danej tablicy -na jej podstawie zostana
    //ustalone wspolrzedne dwoch wierz: row1, col1, row2, col2, ktore potem zwroci funckja
    //w zmiennej result

    for (int i = 0; i < N * N - 1; i++) {
        row1 = i / N;
        col1 = i % N;

        currSumOf1 = 0;

        for (int k = 0; k < N; k++) {
            currSumOf1 += t[row1][k] + t[k][col1];
            //potem trzeba bedzie odjac od uzyskanej sumy 2*t[row1][col1]
        }

        currSumOf1 -= 2 * t[row1][col1];

        //teraz uwzgledniamy druga wieze
        for (int j = i+1; j < N * N; j++) {
            row2 = j / N;
            col2 = j % N;

            currSumOf2 = currSumOf1;

            for (int m = 0; m < N; m++) {
                if (row1 == row2) { //przypadek, gdy wierze sa w tym samym rzedzie
                    option = 1;
                    currSumOf2 += t[m][col2];
                }

                if (col1 == col2) { //przypadek, gdy wierze sa w tej samej kolumnie
                    option = 2;
                    currSumOf2 += t[row2][m];
                }

                if (row1 != row2 && col1 != col2) {
                    option = 3;
                    currSumOf2 += t[row2][m] + t[m][col2];
                }
            }

            if (option == 1) {
                currSumOf2 -= t[row2][col2];
            }

            if (option == 2) {
                currSumOf2 -= t[row2][col2];
            }

            if (option == 3) {
                currSumOf2 -= 2 * t[row2][col2];
            }

            if (currSumOf2 > maxSumOf2) {
                maxSumOf2 = currSumOf2;
                result.row1 = row1;
                result.col1 = col1;
                result.row2 = row2;
                result.col2 = col2;
            }

        }
    }

    return result;
}


int main(){

    int N = 4;
    int **t = new int* [N];

    for(int i=0; i<N; i++){
        t[i] = new int [N];
    }

    for(int i=0; i<N; i++){
        t[0][i]=9;
    }

    for(int i=0; i<N; i++){
        t[2][i]=9;
    }

    for(int i=0; i<N; i++){
        t[i][3]=9;
    }

    for(int i=0; i<N; i++){
        t[i][2]=9;
    }

    t[1][0]=1;
    t[1][1]=1;

    t[3][0]=1;
    t[3][1]=1;

    PosOf2Tow result = twoTowers(t, N);

    cout<<result.row1<<" "<<result.col1<<endl;
    cout<<result.row2<<" "<<result.col2<<endl;

    //Free each sub-array
    for(int i = 0; i < N; ++i) {
        delete[] t[i];
    }
    //Free the array of pointers
    delete[] t;

    return 0;
}



