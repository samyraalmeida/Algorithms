// Dijkstra - Shortest Path in a Graph
// Complexity: O(m*log n)
// Code by Samyra Almeida

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int maxn=1e3+10;

int n, m, dist[maxn];
vector<ii> graph[maxn];

void dijkstra(int u)
{
	memset(dist, 0x3f3f3f3f, sizeof dist);
	dist[u] = 0;

	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push({0, u});

	while(!pq.empty())
	{
		int w, at;  tie(w, at) = pq.top();  pq.pop();

		if(w > dist[at]) continue;

		for(ii node: graph[at])
		{
			int ww, v;  tie(ww, v) = node;

			if(dist[v] > dist[at] + ww)
			{
				dist[v] = dist[at] + ww;

				pq.push({dist[v], v});
			}
		}
	}
}

int main()
{
	return 0;
}