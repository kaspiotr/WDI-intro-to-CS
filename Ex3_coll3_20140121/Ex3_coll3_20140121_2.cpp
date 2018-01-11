/* Napisz funkcje ktora przyjmuje wskaznik do poczatku jednokierunkowego łańcucha odsyłaczowego,
a następnie przenosi na początek wszystkie elementy, w których zapisie ósemkowym występuje nieparzysta
liczba piątek. */


struct Node
{
 int val;
 Node* next;
};


bool Parity5(int k)
{
  bool noparity=false;
  
  while(k!=0)
  {
    if(k%8==5) noparity=!noparity;
    k/=8;
  }
  return noparity;
}

void ChangeList(Node* list)
{   
    Node* empty;
    empty=new Node;
    empty->next=list;
    for(Node* p=list; p->next!=NULL; )
    {
      if( Parity5(p->next->val) )
      {
        Node* tmp=p->next;
        p->next=tmp->next;
        tmp->next=list;
        list=tmp;
        empty->next=tmp;
      }
      else p=p->next;
    }
    delete empty;
}

