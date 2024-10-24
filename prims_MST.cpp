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
vector<pair<int, int>>adj[N];
int vis[N], par[N];
//Find minimum spanning tree
//Time complexity O(E*logE)
//Space complexity O(V^2)
int main()
{
  ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
  int n, m, u, v, wei;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> wei;
    adj[u].push_back({v, wei});
    adj[v].push_back({u, wei});
  }
  priority_queue<PI>pq;
  pq.push({ -0, 1});
  ll minspaning = 0 ;
  while (!pq.empty())
  {
    int node = pq.top().SS, len = -1 * pq.top().FF;
    pq.pop();
    if (vis[node]) continue;
    minspaning += len;
    vis[node] = 1;
    for (auto it : adj[node])
    {
      if (!vis[it.FF])
      {
        pq.push({ -it.SS, it.FF});
        par[it.FF] = node;
      }
    }
  }
  cout << minspaning << endl;
  for (int i = 2; i <= n; i++)
    cout << par[i] << " " << i << endl;
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}