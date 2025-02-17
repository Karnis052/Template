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
int n, m;
ll mincost = 0;
vector<int>par(N), ra(N);

struct info {
  ll u, v, wei;
  bool operator<(const info& other)const
  {
    return wei < other.wei;
  }
};
info adj[N];

int get(int u)
{
  if (par[u] == u)
    return u;
  return par[u] = get(par[u]);
}

void merge(int u, int v)
{
  u = get(u), v = get(v);
  if (ra[v] > ra[u]) swap(u, v);
  par[v] = u;
  if (ra[u] == ra[v])
    ra[u]++;
}


void Kruskal()
{
  int cost, u, v;
  for (int i = 0; i < m; i++)
  {
    u = adj[i].u; v = adj[i].v;
    cost = adj[i].wei;
    if (get(u) != get(v))
    {
      mincost += cost;
      merge(u, v);
    }
  }
}


int main()
{
  ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);

  cin >> n >> m;
  ll u, v, wei;
  for (int i = 0; i <= n; i++)par[i] = i;
  for (int i = 0; i < m; i++)
  {
    //cin>>u>>v>>wei;
    cin >> adj[i].u >> adj[i].v >> adj[i].wei;
  }
  sort(adj, adj + m);
  Kruskal();
  cout << mincost << endl;
  return 0;
}
