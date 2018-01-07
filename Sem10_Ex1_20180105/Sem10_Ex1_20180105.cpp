//author: @kaspiotr (Piotr Kasprzyk)

/*
Zad.1
Napisac funkcje, ktora usunie z lancucha odsylaczowego wszystkie elementy o maksymalnej wartosci.
*/

//wersja pierwsza -bez wartownika

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *next;
};

//funckja pomocnicza do tworzenia lancucha odsylaczowego w odwrotnej kolejnosci do kolejnosci podawania wartosci
Node* createRevList(int noOfEl) {

    int val;
    Node *first=NULL, *p;

    for(int i=1; i<=noOfEl; i++) {
        p = new Node;
        p->next = first;
        cin>>val;
        p->key = val;
        first = p;
    }

    return first;
}

//funckja pomocnicza do tworzenia lancucha odsylaczowego w kolejnosci zgodnej z kolejnoscia wpisywania kolejnych el.
Node* createList(int noOfEls) {

    Node *first=NULL, *prevIter = NULL, *curr;
    int val;

    for(int i=1; i<=noOfEls; i++) {
        if(prevIter == NULL) {
            first = new Node;
            cin>>val;
            first->key = val;
            first->next = NULL;
            prevIter = first;
        } else {
            curr = new Node;
            prevIter->next = curr;
            cin>>val;
            curr->key = val;
            curr->next = NULL;
            prevIter = curr;
        }
    }

    return first;
}

//funckja pomocnicza do wyswietlania lancucha odsylaczowego
void printList(Node *first) {

    while(first != NULL) {
        cout<<first->key<<"\t";
        first=first->next;
    }

    cout<<endl;
}


int maxEl(Node *first){
    int maxVal = first->key;

    while(first != NULL) {
        if(maxVal < first->key) maxVal=first->key;
        first=first->next;
    }

    return maxVal;
}

void delMaxEl(Node* &first) {
    if(first == NULL) return; //jesli lista jest pusta
    int maxVal = maxEl(first);

    Node *prev=NULL, *curr=first;

    while(curr != NULL) {
        if(curr->key == maxVal) {
            if(prev == NULL) {
                curr = curr->next;
                delete first;
                first = curr;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev -> next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

int main() {

    Node *first;
    int noOfEls;

    cin>>noOfEls;

    first = createRevList(noOfEls);

    printList(first);

    delMaxEl(first);

    printList(first);

    cin>>noOfEls;

    first = createList(noOfEls);

    printList(first);

    delMaxEl(first);

    printList(first);

    return 0;
}