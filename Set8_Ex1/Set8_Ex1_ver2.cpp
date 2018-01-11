//author: @kaspiotr (Piotr Kasprzyk)

/*
1. Proszę napisać funkcję wstawiającą na koniec listy nowy element. Do funkcji należy przekazać
wskazanie na pierwszy element listy oraz wstawianą wartość.
*/

//wersja z wartownikiem (version with sentry)

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

//argument -linked list with sentry
void addOneAtTheEnd(Node* &first) {
    Node * curr = first->next;
    if(curr == NULL) {
        curr = new Node;

    }
}

int main() {

    //linked list with sentry
    Node *first = new Node;
    first->next = curr1;
    Node *curr1 = new Node;
    curr1->val = 9;
    Node *curr2 = new Node;
    first2->next = curr2;
    curr2->val = 8;
    Node *curr3 = new Node;
    curr2->next = curr3;
    curr3->val = 7;
    Node *curr4 = new Node;
    curr3->next = curr4;
    curr4->val = 6;
    curr4->next = NULL;

    printList(first);

    cout<<"Give a natural number that will be added at the of the list"<<endl;
    int value;
    cin>>value;

    addOneAtTheEnd(first, value);

    printList(first);

    return 0;

    return 0;
}