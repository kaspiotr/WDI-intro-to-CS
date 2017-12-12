//author: @kaspiotr (Piotr Kasprzyk)

#include <iostream>

using namespace std;

//funckja wypisujaca wszystkie mozliwe rozwiazania
void ala(int x, int y, int k, string res){
    if(x == y) cout<<res<<endl;
    if(k > 0){
        if(9 < x < 100) ala(10*(x%10)+(x/10),y,k-1,res+"A");
        ala(3*x, y, k-1, res+"B");
        if(9 < x) ala(x/10, y, k-1, res+"C");
    }
}

//funckja zwracajaca string z rozwiazaniem -pierwszym uzyskanym przez funckje rekurencyjna
string ola(int x, int y, int k, string res){
    if(x==y) return res;
    if(k==0) return "*";
    string r;
    if(9 < x < 100){
        r = ola(10*(x%10)+(x/10), y, k-1, res+"A");
        if(r != "*") return r;
    }
    r = ola(3*x, y, k-1, res+"B");
    if(r != "*") return r;

    if(9 < x){
        r = ola(x/10, y, k-1, res+"C");
        if(r != "*") return r;
    }

    return "*";
}

//funckja odpowiada na pytanie, czy mozna przeksztalcic liczbe x na y wykonujac trzy podane w tresci
//zadania operacje w ciagu k krokow
bool iza(int x, int y, int k, string res){
    if(x==y) return true;
    if(k==0) return false;

    bool r;
    if(9 < x < 100){
        r = iza(10*(x%10)+(x/10), y, k-1, res+"A");
        if(r) return true;
    }

    r=iza(10*(x%10)+(x+10), y, k-1, res+"B");
    if(r) return true;

    if(9 < x){
        r = iza(x/10, y, k-1, res+"C");
        if(r) return true;
    }

    return false;
}

//string result=""; //zmienna globalna
//
////konstuowanie rozwiazania przy zwijaniu rekurencji
//string ula(int x, int y, int k){
//    if(x==y) return " ";
//    if(k==0) return "";
//
//    string r;
//    if(9 < x < 100){
//        r=ula(10*(x%10)+(x/10),y,k-1);
//        if(r != "") return ("A"+result);
//    }
//
//    result = ula(3*x, y, k-1);
//    if(result != "") return ("B"+result);
//
//    if(9 < x){
//        result = ula(x/10, y, k-1);
//        if(r != "") return ("C"+result);
//    }
//}

int main(){

    ala(6,24,7,"");
    cout<<endl;

    cout<<ola(6,24,7,"")<<endl;
    cout<<endl;

    cout<<iza(6,24,7,"")<<endl;
    cout<<endl;

//    cout<<ula(6,24,7)<<endl;

    return 0;
}

