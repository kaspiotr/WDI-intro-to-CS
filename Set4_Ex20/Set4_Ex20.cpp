
//identyczne zadanie jak 21, dosłownie, ponieważ w obu przypadkach szukamy 2 wież gdzie max_sum zaszachowanych pól

void policz (int t[N][N]){
	
	int sum_w[N],sum_k[N];
	//zerowanie obu powyższych tablic
	//int x=0,y=0//numer kolumny i wiersza do usuniecia
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			sum_w[i]+=t[i][j];
			sum_k[i]+=t[j][i];

		}	
	
}
int gain(int t[N][N], int k1, int w1, int k2, int w2){
	if(w1 == w2){ 
		// stoją w tym samym wierszu, jedyny zysk to kolumna p2 i 
		// pole, na którym stoi wieża 1, bo dotychczas nie było szachowane.
		// Odejmuje pole p2, bo jest już zliczone jako szachowane przez wieżę 1
		return sums_col[k2] - t[w2][k2] + t[w1][k1];
	}
	
	// różna kolumna i wiersz. Odejmuje przecięcia oraz pole w2,k2,
	// bo zostałoby policzone dwukrotnie a nie powinno być liczone wcale
	return sums_col[k2] + sums_row[w2] - 2 * t[w2][k2] - t[w1][k2] - t[w2][k1];
}

//zakładam że indeks w tablicy w[] jest numerem kolumny a wartość numerem wiersza

void moja (int t[N][N]. int w[N]){
	policz(t);
	int sum=0, sum_max=0;
	int x1=0,y1=0,x2=0,y2=0;
	for(int i=0;i<N;i++){
		sum=sum_k[i]+sum_w[w[i]]-2*t[w[i]][i];
		for(int j=0;j<N;j++){
			sum2=sum + gain(t,i,w[i],j,w[j]);
		
			if(sum2>sum_max){
				sum_max=sum;
				x1=w[i];
				y1=i;
				x2=w[j];
				y2=j;
		}
		}
		
	}
	cout<<x1<<y1<<x2<<y2<<endl;
	//w[y]=-1; //gdybyśmy mogli modyfikować tablice w[]
					
	
}


