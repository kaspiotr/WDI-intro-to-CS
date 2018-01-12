//author: @kaspiotr (Piotr Kasprzyk)

/*
Zad.1
Napisz funkcje przyjmująca wskaźnik na pierwszy element i robiąca 3 operacje: usuwanie elementów o ujemnym kluczu,
elementy których klucz w systemie 7 kończy się cyfra nieparzysta przenosi na początek,
a te z parzysta na koniec.
 */

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
};

bool isLastDigIn7BaseSysOdd(int a) {
    if((a%7)%2 !=0) return true;
    return false;
}

//funckja pomocnicza -do wypisywania listy jednokierunkowej
void printList(Node* first) {
    while(first != NULL) {
        cout<<first->val<<"\t";
        first=first->next;
    }
    cout<<endl;
}

//funckja pomocnicza zwracajaca wskaznik na ostatni element listy jendokierunkowej
Node* lastEl(Node* first) {
    Node *prev = NULL;
    Node *curr = first;

    while(curr != NULL) {
        prev = curr;
        curr = curr->next;
    }

    return prev;
}

void customSort(Node* &first) {
    if(first == NULL) return;
    Node *curr =first;
    Node *prev =NULL;
    Node *begin = NULL;
    Node *end = NULL;

    while(curr != NULL) {
        if(curr->val <0) { //usuwamy Node'a z listy jednokierunkowej
            if (prev == NULL) { //z poczatku
                first = first->next;
                delete curr;
                curr = first;
            }
//            } else { //ze srodka/konca
//                Node *tmp = curr;
//                prev->next = curr->next;
//                curr = curr->next;
//                delete tmp;
//            }
        } else { //nie usuwamy Node'a
            if(isLastDigIn7BaseSysOdd(curr->val)) { //przesuwamy Node'a na poczatek
                if(begin == NULL) { //dodajemy do pustej listy begin
                    if(prev == NULL) { //dodajemy peirwszy el. lancucha first
                        begin = first;
                        first =first->next;
                        curr =first;
                        begin ->next = NULL;
                    } else { //dodajemy kolejny/ostatni element listy first
                        begin = curr;
                        prev->next = curr->next;
                        curr = curr->next;
                        begin->next =NULL;
                    }
                } else { //dodajemy do niepustej listy begin
                    Node *curr2=begin, *prev2 =NULL;
                    while(curr2 != NULL) {
                        prev2 = curr2;
                        curr2 = curr2->next;
                    }

                    if(prev ==NULL) { //dodajemy pierwszy element listy first
                        prev2->next = curr;
                        curr =curr->next;
                        first =curr;
                        prev2->next->next =NULL;
                    } else { //dodajemy kolejny/ostatni element listy first
                        prev2->next = curr;
                        prev->next = curr->next;
                        curr =curr->next;
                        prev2->next->next = NULL;
                    }
                }
            } else { //przesuwamy Node'a na koniec
                if(end ==NULL) { //gdy lista end jest pusta
                    if(prev == NULL) { //gdy bierzemy element z poczatku listy first
                        end = first;
                        first = first->next;
                        curr = first;
                        end->next =NULL;
                    } else { //gdy bierzemy kolejny/ostatni element listy first
                        Node *prev2 = lastEl(end);
                        prev2->next =curr;
                        curr =curr->next;
                        prev2->next->next = NULL;
                    }
                } else { //gdy lista end nie jest pusta
                    Node *prev2 = lastEl(end);

                    if(prev ==NULL) { //gdy dodajemy pierwszy element z listy first
                        prev2->next = curr;
                        curr =curr->next;
                        first =curr;
                        prev2->next->next =NULL;
                    } else { //gdy dodajemy kolejny/ostatni element z listy first
                        prev2->next = curr;
                        prev->next = curr->next;
                        curr = curr->next;
                        prev2->next->next =NULL;
                    }
                }
            }
        }
    }

    Node *lastBegin = lastEl(begin);
    Node *lastFirst = lastEl(first);

    if(begin!=NULL) {
        lastBegin->next = end;
        first = begin;
    } else {
        first = end;
    }
}

int main() {

    Node *first = new Node;
    first->val =23;

    Node *n1 = new Node;
    n1->val = 9;
    first->next = n1;

    Node *n2 = new Node;
    n2->val = 5;
    n1->next = n2;

    Node *n3 = new Node;
    n3->val = 4;
    n2->next = n3;

    Node *n4 = new Node;
    n4->val =-7;
    n3->next = n4;

    n4->next =NULL;

    printList(first);

    customSort(first);

    printList(first);

    return 0;
}