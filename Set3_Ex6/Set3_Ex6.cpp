//. Napisać program obliczający i wypisujący wartość N! dla N z zakresu od 1 do 1000.


#include <iostream>
#include <cmath>
using namespace std;


int main(){
   int digitNumber,p,tmp, N;
   //z wzoru sterlinga

   cin>>N;

   digitNumber=int((N*log(N/exp(1))+0.5*log(N*3.14))/10.0)+1;
   int s[digitNumber];

   // Zerowanie tab
   for (int i=0;i<digitNumber;i++){
      s[i]=0;
   };

   s[0]=1;


   for(int i=2;i<=N;i++){
      p=0;
      for(int j=0;j<digitNumber;j++){
         tmp=s[j]*i+p;
         p=tmp/10;
         s[j]=tmp%10;

      };
   };
   // Zliczam ile jest zer na koncu
   int k=0;
   while(s[k]==0){
      k=k+1;
   };

   for(int i=0;i<digitNumber-k;i++){
      cout<<s[digitNumber-i-1];
   };
   cout<<"*1E+"<<k;
   cin.ignore();
}
