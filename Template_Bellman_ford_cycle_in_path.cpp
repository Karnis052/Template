// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int,int> PII;
const int mod = 1e9+7;
const int INF = 1e9;
const int N = 1e5+5;
vector<int>par, dist;
struct edge{
int  a, b, cost;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<edge>adj(m);
    par.clear(); par.resize(n+5, -1);
    dist.clear(); dist.resize(n+5, INF);
    for(int i=0;i<m;i++)
    {
        cin>> adj[i].a>> adj[i].b >> adj[i].cost;
    }
    int src,des, last ; cin>> src>> des;
    dist[ src] =0;
    for(int i=0;i<n;i++)
    {
        last =-1;
        for(int j=0;j<m;j++)
        {
            if( dist[adj[j].a< INF and dist[adj[j].b] > dist[adj[j].a]] + adj[j].cost )
            {
                dist[adj[j].b] =  max(-INF, dist[adj[j].a] + adj[j].cost);/// To check overflow
                par[adj[j].b] = adj[j].a;
                last = adj[j].b;
            }
        }
    }
    if(last==-1) cout<<"No negative cycle found\n";
    else
    {
        for(int i=0;i<n;i++)
             last = par[last];
        vector<int>path;
        for(int cur= last; ; cur = par[cur])
        {
            path.push_back(cur);
            if( cur== last and path.size()> 1)
                break;
        }
        cout<< "The negative cycle is :\n";
        reverse(path.begin(), path.end());
        for(auto it : path)
            cout<< it<<" ";
    }
    return 0;
}

