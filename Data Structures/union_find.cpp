// Disjoint sets: Union-find - Using Rank and Path Compression Optimizations 
// Complexity(find): O(log n)
// Complexity(join): O(log n)
// By Samyra Almeida

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int n, uf[maxn], rk[maxn];

int find(int u)
{
	if(uf[u] == u) return u;
	else return uf[u] = find(uf[u]);
}

void join(int u, int v)
{
	u = find(u); v = find(v);

	if(u == v) return;
	
	if(rk[u] > rk[v]) swap(u, v);

	uf[u] = v;
	rk[v] += (rk[u] == rk[v]);
}

int main()
{
	for(int i = 1 ; i <= n ; ++i) uf[i] = i;
	
	memset(rk, 0, sizeof rk);
	
	return 0;
}