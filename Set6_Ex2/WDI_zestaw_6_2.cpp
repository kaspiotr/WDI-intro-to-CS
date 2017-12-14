// WDI_zestaw_6_2.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

const int N = 10;

int counter = 0;

void Nka(int t[N], int max_n, int n, int indeks, int tmp_iloczyn, int iloczyn) {

	if (n == max_n && tmp_iloczyn == iloczyn) counter++;

	if (n < max_n && tmp_iloczyn <= iloczyn && indeks < N) { //tmp_iloczyn mniejszy lub równy!
		Nka(t, max_n, n + 1, indeks + 1, tmp_iloczyn*t[indeks], iloczyn);
		Nka(t, max_n, n, indeks + 1, tmp_iloczyn, iloczyn);
	}
}

int main()
{
	int tab[N] = { 50, 25, 1000, 1, 2, 1000, 10, 1000, 5, 1001 };
	Nka(tab, 2, 0, 0, 1, 50);
	cout << counter;
    return 0;
}

