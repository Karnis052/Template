// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;
vector<int>adj[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v, w;
    cin >> n >> m;
    vector<vector<int>>dist(n + 2, vector<int>(n + 2, INF)); // store minimum distance from i to j vertex
    for (int i = 1; i <= m; i++) // Take input in a matricx
    {
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    for (int i = 0; i < n; i++) // ensure source to source 0 distance
        dist[i][i] = 0;
    for (int k = 0; k < n; k++) // trying to place every vertex as a connecting vertex
        for (int i = 0; i < n; i++) // source vertex
            for (int j = 0; j < n; j++) // destination
                if (dist[i][k] < INF and dist[k][j] < INF)
                    dist[i][j]  = min(dist[i][j], dist[i][k] + dist[k][j]);
    for (int i = 0; i < n; i++)
        if (dist[i][i] < 0)
        {
            cout << "Negative cycle found \n";
            return 0;
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dist[i][j] << " ";
        cout << "\n";
    }
    // Time complexity O(vertex^3);
    return 0;
}

