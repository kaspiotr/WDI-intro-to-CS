//author: @kaspiotr (Piotr Kasprzyk)

/*
19. Napisać funkcję, do której przekazujemy licznik i mianownik ułamka. Funkcja powinna wypisać
wartość ułamka jako rozwinięcie dziesiętne uwzględniające okres, np. 1/3=0.(3), 1/6=0.1(6).
*/

#include <iostream>

using namespace std;

const int MAX = 300;

//funkcja wypisujaca rozwiniecie dziesietne ulamka o podanym liczniku (counter) i mianowniku (denominator)
void expansion(int c, int d){
    int rests[MAX]; //tablica reszt
    int result[MAX]; //cyfry wyniku

    for(int i=0; i<MAX; i++){
        rests[i]=0;
        result[i]=0;
    }

    result[0]=c/d;
    c%=d;
    rests[0]=c;
    int i=1, j;

    while(true){
        c*=10;
        result[i]=c/d;
        c%=d;
        rests[i]=c;

        //gdy d dzieli c (ulamek nie ma okresu)
        if(c == 0) break;

        //przeszukiwanie, czy ktoras z reszt sie nie powtorzyla
        for(j=0; j<i; j++){
            if(rests[j] == c) break;
        }

        if(j < i) break;
        i++;
    }
    i++;

    cout<<result[0]<<".";

    //dla ulamka bez okresu
    if(c == 0) {
        for (int k = 1; k < i; k++) cout << result[k];
    }
    else{
        for(int k=1; k<=j; k++) cout<<result[k];
        cout<<"(";
        for(int k=j+1; k<i; k++) cout<<result[k];
        cout<<")";
    }

}

int main(){
    int a,b;
    cin>>a>>b;

    expansion(a,b);
    cout<<endl;

    return 0;
}