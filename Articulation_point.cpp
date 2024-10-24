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
int st[N], lw[N], timer = 1;
vector<int>ac;
void dfs(int node, int an)
{
  st[node] = lw[node] = timer++;
  int child = 0;
  for (auto it : adj[node])
  {
    if (it == an) continue;
    if (st[it] != 0)
      lw[node] = min(lw[node], st[it]);
    else
    {
      child++;
      dfs(it, node);
      if (st[node] <= lw[it] and node != 1)
        ac.push_back(node);
      lw[node] = min(lw[node], lw[it]);
    }
  }
  if (node == 1 and child > 1) ac.push_back(node);
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
  dfs(1, -1);
  for (auto it : ac)
    cout << it << " ";
  cout << endl;
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}