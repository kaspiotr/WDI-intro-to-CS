//author: @kaspiotr (Piotr Kasprzyk)

/*
6. Proszę napisać program, który wczytuje wprowadzany z klawiatury ciąg liczb naturalnych zakończonych zerem stanowiącym
wyłącznie znacznik końca danych. Program powinien wypisać te elementy ciągu które są równe średniej arytmetycznej z 4
najbliższych sąsiadów. Na przykład dla ciągu: 2,3_,2,7,1,2,4_,8,5,2,2,4_,3,9,5_,4,0 powinny zostać wypisane
podkreślone liczby. Można założyć, że w ciągu znajduje się co najmniej 5 elementów.
 */

#include <iostream>
#include <string>

using namespace std;

double arythAverageVal(int *tab, int idx, int tabSize){

    int idxL = idx-2;
    int idxR = idx+2;
    double average = 0;

    while(idxL < 0){
        idxR++;
        idxL++;
    }

    while(idxR > tabSize-1){
        idxL--;
        idxR--;
    }

    for(int i=idxL; i<=idxR; i++){
        if(i == idx) continue;
        average += tab[i];
    }

    average = average/4.0;

    return average;
}


int main(){

    string seq;
    cin>>seq;

    int strSize = seq.size();

    int *tab = (int*)malloc(strSize*sizeof(int));

    int idx = 0; //idx -aktualnie rozpatrywany element w ciagu wejsciowym
    int intVal = 0;
    int digit;
    int tabIdx=0;
    int pos = 1;
    int length=0;

    while(idx < strSize){

        pos = 1;
        intVal = 0;
        while(seq[idx] != ',' && seq[idx] != '0'){
            digit = seq[idx]-'0';
            intVal *= pos;
            intVal += digit;
            pos *= 10;
            idx++;
        }

        if(seq[idx] == ','){
            tab[tabIdx] = intVal;
            tabIdx++;
            idx++;
            length++;
            continue;
        }

        if(seq[idx] == '0') break;
    }

    tab = (int*)realloc(tab, length*sizeof(int));

    for(int i=0; i<length; i++){
        double value = tab[i];
        if(value == arythAverageVal(tab, i, length)){
            cout<<tab[i]<<" ";
        }
    }
    cout<<endl;

    free(tab);

    return 0;
}
