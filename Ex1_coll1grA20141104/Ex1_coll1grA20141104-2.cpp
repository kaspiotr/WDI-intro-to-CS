

//mniej rozbudowane rozwiązanie
int main()
{
  int number;
  int t[10] = {0,0,0,0,0,0,0,0,0,0};  // w tej tablicy bede trzymal elementy w porzadku rosnacym 
  for(;;)
  {
    std::cin >> number;
    if(number==0) break;
    int i;
    for(i=0; i<10 and t[i]>number ;i++)
      ;
    if(i==10 or t[i]==number) continue;
    for(int j=8; j>=i ;j--) 
      t[j+1]=t[j];
    t[i]=number;      
  }
  std::cout << "10 wartosc: " << t[9];
  return 0;
}
