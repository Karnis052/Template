// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int,int> PII;
const int mod = 1e9+7;
const int INF = 1e9;
const int N = 1e5+5;
vector<int>adj[N], disc, low;
vector<pair<int,int>>ans;
int timer;
void dfs(int node, int par)
{
    low[node] = disc[node] = timer++;
    for(auto it : adj[node])
    {
        if(it== par) continue;
        if(disc[it]!=-1)
            low[node] = min(low[node], disc[it]);
        else
        {
            dfs(it, node);
            low[node] = min(low[node], low[it]);
            if(low[it]> disc[node])
            ans.push_back({node, it});
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,u,v;
    cin>>n>>m;
    disc.clear(); disc.resize(n+4,-1);
    low.clear(); low.resize(n+4,-1);
    timer =0;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(disc[i]==-1)
         dfs(i, -1);
    for(auto it: ans)
        cout<< it.first<<" "<< it.second<<"\n";
    return 0;
}

