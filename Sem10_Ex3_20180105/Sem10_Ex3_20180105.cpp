//author: @kapiotr (Piotr Kasprzyk)

/*
Napisac funckje, ktora obliczy dlugosc cyklu w cyklicznym lancuchu odsylaczowym
*/

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *next;
};

//funckja, ktora oblicza dlugosc cyklu w lancuchu -jesli lancuch nie zawiera cyklu funckja zwraca wartosc 0
int cycleLength(Node *first) {
    if(first == NULL) return 0;

    Node *p1 = first; //skok co 1
    Node *p2 = first->next; //skok co 2

    while(p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        if(p2 == NULL) return 0;

        p2=p2->next;
        if(p2 == NULL) return 0;
    }

    //znaleziono cykl
    int counter=1;
    p1=p1->next;

    while(p1 != p2){
        counter++;
        p1 = p1->next;
    }

    return counter;

}

int main() {

    //lancuch z cyklem
    Node *first1 = new Node;
    first1->key = 1;
    Node *curr1 = new Node;
    first1->next = curr1;
    curr1->key = 2;
    Node *curr12 = new Node;
    curr1->next = curr12;
    curr12->key = 3;
    Node *curr13 = new Node;
    curr12->next = curr13;
    curr13->key = 4;
    curr13->next = curr1;


    //lancuch bez cyklu
    Node *first2 = new Node;
    first2->key = 9;
    Node *curr2 = new Node;
    first2->next = curr2;
    curr2->key = 8;
    Node *curr22 = new Node;
    curr2->next = curr22;
    curr22->key = 7;
    Node *curr23 = new Node;
    curr22->next = curr23;
    curr23->key = 6;
    curr23->next = NULL;


    cout<<cycleLength(first1)<<endl;
    cout<<cycleLength(first2)<<endl;

    return 0;
}