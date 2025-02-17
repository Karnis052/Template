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
const int N = 1e3 + 5;
// Shortest path between all pair of vertices
ll dp[N][N];
int main()
{
  ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
  int n, m, u, v, wei;
  cin >> n >> m;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      dp[i][j] = INF;
  for (int i = 0; i < N; i++)
    dp[i][i] = 0;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> wei;
    dp[u][v] = wei;
    dp[v][u] = wei; /// for undirected graph;
  }


  for (int k = 0; k < n; k++)
  { for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
        if (dp[i][k] < INF and dp[k][j] < INF) // For negative weight edge
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << dp[i][j] << " ";
    cout << endl;
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}

// Time complexity O(V^3)