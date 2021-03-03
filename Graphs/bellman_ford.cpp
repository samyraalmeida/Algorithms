#include <bits/stdc++.h>

using namespace std;

const int maxm = 1e5+10, maxn = 1e5+10, inf = 0x3f3f3f3f;

struct node { int a, b, w; };

node graph[maxm];
int n, m, dist[maxn];

bool bellman(int u)
{
	memset(dist, inf, sizeof dist);
	dist[u] = 0;

	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= m ; ++j)
		{
			int d = dist[graph[j].b];

			dist[graph[j].b] = min(d, dist[graph[j].a] + graph[j].w);
	
			if(i == n && dist[graph[j].b] != d) return false;
		}
	}

	return true;
}

int main()
{
	return 0;
}