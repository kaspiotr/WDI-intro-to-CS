//author: @kaspiotr (Piotr Kasprzyk)

/*
3. Dane są trzy listy jednokierunkowe uporządkowane rosnąco bez powtarzających się
liczb. Proszę napisać funkcję która usunie w każdej liście elementy powtarzające się
w trzech listach. Funkcja ma zwrócić liczbę usuniętych elementów.
 */

#include <cstdlib>
#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *next;
};

//funkcja drukujaca liste
void printList(Node* first){
    if(first == NULL) return;
    while(first != NULL){
        cout<<first->val<<"\t";
        first=first->next;
    }
    cout<<endl;
    return;
}

//funckja tworzaca liste na podstawie tablicy
Node* createList(int A[], int n){
    Node *q2=NULL;
    Node *first=NULL;

    for(int i=n-1; i>=0; i--){
        Node *q = new Node;
        q->val=A[i];
        q->next = q2;
        q2 = q;
    }

    first=q2;

    return first;
}

void deleteNode(Node* &first, Node* &prev, Node* &q){
    if(prev == NULL){//usuwamy Node'a z poczatku listy
        Node *tmp = q;
        q = q->next;
        first = q;
        delete tmp;
    }
    else{//usuwamy Node'a ze środka lub końca listy
        Node *tmp = q;
        q = q->next;
        prev->next = q;
        delete tmp;
    }

    return;
}

void deleteCommonElement(Node* &first1, Node* &first2, Node* &first3){
    if(first1 == NULL || first2 == NULL || first3 == NULL) return; //jesli ktoras z trzech list jest pusta

    Node* q = first1;
    Node* q1 = first1;
    Node* q2 = first2;
    Node* q3 = first3;
    Node *previous=NULL, *prev1=NULL, *prev2=NULL, *prev3=NULL;

    int howManyEqual = 0; //zminna, ktora mowi w ilu lancuchach aktualnie
    //rozpatrywana wartosc jest taka sama


    while(/*q != NULL &&*/ q1 != NULL && q2 != NULL && q3 != NULL) {
        howManyEqual = 0;

        //if(q1 == NULL || q2 == NULL || q3 == NULL) return; //bo po wejściu do funckji delNode moze okazac sie
        //ze usuniemy node'a z konca, ktoregos z lancuchow
        //i ktores z q1, q2 lub q3beda mialy wartosc NULL
        //przed zaktualizowaniem q na NULL

        if (q != q1 && q->val > q1->val) {
            previous = prev1;
            q = q1;
        } else howManyEqual++;

        if (q != q2 && q->val > q2->val) {
            previous = prev2;
            q = q2;
        } else howManyEqual++;

        if (q != q3 && q->val > q3->val) {
            previous = prev3;
            q = q3;
        } else howManyEqual++;

        //wskaznik q jest ustawiony na najmniejsza z aktualnie
        //rozpatrywanych wartosci we wszystkich listach

        if (howManyEqual == 3  && q1->val == q2->val && q1->val == q3->val) {//czyli jesli q we wszystkich lancuchach pokazuje na node'a, ktorego
            //wartosc w kazdym z node'ow aktualnie rozpatrywanych jest taka sama
            //to usuwamy go ze wszystkich trzech lancuchow
            deleteNode(first1, prev1, q1);
            deleteNode(first2, prev2, q2);
            deleteNode(first3, prev3, q3);
        }

        if (howManyEqual != 3 || q1->val != q2->val || q1->val != q3->val) { //jesli nie doszlo do usuniecia powtarzajacego sie w trzech lancuchach node'a
            if (q == q1) {
                prev1 = q1;
                q1 = q1->next;
            }

            if (q == q2) {
                prev2 = q2;
                q2 = q2->next;
            }

            if (q == q3) {
                prev3 = q3;
                q3 = q3->next;
            }

            previous = q;
            q = q->next;
        }
    }

    return;
}


int main(){

    //int a[]={7,8,15,20};
    //int an=4;

    int a[]={9,16,22,31,32};
    int an=5;

    Node *first1 = createList(a, an);

    //int b[]={6,8};
    //int bn=2;
    int b[]={9,17,22,37};
    int bn=4;


    Node *first2 = createList(b, bn);

    //int c[]={8,15,20};
    //int cn=3;

    int c[]={5,9,14,18,24,53};
    int cn=6;

    Node *first3 = createList(c, cn);

    printList(first1);
    printList(first2);
    printList(first3);

    deleteCommonElement(first1, first2, first3);

    //deleteNode(prev ,first1);

    printList(first1);
    printList(first2);
    printList(first3);

    return 0;
}

