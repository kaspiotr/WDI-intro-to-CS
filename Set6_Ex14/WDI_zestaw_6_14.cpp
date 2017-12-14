// WDI_zestaw_6_14.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include<iostream>
#include<ctime>

using namespace std; //kwestia zwracania TRUE !!!

bool flag = false;

bool king(int t[8][8], int w, int k) {
	
	if (w == 7 && k == 7) {
		flag = true; cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
		return true;
	}

	if (!flag) {

		int dw[3] = { 0,1,1 };
		int dk[3] = { 1,1,0 };

		for (int i = 0; i < 3; i++) {
			int new_w = w + dw[i];
			int new_k = k + dk[i];
			if (new_w >= 0 && new_w < 8 && new_k >= 0 && new_k < 8) {
				int last = t[w][k] % 10; cout << t[w][k] << " LAST: " << last << endl;
				int first = t[new_w][new_k]; while (first >= 10) first /= 10; cout << t[new_w][new_k] << " FIRST: " << first << endl;
				if (last < first) {
					cout << "TAK" << endl;
					king(t, new_w, new_k);
				}
				else cout << "NIE" << endl;
			}
		}
	}
	if (flag) return true;
}

int main()
{
	srand(time(NULL));
	int tab[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tab[i][j] = rand() % 100;
		}
	}
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}

	cout << king(tab, 0, 0);

	
	


    return 0;
}

