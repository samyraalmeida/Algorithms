// Binary Indexed Tree - BIT
// Complexity(sum): O(log n)
// Complexity(update): O(log n)
// By Samyra Almeida

#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;

int n, max_v, bit[maxn];

int bit_sum(int idx)
{
	int sum = 0;
	
	while(idx > 0)
	{
		sum += bit[idx];
		idx -= (idx&-idx);
	}

	return sum;
}

void bit_upd(int idx, int val)
{	
	while(idx <= max_v)
	{	
		bit[idx] += val;
		idx+=(idx&-idx);
	}
}

int main()
{
	return 0;
}