//author: @kaspiotr (Piotr Kasprzyk)

/*
Zad.1
Napisac funkcje, ktora usunie z lancucha odsylaczowego wszystkie elementy o maksymalnej wartosci.
*/

//wersja druga -z wartownikiem

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *next;
};

//funckja pomocnicza do tworzenia lancucha odsylaczowego w kolejnosci zgodnej z kolejnoscia wpisywania kolejnych el.
Node* createList(int noOfEls) {

    Node *first=new Node;
    Node *prevIter = NULL, *curr;
    int val;

    for(int i=1; i<=noOfEls; i++) {
        if(prevIter == NULL) {
            curr = new Node;
            cin>>val;
            curr->key = val;
            curr->next = NULL;
            prevIter = curr;
            first->next = curr;
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

//funkcja wypisujaca liste z wartownikiem
void printList(Node* first) {
    first = first->next;
    while(first != NULL) {
        cout<<first->key<<"\t";
        first = first ->next;
    }
    cout<<endl;
}

int maxEl(Node *first) {
    first = first->next;
    int maxVal = first->key;
    while(first != NULL) {
        if(maxVal < first->key) maxVal = first->key;
        first = first->next;
    }

    return maxVal;
}

void delMaxEl(Node *first) {
    if(first-> next == NULL) return;
    int maxVal = maxEl(first);

    Node *prev=first, *curr = first->next;

    while(curr != NULL) {
        if(curr->key == maxVal) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
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

    first = createList(noOfEls);

    printList(first);

    delMaxEl(first);

    printList(first);

    return 0;
}