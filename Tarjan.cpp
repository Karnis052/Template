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
// Tarjan Algorithm for strongly connected components
vector<int>adj[N];
vector<vector<int>>scc;
int vis[N], instack[N], disc[N], lw[N], timer = 0;
stack<int>stck;
void dfs(int node)
{
	vis[node] = 1;
	disc[node] = lw[node] = timer++;
	instack[node] = 1;
	stck.push(node);
	for (auto it : adj[node])
	{
		if (!vis[it])
		{
			dfs(it);
			lw[node] = min(lw[it], lw[node]);
		}
		else if (instack[it])
			lw[node] = min(lw[node], disc[it]);
	}
	if (disc[node] == lw[node])
	{
		vector<int>cur;
		while (1)
		{
			int u = stck.top(); stck.pop();
			cur.push_back(u);
			instack[u] = false;
			if (u == node)
				break;
		}
		scc.push_back(cur);
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
	}
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
			dfs(i);
	}
	cout << scc.size() << endl;
	for (int i = 0; i < scc.size(); i++)
	{
		for (int j = 0; j < scc[i].size(); j++)
			cout << scc[i][j] << " ";
		cout << endl;
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}