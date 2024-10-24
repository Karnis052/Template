// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int, int>PI;
typedef pair<ll, ll > PL;
typedef vector<int>VI;
typedef vector<ll>VL;
#define FF first
#define SS second
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;
vector<pair<int, ll>>adj[N];
int n, m;
//Find shortest path from source to all other vertices in a weighted graph
//Time complexity O(ElogV)
//Space Complexity O(V)
void dijkstra(int sc)
{
	priority_queue<pair<ll, int>>pq; // (dist, node)
	vector<ll> dist(n + 5, INF);
	vector<int>level(n + 5);
	pq.push({0, sc});
	dist[sc] = 0;
	while (!pq.empty())
	{	auto cur = pq.top(); pq.pop();
		ll len = -cur.FF, node = cur.SS;
		if (len > dist[node])continue;
		for (auto it : adj[node])
		{
			ll nlen = dist[node] + it.SS, v = it.FF;
			if (dist[v] > nlen)
			{
				dist[v] = nlen;
				level[v] = level[node] + 1;
				pq.push({ -nlen, v});
			}
		}
	}
	cout << "Shortest path form source to all other node " << endl;
	for (int i = 1; i <= n; i++)
		cout << dist[i] << " ";
	cout << endl;
}
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	ll u, v, cost;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> cost;
		adj[u].push_back({v, cost});
		adj[v].push_back({u, cost});
	}
	int sc = 1;
	dijkstra(sc);
	return 0;
}




/*void Dijkstra(int sc)
{
	vector<ll>dist(N, INF), level(N);
	priority_queue<pair<ll, int>>pq;
	pq.push({0, sc});
	dist[sc] = 0;
	while (!pq.empty())
	{
		auto it = pq.top(); pq.pop();
		int u = it.SS; ll  cost = -it.FF;
		if (cost > dist[u]) continue;
		for (auto it : adj[u])
		{
			int v = it.FF; ll nwei = it.SS;
			if (dist[v] > dist[u] + nwei)
			{
				dist[v] = dist[u] + nwei;
				level[v] = level[u] + 1;
				pq.push({ - dist[v], v});
			}
		}
	}
}*/