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

int vis[N];
vector<pair<int, int>>adj[N];
vector<int>order;
void dfs(int node)
{
	vis[node] = 1;
	for (auto it : adj[node])
	{
		if (vis[it.FF]) continue;
		dfs(it.FF);
	}
	order.push_back(node);
}
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	int n, m, u, v, wei;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> wei;
		adj[u].push_back({v, wei});
	}
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			dfs(i);
		}
	}
	reverse(order.begin(), order.end());
	int src = 0;
	vector<ll>dist(n + 5, INF);
	dist[src] = 0;
	for (int i = 0; i < order.size(); i++)
	{
		for (auto it : adj[order[i]])
		{
			if (dist[it.FF] > dist[order[i]] + it.SS)
				dist[it.FF] = dist[order[i]] + it.SS;
		}
	}
	for (int i = 0; i < n; i++)
		cout << dist[i] << " ";
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}