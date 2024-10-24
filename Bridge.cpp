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
vector<int>adj[N];
vector<PI>pr;
int st[N], lw[N], timer = 1;
void dfs(int node, int an)
{
	st[node] = lw[node] = timer++;
	for (auto it : adj[node])
	{
		if (it == an) continue;
		if (lw[it] != 0)
			lw[node] = min(lw[node], st[it]);
		else
		{
			dfs(it, node);
			if (st[node] < lw[it])
				pr.push_back({node, it});
			lw[node] = min(lw[node], lw[it]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	int n, m, u, v;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	timer = 1;
	dfs(1, -1);
	//cout << n << endl;
	for (auto it : pr)
		cout << it.FF << " " << it.SS << endl;

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}