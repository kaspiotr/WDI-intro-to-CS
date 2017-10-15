/*
ad-wdi kolokwium 1, czwartek, 28 stycznia 2010 Nazwisko Imię
Zad. 1 Dana jest duża tablica typu tab=array[1..n] of integer. Proszę napisać funkcję, która
zwraca informację, czy w tablicy zachodzi następujący warunek: „wszystkie elementy, których
indeks jest elementem ciągu Fibonacciego są liczbami złożonymi, a wśród pozostałych
przynajmniej jedna jest liczbą pierwszą”.
Uwagi:
• Czas na rozwiązanie zadania wynosi 25 minut, za zadanie można otrzymać 5 punktów.
• Oceniane będą: przejrzystość i czytelność kodu oraz efektywność rozwiązania.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

const int N = 10;

bool isPrime(int a){
    if(a==1) return false;
    if(a%2==0){
        if(a==2) return true;
        if(a!=2) return false;
    }

    int div=3;

    while(div*div <= a){
        if(a%div == 0){
            if(a == div) return true;
            if(a != div) return false;
        }
        else{
            div+=2;
        }
    }

    return true;
}

void createFibo(int *F, int maxIdx, int &size){

    F[1]=1;
    F[2]=1;

    int i=2;
    do{
        i++;
        F[i]=F[i-1]+F[i-2];
    }while(F[i]<maxIdx);

    F = (int*)realloc(F, (i+1)*sizeof(int));

    size = i+1;
}

bool doesItOccur(int tab[], int n){
    int size = 4;
    int *F = (int*)malloc(size*sizeof(int));//int *F = new int [n];

    createFibo(F, n-1, size);

    bool thereIsAtLeastOnePrime = false;
    bool firstElIsPrime = false;

    if(isPrime(tab[0]) == true) firstElIsPrime = true;

    int j=1; //indeks aktualnie rozpatrywanego elementu ciagu Fibonacciego

    for(int i=1; i<n; i++){
        while(j<size-1 && F[j]<i) j++;

        if(F[j]==i && isPrime(tab[i])==true) {
            free(F);
            return false;
        }

        if(thereIsAtLeastOnePrime==false && F[j]!=i && isPrime(tab[i])==true)
            thereIsAtLeastOnePrime = true;
    }

    free(F);

    if(firstElIsPrime == true) return true;
    if(thereIsAtLeastOnePrime == true) return true;

    return false;
}


int main(){
    //           0, F, F, F, 4, F, 6, 7, F, 9,10,11,12, F
    int tab1[]={ 7, 4, 6, 8,12,16, 6, 8,34, 4}; //->tak
    int tab2[]={ 1, 2, 3, 5, 4, 7, 8,13,14,15}; //->nie
    int tab3[]={ 1, 4, 6, 8,12,16, 6, 8,34, 4}; //->nie

    if(doesItOccur(tab1, N) == true) cout<<"tab1 TAK"<<endl;
    else cout<<"tab1 NIE"<<endl;
    if(doesItOccur(tab2, N) == true) cout<<"tab2 TAK"<<endl;
    else cout<<"tab2 NIE"<<endl;
    if(doesItOccur(tab3, N) == true) cout<<"tab3 TAK"<<endl;
    else cout<<"tab3 NIE"<<endl;

    return 0;
}