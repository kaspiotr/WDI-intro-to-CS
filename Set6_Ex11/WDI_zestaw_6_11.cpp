// WDI_zestaw_6_11.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;

void wyraz(string s1, string s2, int i, string s3) {

	int samogloski = 0; int samogloski_3 = 0; int waga = 0; int waga_3 = 0;
	for (int i = 0; i < (int)s1.length(); i++) {
		if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'u' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'y') 
			samogloski++;
	}

	for (int i = 0; i < (int)s1.length(); i++) {
		waga += (int)s1[i];
	}

	for (int i = 0; i < (int)s3.length(); i++) {
		if (s3[i] == 'a' || s3[i] == 'e' || s3[i] == 'u' || s3[i] == 'i' || s3[i] == 'o' || s3[i] == 'y')
			samogloski_3++;
	}

	for (int i = 0; i < (int)s3.length(); i++) {
		waga_3 += (int)s3[i];
	}

	if (samogloski == samogloski_3) {
		if (waga == waga_3) {
			cout << s3 << endl;
			//return true;
		}
	}

	if (i < (int)s2.length()) {
		wyraz(s1, s2, i+1, s3 + s2[i]);
		wyraz(s1, s2, i+1, s3);
	}

	//return false;

}




int main()
{

	/*string s1 = "";
	string s2 = "abcd";
	string s3 = s1 + s2[0];
	cout << s3 << endl;*/

	wyraz("ala", "allllaaa", 0, "");

    return 0;
}

