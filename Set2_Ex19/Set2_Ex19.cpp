//author: @kaspiotr (Piotr Kasprzyk)

/*
19. Mamy dane dwa ciągi o następujących zależnościach:
A:  a(0)=0, a(1)=1,a(n)=a(n-1)-b(n-1)*a(n-2)
B:  b(0)=2, b(n)=b(n-1)+2*a(n-1)
Proszę napisać program, który czyta liczby typu int ze standardowego wejścia i tak długo jak liczby te są kolejnymi
wyrazami ciągu An (tj. a0, a1, a2, ...) wypisuje na standardowe wyjście wyrazy drugiego ciągu Bn (tj. b0, b1, b2, ...).
*/

/* Kolejne wyrazy ciagu an: 0 1 1 -3 -9 -9 -171
 * Kolejne wyrazy ciagu bn: 2 2 4 6 0 -18 -36
 *
 */
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, prev;
    int a0=0, a1=1, b0=2;
    int a2, b1;

    bool a0Checked = false; //flaga, ktora mowi czy wyraz a0 zostal sprawdzony
    bool a1Checked = false; //flaga, ktora mowi czy wyraz a1 zostal sprawdzony
    while(cin.peek()!='\n'){//wczytywanie wejscia do pojawienia sie znaku nowej linii -enter('\n')
        cin>>n;
        prev=n;

        if(!a0Checked){
            if(n!=a0) break;
            else{
                cout<<b0<<endl;
                a0Checked=true;
                continue;
            }
        }

        if(!a1Checked){
            if(n!=a1) break;
            else{
                b1 =b0+2*a0;
                a2 =a1-b1*a0;
                b0=b1;
                a0=a1;
                a1=a2;

                cout<<b1<<endl;
                a1Checked=true;
                continue;
            }
        }


        b1=b0+2*a0;
        a2=a1-b1*a0;

        b0=b1;
        a0=a1;
        a1=a2;

        if(prev==a0) cout<<b1<<endl;
        else break;

    }

    return 0;
}