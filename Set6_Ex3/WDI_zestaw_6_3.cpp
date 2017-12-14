// WDI_zestaw_6_3.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include<iostream>
#include<ctime>

using namespace std;

const int N = 20; 

int counter = 0;

void Nka(int t[N], int max_n, int n, int indeks, int tmp_iloczyn, int iloczyn, int *tab, bool bierzemy) {

	if (bierzemy) tab[n-1] = t[indeks-1];

	if (n == max_n && tmp_iloczyn == iloczyn) {
		counter++;
		for (int i = 0; i < max_n; i++) {
			cout << tab[i] << " ";
		}
		cout << endl;
	}

	if (n < max_n && tmp_iloczyn <= iloczyn && indeks < N) { //tmp_iloczyn mniejszy lub równy!
		bool flag = true;
		Nka(t, max_n, n + 1, indeks + 1, tmp_iloczyn*t[indeks], iloczyn, tab, flag);
		flag = false;
		Nka(t, max_n, n, indeks + 1, tmp_iloczyn, iloczyn, tab, flag);
	}

}

int main()
{
	srand(time(NULL));
	int tab[N]; int n, ilo;
	for (int i = 0; i < N; i++) tab[i] = rand() % 10;
	for (int i = 0; i < N; i++) cout << tab[i] << " "; cout << endl;
	cout << "Podaj liczbe N-ek: ";
	cin >> n;
	cout << endl;
	cout << "Podaj iloczyn: ";
	cin >> ilo;
	cout << endl;
	
	int *tab1 = new int[n]; bool flag1 = false;
	
	Nka(tab, n, 0, 0, 1, ilo, tab1, flag1);
	
	cout << "LICZBA N-ek: "; 
	cout << counter << endl;
	delete[]tab1;
	return 0;
}
