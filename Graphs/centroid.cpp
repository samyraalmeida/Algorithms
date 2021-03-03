#include <bits/stdc++.h>

using namespace std;

const int maxn=1e3+10;

int n, mk[maxn], sub[maxn];
vector<int> graph[maxn], centroid_tree[maxn];

void dfs(int u, int f)
{
	for(int v: graph[u])
	{
		if(v == f || mk[v]) continue;
		
		dfs(v, u);  sub[u] += sub[v];
	}

	sub[u]++;
}

int get(int u, int f, int size)
{
	for(int v: graph[u])
	{
		if(v == f || mk[v]) continue;

		if(sub[v] > size / 2) return get(v, u, size);
	}

	return u;
}

int decompose(int u)
{
	memset(sub, 0, sizeof sub);

	dfs(u, 0);

	int c = get(u, 0, sub[u]);
	
	mk[c] = 1;

	for(int v: graph[c])
	{
		if(!mk[v])
		{
			int vis = decompose(v);
			
			centroid_tree[c].push_back(vis);
			centroid_tree[vis].push_back(c);
		}
	}

	return c;
}

int main()
{
	scanf("%d", &n);

	for(int i = 1 ; i < n ; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i = 1 ; i <= n ; ++i)
	{
		if(!mk[i]) decompose(i);
	}	

	for(int i = 1 ; i <= n ; ++i)
	{
		printf("%d\n ", i);

		for(int j = 0 ; j < centroid_tree[i].size() ; ++j)
		{
			if(centroid_tree[i][j]!=0) printf("%d ", centroid_tree[i][j]);
		}

		printf("\n");
	}

	return 0;
}
