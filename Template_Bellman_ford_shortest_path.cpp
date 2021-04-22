// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;
vector<int>par, dist;
struct  edge {         // To store edge
    int a, b, cost;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<edge>adj(m);            // edge struct type vector, Rem: compare edge with int
    par.clear(); par.resize(n + 5, -1);
    dist.clear() ; dist.resize(n + 5, INF);
    for (int i = 0; i < m; i++)
    {
        cin >> adj[i].a >> adj[i].b >> adj[i].cost;
    }
    int src, des; cin >> src >> des;
    bool f1 = 0;
    dist[src] = 0;
    for (int i = 0; i < n; i++) // Take  every vertex as a source
    {
        f1 = 1;
        for (int j = 0; j < m; j++) // try to explore all it's connected edge
        {
            if ( dist[adj[j].a] < INF and dist[adj[j].b]> dist[adj[j].a] + adj[j].cost )
            {
                dist[adj[j].b] = dist[ adj[j].a] + adj[j].cost;
                par[adj[j].b] = adj[j].a;
                f1 = 0;
            }
        }
        if (f1) break;
    }
    if (dist[des] == INF)
        cout << "No path from source node to destination\n";
    else
    {
        cout << dist[des] << "\n";
        vector<int>ans;
        for (int cur = des ; cur != -1; cur = par[cur])
            ans.push_back(cur);
        reverse(ans.begin(), ans.end());
        for (auto it : ans)
            cout << it << " ";
    }
    // Time complexity O(VE)
    return 0;
}

