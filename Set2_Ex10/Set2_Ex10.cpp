//author: @kaspiotr (Piotr Kasprzyk)

/*
10. Liczba dwu-trzy-piątkowa w rozkładzie na czynniki pierwsze nie posiada innych czynników niż 2,3,5. Jedynka też jest
taką liczbą. Napisz program, który wylicza ile takich liczb znajduje się w przedziale od 1 do N włącznie.
 */

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int counter=0;

    int j;
    for(int i=1; i<=n; i++){
        j=i;

        while(j%2 == 0)
            j/=2;

        while(j%3 == 0)
            j/=3;

        while(j%5 == 0)
            j/=5;

        if(j == 1) counter++;
    }

    cout<<counter<<endl;

    return 0;
}

