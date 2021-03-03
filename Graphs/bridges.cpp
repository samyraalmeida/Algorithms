// Bridges in a graph - Algotithm
// Complexity: O(n + m)
// By Samyra Vitória

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10;

struct ed
{
	int x, y;

	bool operator<(const ed& o) const
	{
		if(o.x != x) { return x < o.x; } else { return y < o.y; }
	}
};

int n, m, t, mk[maxn], ft[maxn], low[maxn], s[maxn];

vector<int> graph[maxn];
vector<ed> bridges;

void dfs(int u)
{
	mk[u] = 1;
	low[u] = s[u] = ++t;

	for(auto v: graph[u])
	{
		if(!mk[v])
		{
			ft[v] = u;
			dfs(v);
			low[u] = min(low[u], low[v]);

			if(low[v] > s[u])
			{
				if(v > u) bridges.push_back({u, v});
				else bridges.push_back({v, u});
			}
		}
		else if(v != ft[u]) { low[u]=min(low[u], s[v]); }
	}
}

int main()
{
	return 0;
}
