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
vector<int>adj[N];
void dfs(int node)
{
  vis[node] = 1;
  for (auto it : adj[node])
  {
    if (vis[it])continue;
    dfs(it);

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
    adj[v].push_back(u);
  }
  int isconnected = 1;
  dfs(1);
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i] and adj[i].size() > 0)
      isconnected = 0;
  }
  if (!isconnected)
  {
    cout << "Graph has no Eulerian path or cycle" << endl;
    return 0;
  }
  int odd = 0;
  for (int i = 1; i <= n; i++)
    if (adj[i].size() & 1)
      odd++;
  if (odd == 2)
    cout << "Graph has a Eulerian path" << endl;
  else if (odd == 0)
    cout << "Graph has a Eulerian circuit/cycle" << endl;
  else cout << "Graph has no Eulerian path or cycle" << endl;



  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}