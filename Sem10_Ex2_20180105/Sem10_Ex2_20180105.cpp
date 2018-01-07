//author: @kasiotr (Piotr Kasprzyk)

/*
Zad.2
Napisac funkcje, ktora stwierdzi czy dany lanuch odsylaczowy zawiera cykl czy nie.
*/

//pomysl: przechodzic liste jendokierunkowa dwoma wskaznikami; pierwszym co jeden element, a drugim
//co drugi element

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *next;
};

//funckja pomocnicza do wyswietlania lancucha odsylaczowego
void printList(Node *first) {

    int maxNoOfDispEls = 8; //zmianna, ktora mowi ile elementow lancucha zostanie maksymalnie wyswietlonych
    while(first != NULL && maxNoOfDispEls>0) {
        cout<<first->key<<"\t";
        first=first->next;
        maxNoOfDispEls--;
    }

    cout<<endl;
}

bool cycle(Node *first) {

    //lancuch jest pusty
    if(first == NULL) return false;

    Node *p1 = first; //skok co 1
    Node *p2 = first->next; //skok co 2

    while(p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        if(p2 == NULL) return false;

        p2 = p2->next;
        if(p2 == NULL) return true;
    }
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

    printList(first1);

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

    printList(first2);

    return 0;
}
