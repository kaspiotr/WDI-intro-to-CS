//author: @kaspiotr (Piotr Kasprzyk)

/*
1. Proszę napisać funkcję wstawiającą na koniec listy nowy element. Do funkcji należy przekazać
wskazanie na pierwszy element listy oraz wstawianą wartość.
*/

//wersja bez wartownika (version without sentry)

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
};

//funckja pomocnicza do wyswietlania lancucha odsylaczowego
void printList(Node *first) {

    while(first != NULL) {
        cout<<first->val<<"\t";
        first=first->next;
    }

    cout<<endl;
}

void addOneAtTheEnd(Node* &first, int newVal) {
    if(first == NULL) {
        first = new Node;
        first->val = newVal;
        first->next = NULL;
        return;
    }

    Node *curr = first;
    Node *prev = NULL;

    while(curr != NULL) {
        prev = curr;
        curr = curr->next;
    }

    curr = new Node;
    curr->val = newVal;
    curr->next = NULL;
    prev->next = curr;
}

int main() {

    Node *first2 = new Node;
    first2->val = 9;
    Node *curr2 = new Node;
    first2->next = curr2;
    curr2->val = 8;
    Node *curr22 = new Node;
    curr2->next = curr22;
    curr22->val = 7;
    Node *curr23 = new Node;
    curr22->next = curr23;
    curr23->val = 6;
    curr23->next = NULL;

    printList(first2);

    cout<<"Give a natural number that will be added at the of the list"<<endl;
    int value;
    cin>>value;

    addOneAtTheEnd(first2, value);

    printList(first2);

    return 0;
}
