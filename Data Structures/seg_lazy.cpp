// Seg with Lazy
// Complexity(get): O(log n)
// Complexity(update): O(log n)
// By Samayra Vitória

#include <bits/stdc++.h>

using namespace std;

const int maxn=100100;

typedef long long ll;

int t, n, q, c, num[maxn], ir[4*maxn], il[4*maxn];
ll tree[4*maxn], lazy[4*maxn];

void refresh(int u)
{
	if(lazy[u] == 0LL) return;

	if(ir[u] != il[u])
	{
		lazy[2 * u] += lazy[u];
		lazy[2 * u + 1] += lazy[u];
	}

	tree[u] += lazy[u] * (ir[u] - il[u] + 1LL);
	lazy[u] = 0LL;
}

void build(int u, int l, int r)
{
	ir[u] = r, il[u] = l;

	if(l == r) tree[u] = 0LL;
	
	else
	{
		int mid = (l + r) >> 1;

		build(u * 2,l, mid); build(u * 2 + 1, mid + 1, r);

		tree[u] = tree[2 * u] + tree[2 * u + 1];
	}
}

void up(int u, int l, int r, ll val)
{
	refresh(u);

	if(il[u] > r || ir[u] < l) return;

	if(il[u] >= l && ir[u] <= r)
	{	
		lazy[u] += val; refresh(u);
		return;
	}

	up(2 * u, l, r, val); up(2 * u + 1, l, r, val);

	tree[u] = tree[2 * u] + tree[2 * u + 1];
}

int get(int u, int l, int r)
{
	if(il[u] > r || ir[u] < l) return 0LL;

	refresh(u);
	
	if(il[u] >= l && ir[u] <= r) { return tree[u]; }

	return get(2 * u, l, r) + get(2 * u + 1, l, r);
}

int main()
{
	scanf("%d", &n);

	for(int i = 1 ; i <= n ; ++i) { scanf("%d", &num[i]); }

	build(1, 1, n);
	
	scanf("%d", &q);

	for(int i = 0 ; i < q ; ++i)
	{
		char id;  int a, b;
		scanf(" %c%d%d", &id, &a, &b);

		if(id=='U')
		{
			int val;  scanf("%d", &val);
			
			up(1, a, b, val);
		}
		else { printf("%d\n", get(1, a, b)); }
	}

	return 0;
}