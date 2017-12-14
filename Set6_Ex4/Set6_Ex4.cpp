/*Dany jest zestaw odważników int t[N]. Napisać funkcję, która sprawdza czy jest możliwe odważenie określonej masy.
Odważniki można umieszczać tylko na jednej szalce. */

bool odwaz (int odw[], int n, int c, int p){
    if (c == 0) return true;
    if (c < 0) return false;
    if (p == n) return false;

    return odwaz(odw, n, c-odw[p], p+1) || odwaz(odw, n, c, p+1);
}

int main(){
    //do sprawdzania
    int arr[] = {7, 4, 3, 9, 5, 2, 3};
    int n = 7;

    cout << odwaz(arr, n, 8, 0);
    return 0;
}
