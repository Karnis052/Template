// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int,int> PII;
const int mod = 1e9+7;
const int INF = 1e9;
const int N = 1e5+5;
vector<int>adj[N];
bool vis[N];
int n, m;
void dfs(int node)
{
    vis[node] =1;
    for(auto it : adj[node])
    {
        if( !vis[it])
        dfs(it);
    }
}
bool connected()
{
    int root =-1;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size() >0)
        {
            root = i; break;
        }
    }
    if(root == -1 )
        return true;
    dfs(root);
    for(int i=1;i<= n;i++)
    {
        if(!vis[i] and adj[i].size()>0)
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int  u,v;
    cin>>n>>m;
    for(int i=0;i<n+4;i++)
    {
        adj[i].clear(); vis[i] =0;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool f1=1;
    if(!connected() ) f1 =0;
    int odd =0;
    for(int i=1;i<=n;i++)
    {
        if((int) adj[i].size()& 1) odd++;
    }
    if(odd>2 or !f1)
        cout<<"Graph don't having  Euler circuit and Euler path\n";
    else if(odd== 2 and f1)
        cout<< "Graph is a Eulerian path or semi Eulerian circuit\n";
    else
        cout<<"Graph is a Eulerian circuit\n";

    return 0;
}

