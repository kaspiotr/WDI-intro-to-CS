/*
 Autor: @thoren (Tomasz Makowski)
*/
#include <iostream>
int main() {

    const int N=1000000; //ilość przeszukiwanych liczb

    for (int i=1; i<N; i++) {

        int a=i; // pierwsza liczba
        int b=1; //suma dzielników właściwych pierwszej liczby
        int suma=1; // suma dzielników liczby b

        for (int k=2; k*k<a; k++) { //sumowanie dzielników pierwszej liczby
            if (a%k==0) {
                b+=(k+a/k);
            }
        }

        for (int k=2; k*k<b; k++) { //sumowanie dzielników liczby będącej sumą dzielników pierwszej liczby
            if (b%k==0) {
                suma+=(k+b/k);
            }
            if (b>N) { //warunek nie przekraczania miliona; wystarczy ten jeden warunek (patrz kom. niżej)
                break;
            }
        }

        if ((suma==a)&&(a<b)) { //wyświetlanie tylko liczb zaprzyjaźnionych (bez powtórzeń - można przyjąć a<b)
            std::cout << "Liczby " << a << " i " << b << " sa zaprzyjaznione." << std::endl;
        }
    }

    return 0;
}
