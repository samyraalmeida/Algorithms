// Lowest Common Ancestor - LCA
// Implement using Segment Tree
// Complexity: O()
// By Samyra Vitória

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

int n, q, t, h[maxn], in[maxn], path[2*maxn], tree[4*maxn];

vector<int> graph[maxn];

void dfs(int u, int a)
{
	in[u] = ++t;
	path[t] = u;
	h[u] = h[a] + 1;

	for(int v: graph[u])
	{
		if(v==a) continue;

		dfs(v, u); path[++t] = u;
	}
}

int op(int a, int b)
{
	if(h[a] < h[b]) return a;
	else return b;
}

void build(int u, int l , int r)
{
	if(l == r) { tree[u] = path[l]; }
	else
	{
		int m = (l + r) >> 1;

		build(2*u, l , m);  build(2*u + 1, m + 1, r);

		tree[u] = op(tree[2*u], tree[2*u + 1]);
	}
}

int query(int u, int l, int r, int a , int b)
{
	if(a <= l and r <= b) { return tree[u]; }
		
	int m = (l + r) >> 1;

	if(b <= m) return query(2*u, l , m, a , b);
	if(a > m) return query(2*u + 1, m + 1, r, a, b);

	return op(query(2*u, l , m, a , b), query(2*u + 1, m + 1, r, a , b));
}

int LCA(int a , int b)
{
	if(in[a] > in[b]) swap(a, b);

	return query(1, 1, t, in[a], in[b]);
}

int main()
{    
    dfs(1, 1);

    build(1, 1, t);
    
    return 0;
}