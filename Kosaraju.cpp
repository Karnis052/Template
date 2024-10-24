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
// Find number of strongly connected component in directed graph
vector<int>adj[N], revadj[N], comp[N];
int vis[N], id[N], component = 0;
vector<int>order;
void dfs(int node)
{
	vis[node] = 1;
	for (auto it : adj[node])
	{
		if (vis[it])continue;
		dfs(it);
	}
	order.push_back(node);
}
void dfs2(int node)
{
	vis[node] = 1;
	id[node] = component;      // current node's component id
	comp[component].push_back(node); // all node under current component
	for (auto it : revadj[node])
	{
		if (vis[it])continue;
		dfs2(it);
	}
}
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	int n, m, u, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		revadj[v].push_back(u);
	}
	for (int i = 0; i < N; i++)
		vis[i] = 0;
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
			dfs(i);
	}
	reverse(order.begin(), order.end());
	for (int i = 0; i < N; i++)
		vis[i] = 0;
	for (auto it : order)
	{
		if (!vis[it])
		{
			dfs2(it);
			component++;
		}
	}
	cout << "Number of connected component  is " << component << endl;

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}