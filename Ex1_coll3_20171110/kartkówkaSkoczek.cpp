// kartkówkaSkoczek.cpp : Defines the entry point for the console application.
/*Dana jest tablica int t[N][N], prosze sprawdzić ile jest par pól w tablicy 
takich że ich iloczyn jest równy zadanemu n a odległość między polami jest równa 
skokowi skokczka szachowego
*/

#include "stdafx.h"
#include <iostream>
int const N = 5;
using namespace std;

bool isPossible (int array[N][N],int w, int k, int newW, int newK, int product)
{
	return (newK < N  && newW < N && array[w][k] * array[newW][newK] == product);
}

int numOfPairs(int array[N][N], int product)
{
	int newW, newK,count;
	newW = newK = count = 0;
	for (int w = 0; w < N; w++)
	{
		for (int k = 0; k < N; k++)
		{
			newW = w + 2;
			newK = k + 1;
			if (isPossible(array, w, k, newW, newK, product)) count++;
			if (isPossible(array,w, newK, newW, k, product)) count++;
			newW = w + 1;
			newK = k + 2;
			if (isPossible(array, w, k, newW, newK, product)) count++;
			if (isPossible(array, newW, k, w, newK,product))count++;
		}
	}
	return count;
}

int main()
{
	int array[N][N] = 
	{
		{2,1,2,5,3},
		{3,1,3,2,5},
		{5,3,4,2,2},
		{1,2,8,3,3},
		{8,5,3,1,1}
	};
	int result = numOfPairs(array, 6);
	cout << result << endl;
    return 0;
}

