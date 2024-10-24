// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
const ll  INF = 1e12;
const int N = 1e5 + 5;
const int   ln = 20;
int depth[N], par[ln][N];
vector<int>adj[N];
bool vis[N];
void dfs(int node )
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it])
            continue;
        depth[it] = depth[node] + 1;
        par[0][it] = node;
        dfs(it);
    }
}
int LCA(int u, int v)
{
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = ln - 1; i >= 0; i--)
    {
        if (depth[u] - (1 << i) >= depth[v])
            u = par[i][u];
    }

    if (u == v) return u;
    for (int i = ln - 1; i >= 0; i--)
    {
        if (par[i][u] != -1 and par[i][u] != par[i][v])
        {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n , q = 1, m, u, v;
    cin >> n >> q;
    for (int i = 0; i < ln; i++)
        for (int j = 0; j < N; j++)
            par[i][j] = -1;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    for (int i = 1; i < ln; i++)
    {
        for (int j = 0; j < n + 3; j++)
        {
            if (par[i - 1][j] != -1)
                par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
    return 0;
}

int ln = 20;
vector<int>adj[N];
struct LCA {

    vector<int>vis, depth;
    vector<vector<int>>par;
    LCA(int n)
    {
        vis.resize(n + 5); depth.resize(n + 5);
        par.resize(ln, vector<int>(n + 5, -1));

    }

    void dfs(int node)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (vis[it])continue;
            depth[it] = depth[node] + 1;
            par[0][it] = node;
            dfs(it);
        }
    }
    void calc(int n)
    {
        for (int i = 1; i < ln; i++)
        {
            for (int j = 0; j < n + 3; j++)
            {
                if (par[i - 1][j] != -1)
                    par[i][j] = par[i - 1][par[i - 1][j]];
            }
        }
    }
    int get(int u, int v)
    {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = ln - 1; i >= 0; i--)
        {
            if (depth[u] - (1 << i) >= depth[v])
                u = par[i][u];
        }

        if (u == v) return u;
        for (int i = ln - 1; i >= 0; i--)
        {
            if (par[i][u] != -1 and par[i][u] != par[i][v])
            {
                u = par[i][u];
                v = par[i][v];
            }
        }
        return par[0][u];
    }

};