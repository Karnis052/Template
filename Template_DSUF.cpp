// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;

vector<int> par, ran;
vector<pair<int, int>>pr;

int find_set(int v)
{
    if (par[v] == v)
        return v;
    return par[v] = find_set(par[v]);
}
void union_sets(int u, int v)
{
    if (ran[u] < ran[v]) swap(u, v);
    par[v] = u;
    if (ran[u] == ran[v])
        ran[u]++;
}

bool find_cycle()
{
    for (auto it : pr)
    {
        int from = find_set(it.first), to = find_set(it.second);
        if (from == to)
            return true;
        union_sets(from, to);
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    par.clear(); par.resize(n + 4);
    ran.clear(); ran.resize(n + 5);
    for (int i = 0; i <= n; i++)
        par[i] = i, ran[i] = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        pr.push_back({u, v});
    }
    if ( find_cycle())
    {
        cout << "Find Cycle\n";
    }
    else cout << "No cycle\n";
    return 0;
}

