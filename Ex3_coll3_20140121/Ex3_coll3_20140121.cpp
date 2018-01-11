//author: @kaspiotr (Piotr Kasprzyk)

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
};

//funckja pomocnicza -drukujaca liste jednokierunkowa
void printList(Node *first) {
    while(first != NULL) {
        cout<<first->val<<"\t";
        first = first->next;
    }
    cout<<endl;
}

int noOf5(int o){
    int counter = 0;

    while(o !=0){
        if(o%10 ==5) counter++;
        o /=10;
    }

    return counter;
}

int osemkowo(int a) {
    int result =0, rest =0, pos = 1;

    while(a !=0) {
        rest =a%8;
        result += rest*pos;
        pos *=10;
        a /=8;
    }

    return result;
}

void moveAtBegin(Node* &first) {
    if(first == NULL) return;
    Node *prev = NULL, *curr = first;
    Node *moved = NULL;

    while(curr != NULL) {
        if(noOf5(osemkowo(curr->val))%2 != 0) {
            if(moved == NULL) { //gdy lista moved jest pusta
                if(prev == NULL) { //gdy przenosimy pierwszy element listy first
                    moved = curr;
                    curr = curr->next;
                    first = curr;
                    moved->next = NULL;
                } else { //gdy przenosimy kolejny/ostatni element listy first
                    moved = curr;
                    prev->next = curr->next;
                    curr = curr->next;
                    moved->next = NULL;
                }
            } else { //gdy lista moved nie jest pusta
                Node *prevMov = NULL;
                Node *curr2 = moved;
                while(curr2 != NULL) {
                    prevMov = curr2;
                    curr2 = curr2->next;
                }

                if(prev == NULL) { //gdy przenosimy pierwszy element listy first
                    prevMov->next = curr;
                    curr = curr->next;
                    first = curr;
                    prevMov->next->next=NULL;
                } else { //gdy przenosimy kolejny/ostatni element listy first
                    prevMov->next = curr;
                    prev->next = curr->next;
                    curr = curr->next;
                    prevMov->next->next = NULL;
                }
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    Node *prevMov = NULL;
    Node *curr2 = moved;
    while(curr2 != NULL) {
        prevMov = curr2;
        curr2 = curr2->next;
    }
    prevMov->next = first;
    first = moved;
}

int main() {

    Node *first = new Node;
    first->val =16;

    Node *n1 = new Node;
    first->next = n1;
    n1->val = 21;

    Node *n2 = new Node;
    n1->next = n2;
    n2->val = 5;

    Node *n3 = new Node;
    n2->next = n3;
    n3->val = 13;

    Node *n4 = new Node;
    n3->next = n4;
    n4->val = 45;

    n4->next = NULL;

    printList(first);

    moveAtBegin(first);

    printList(first);

    return 0;
}
