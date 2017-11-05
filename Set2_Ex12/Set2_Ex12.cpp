//author: @kaspiotr (Piotr Kasprzyk)

/*
12. Dana jest liczba naturalna o niepowtarzających się cyfrach pośród których nie ma zera.
Ile różnych liczb podzielnych np. przez 7 można otrzymać poprzez wykreślenie dowolnych cyfr w tej liczbie.
Np. dla 2315 będą to 21, 35, 231, 315.
 */

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int m = n;
    int digNo = 0;
    int pow = 1;

    n=0;
    while(m != 0){
        digNo++;
        n=10*n + m%10;
        pow*=2;
        m/=10;
    }
    //cout<<n<<endl;

    int counter = 0, j, number;
    for(int i=1; i<pow; i++){ //od i=1 bo nie rozwazamy liczby 0 cyfrowej
        j=i;
        m=n;
        number=0;
        while(m != 0){
            if(j%2 == 1) number = number*10 + m%10;
            m/=10;
            j/=2;
        }
        //cout<<number<<endl;

        if(number%7 == 0) counter++;
    }

    cout<<counter<<endl;

    return 0;
}
