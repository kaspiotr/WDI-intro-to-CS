// WDI_zestaw_4_12.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

const int max2 = 4;
const int max1 = 2;

int liczba_jedynek(int n) {

	int count = 0;
	while (n > 0) {
		int last = n % 2;
		if (last == 1) count++;
		n /= 2;
	}

	return count;

}

bool isPossible(int t1[max1][max1], int t2[max2][max2]) {

	int zgodnosc = 0;

	for (int i = 0; i <= max2 - max1; i++) {
		for (int j = 0; j <= max2 - max1; j++) {
			zgodnosc = 0;
			for (int p = 0; p < max1; p++) {
				for (int k = 0; k < max1; k++) {

					if (liczba_jedynek(t2[i + p][j + k]) == liczba_jedynek(t1[p][k])) {
						zgodnosc++;
						//cout << t2[i + p][j + k] << " " << t1[p][k] << endl;
					}
					
				}
			}
			double q = double(zgodnosc) / (double)(max1*max1);
			q *= 100;
			if (q > 33) return true;
		}
	}	
	return false;
}



int main()
{


	int t2[max2][max2]; int t1[max1][max1];

	for (int i = 0; i < max2; i++) {
		for (int j = 0; j < max2; j++) {
			t2[i][j] = 1841;
		}
	}

	
	t2[2][1] = 10;
	t2[2][2] = 6;
	t2[3][1] = 9;
	t2[3][2] = 6;

	t1[0][0] = 1;
	t1[1][1] = 10;
	t1[0][1] = 1;
	t1[1][0] = 6;

	for (int i = 0; i < max2; i++) {
		for (int j = 0; j < max2; j++) {
			cout << t2[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < max1; i++) {
		for (int j = 0; j < max1; j++) {
			cout<<t1[i][j] << " ";
		}
		cout << endl;
	}


	cout<<isPossible(t1, t2);
	


    
	return 0;
}

