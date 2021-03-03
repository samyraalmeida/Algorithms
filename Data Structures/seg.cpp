// Segment in Tree - Sum
// By Samyra Almeida

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

int n, q, v[maxn], tree[4*maxn], il[4*maxn], ir[4*maxn];

int join(int a, int b) { return (a+b); }

void build(int u, int l, int r)
{
	il[u] = l, ir[u] = r;
	
	if(l==r) { tree[u]=v[l]; }
	else
	{
		int m = (l + r) >> 1;

		build(2 * u, l, m);  build(2 * u + 1, m + 1, r);

		tree[u] = join(tree[u * 2], tree[u * 2 + 1]);
	}
}
int get(int u, int l, int r)
{
	if(ir[u] < l || il[u] > r) return 0;

	if(l <= il[u] && ir[u] <= r) return tree[u];

	return join(get(u * 2, l, r), get(u * 2 + 1, l, r));
}

void up(int u, int val, int i)
{
	if(il[u] > i || ir[u] < i) return;
	
	if(il[u] == ir[u])
	{
		tree[u] += val;  v[i] = tree[u];
		return;
	}

	up(2 * u, val, i); up(2 * u + 1, val, i);

	tree[u] = join(tree[u * 2], tree[u * 2 + 1]);
}

int main()
{
	while(scanf("%d", &n) && n)
	{
		for(int i = 1 ; i <= n ; ++i) { scanf("%d", &v[i]); }

		build(1, 1, n);
		
		scanf("%d", &q);

		for(int i = 0 ; i < q ; ++i)
		{
			char id; scanf(" %c", &id);

			if(id == 'U')
			{
				int j, val;  scanf("%d%d", &j, &val);

				up(1, val, j);
			}
			else
			{
				int a, b;  scanf("%d%d", &a, &b);

				printf("%d\n", get(1, a, b));
			}
		}
	}

	return 0;
}