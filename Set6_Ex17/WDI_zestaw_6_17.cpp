// WDI_zestaw_6_17.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<ctime>

using namespace std;

const int N = 10;

bool isPrime(int t[N], int p, int k) {

	if (t[k] == 0) return false;
	long long int result = 0; //problem z zakresm int dla d³ugich liczb...
	for (int i = p; i <= k; i++) {
		result += t[i];
		result *= 10;
	}
	result /= 10;

	if (result == 0 || result == 1) return false;

	for (int i = 2; i <= sqrt(result); i++) {
		if (result%i == 0) return false;
	}
	
	cout << result << endl;
	return true;

}

bool funkcja(int t[N], int i, int j) { 

	if (isPrime(t, i, j)) return true; else {

		for (int j = 0; j < 30 && i + j + 1 < N; j++) {

			if (isPrime(t, i, i + j) && funkcja(t, i + j + 1, N - 1))
				return true;
		}

	}

	return false;

}


int main()
{
	srand(time(NULL));
	int tab[N];
	for (int i = 0; i < N; i++) tab[i] = rand() % 2;
	for (int i = 0; i < N; i++) cout << tab[i];
	cout << endl;
	cout << funkcja(tab, 0, 0) << endl;
    return 0;
}

