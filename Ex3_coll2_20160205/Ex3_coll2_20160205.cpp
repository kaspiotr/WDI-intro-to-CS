//author: @kaspiotr (Piotr Kasprzyk)

/*
Zad3. Dany jest zbior punktow plaszczyzny o wspolrzednych bedacych liczbami calkowitymi. Zbior ten dany jest
w postaci listy jednokierunkowej. Prosze napisac funckje, ktora rozdziela lancuch na cztery lancuchy zawierajace punkty
nalezace odpowiednio do I, II, II i IV cwiartki ukladu wpsolrzednych, natomiast punkty lezace na osiach ukladu
wspolrzednych usuwa z pamieci. Prosze zadeklarowac odpowiednie typy.
*/

#include <iostream>

using namespace std;

struct Point {
    int x, y;
    Point *next;
};

//funkcja pomocnicza do drukowania listy
void printList(Point *first) {
    while(first != NULL) {
        cout<<"x="<<first->x<<", y="<<first->y<<"\t";
        first = first->next;
    }
    cout<<endl;
}

int whichQuarter(int x, int y) {
    if(x >0 && y >0) return 0;
    if(x <0 && y >0) return 1;
    if(x <0 && y <0) return 2;
    if(x >0 && y <0) return 3;
}

void divInFour(Point* &first, Point* &first1, Point* &first2, Point* &first3, Point* &first4) {
    first1 = first2 = first3 = first4 = NULL;
    if(first == NULL) return;

    Point* start[4];
    for(int i=0; i<4; i++) start[i]=NULL;
    int key;

    while(first !=NULL) {
        if(first->x ==0 || first->y ==0) { //usuwamy Point'a
            //zawsze usuwamy z poczatku listy jednokierunkowej
            Point *tmp =first;
            first = first->next;
            delete tmp;
        } else {
            key = whichQuarter(first->x, first->y);

            if(start[key] == NULL) {
                start[key] =first;
                first =first->next;
                start[key]->next = NULL;
            } else {
                Point *curr = start[key];
                Point *prev = NULL;

                while(curr != NULL) {
                    prev = curr;
                    curr =curr->next;
                }

                prev->next = first;
                curr = first;
                first = first->next;
                curr->next = NULL;
            }
        }
    }

    first1 = start[0];
    first2 = start[1];
    first3 = start[2];
    first4 = start[3];
}

int main() {

    Point *first;

    Point *p1 = new Point;
    first = p1;
    p1->x = -9; p1->y= 4;

    Point *p2 = new Point;
    p1->next = p2;
    p2->x = 5; p2->y= 16;

    Point *p3 = new Point;
    p2->next = p3;
    p3->x = 0; p3->y= 30;

    Point *p4 = new Point;
    p3->next = p4;
    p4->x = 12; p4->y= 7;

    Point *p5 = new Point;
    p4->next = p5;
    p5->x = 3; p5->y= 14;

    p5->next = NULL;

    printList(first);

    Point *first1, *first2, *first3, *first4;
    first1 = first2 = first3 = first4 = NULL;

    divInFour(first, first1, first2, first3, first4);

    cout<<"first: ";
    printList(first);

    cout<<"1: ";
    printList(first1);
    cout<<"2: ";
    printList(first2);
    cout<<"3: ";
    printList(first3);
    cout<<"4: ";
    printList(first4);

    return 0;
}
