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
const int N = 15;
int cost[N][N], dp[1 << N][N];
int n, m;
int TSP(int mask, int pos)
{
	if (mask == (1 << n) - 1)
	{
		return cost[pos][0];
	}
	if (dp[mask][pos] != -1)
		return dp[mask][pos];
	int ans = INF;
	for (int i = 0; i < n; i++)
	{
		if ((mask & (1 << i)) == 0)
		{
			ans = min(ans, TSP(mask | (1 << i), i) + cost[pos][i]);
		}

	}
	return dp[mask][pos] = ans;

}
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	int  u, v, wei;
	cin >> n >> m;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cost[i][j] = INF;
	}
	for (int i = 0; i < (1 << n); i++)
		for (int j = 0; j < n; j++) dp[i][j] = -1;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> wei;
		cost[u][v] = wei;
		cost[v][u] = wei;
	}
	ll ans = TSP(0, 0);
	cout << ans << endl;

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}