//author: @bielakarolina (Karolina Biela)

/*
ad-wdi-k1b, środa, 5 listopada 2014
1. Proszę napisać program, który wczytuje wprowadzany z klawiatury ciąg liczb naturalnych
zakończonych zerem stanowiącym wyłącznie znacznik końca danych.
Program powinien wypisać te elementy ciągu które są równe średniej arytmetycznej z 4 najbliższych
sąsiadów. Na przykład dla ciągu: 2,3_,2,7,1,2,4_,8,5,2,2,4_,3,9,5_,4,0 powinny zostać wypisane
podkreślone liczby. Można założyć, że w ciągu znajduje się co najmniej 5 elementów.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

  int n=16;
  int tab[n]={2,3,2,7,1,2,4,8,5,2,2,4,3,9,5,4};
  int j,i,suma=0;
  for(int k=0;k<n;k++){
    i=k-2;    //zakresy w idealnym świecie
    j=k+2;
    suma=0;
    while(i<0 && j<n-1 && i!=k){  //przesuwamy się przedziałem nas interesującym
        i++;
        j++;
    }
    while(j>n-1 && i>0 && j!=k){
        i--;
        j--;
    }
 //   cout<<k<<" :k "<<i<<" :i "<<j<<" :j ";
    for(int p=i;p<=j;p++)
        suma+=tab[p];
    suma-=tab[k];
    //cout<<(double)suma/4<<" "<< tab[k]<<endl;
    if(tab[k]==suma/4) cout<<tab[k]<<endl;
  }

    return 0;
}
