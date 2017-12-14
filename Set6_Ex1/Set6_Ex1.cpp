//author: dr inż. Marek Gajecki

/*
1. Rekurencyjne obliczanie wyznacznika z macierzy (treśd oczywista)
*/

//obliczanie wyznacznika macierzy w oparciu o tablice statyczne (tablice dwuwymiarowe przekazywane do funkcji)

#include <iostream>

using namespace std;

const int N = 4;

//funckja dosuwajaca liczony minor macierzy do lewego gornego rogu macierzy wejsciowej -zeby potem funckja rekureencyjna
//mogla zwrocic wartosc obliczonego wyznacznika
void dosun(double t[N][N], double t2[N][N], int i, int n) {
    for (int k = 0; k < n; k++)
        for (int w = 1; w < n; w++)
            t2[n - 1][i] = t[n][i];

    for (int w = 0; w < n - 1; w++)
        for (int k = i; k < n; k++)
            t2[w][k] = t2[w][n - 1];
}

double det(double t[N][N], int n) {
    double t2[N][N];

    if (n == 1) return t[0][0];

    double sum = 0.0;
    int zn = 1; //zmienna ustalajaca znak przy obliczaniu wyznczanika (minora)

    for (int i = 0; i < n; i++) {
        dosun(t, t2, i, n);
        sum += t[0][i] * det(t2, n - 1) *
               zn; //t2 to macierz o usunietym wierszu i usunietej kolumnie i dosunieta do gortnego
        //lewego rogu
        zn = -zn; //bo znak zmienia sie na przemian
    }

    return sum;
}


int main() {

    double matrix[][N] = {{1,  2,  3,  4},
                          {5,  6,  7,  8},
                          {9,  10, 11, 12},
                          {13, 14, 15, 16}}; //wyznacznik dla tej macierzy powinien wyniesc 0

    double matrix2[][N] = {{1, 2, 3, 4},
                           {3, 2, 1, 7},
                           {5, 2, 1, 3},
                           {1, 3, 4, 2}}; //wyznacznik dla tej macierzy powinien wyniesc 54

    cout << det(matrix, N) << endl;

    cout << det(matrix2, N) << endl;

    return 0;
}