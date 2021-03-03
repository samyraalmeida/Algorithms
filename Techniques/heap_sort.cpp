// Heap Sort
// buildHeap: O(log n)
// buildMaxHeap: O(log n * (n/2))
// heapSort: O(log n * ((n/2) + n))
// By Samyra Almeida

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int n, vet[maxn];

void build(int u, int x)
{
	int e = u + u + 1, d = u + u + 2;
	int largest = u;

	if(e < x && vet[largest] < vet[e]) largest = e;
	if(d < x && vet[largest] < vet[d]) largest = d;

	if(u != largest)
	{
		int g = vet[u];
		vet[u] = vet[largest];  vet[largest] = g;

		build(largest, x);
	}
}

void MaxHeap(int x)
{
	int s = x >> 1;
	
	for(int i = s ; i >= 0 ; --i)  build(i, x);
}

int heapSort(int x)
{
	MaxHeap(x);

	for(int i = x - 1 ; i >= 1 ; --i)
	{
		int k = vet[i];
	    
		vet[i] = vet[0];  vet[0] = k;  x--;
		
		build(0, x);
	}
}

int main()
{
	scanf("%d", &n);

	for(int i = 0 ; i < n ; ++i) scanf("%d", &vet[i]);

	heapSort(n);

	for(int  i = 0 ; i < n ; ++i) printf("%d ", vet[i]);

	printf("\n");
	return 0;
}