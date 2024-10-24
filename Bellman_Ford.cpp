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
const ll INF = 1e9;
const int N = 1e5 + 5;
// Find negative weight cycle in a graph

struct info {
	int u, v, wei;
};
info edge[N];
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> edge[i].u >> edge[i].v >> edge[i].wei;
	int src = 1, des = n; // shortest path from src to des
	vector<ll>dist(n + 5, INF); // Any circle (Not necessarily from src) set
	//dist value 0 for all node
	vector<int>par(n + 5, -1); // path retrieval
	dist[src] = 0;
	int last;
	for (int i = 0; i < n; i++)
	{
		last = -1;
		for (int j = 0; j < m; j++)
		{
			if ( dist[edge[j].u] < INF)
			{
				if (dist[edge[j].v] > dist[edge[j].u] + edge[j].wei)
				{
					dist[edge[j].v] =  max(-INF, dist[edge[j].u] + edge[j].wei); // adopted for overflow
					par[edge[j].v] = edge[j].u;
					last = edge[j].v;
				}
			}
		}
	}
	if (last == -1)
	{
		cout << "No negative cycle found" << endl;
		cout << "Minimum distance Sorce to destination is " << dist[des] << endl;

	}
	else
	{
		int y = last;
		for (int i = 0; i < n; i++)
			y = par[y];
		vector<int>path;
		for (int i = y; ; i = par[i])
		{
			path.push_back(i);
			if (i == y and path.size() > 1)
				break;
		}
		reverse(path.begin(), path.end());
		cout << "Negative  weight cycle is" << endl;
		for (auto it : path)
			cout << it << " ";
	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}

// Time complexity O(VE)
//Space complextiy O(V)