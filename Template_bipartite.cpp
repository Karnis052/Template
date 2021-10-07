// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int,int> PII;
const int mod = 1e9+7;
const int INF = 1e9;
const int N = 1e5+5;
vector<int>adj[N], col;
bool bipartite ;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,u,v;
    cin>>n>>m;
    col.clear(); col.resize(n+4,-1);
    bipartite =1;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        {
            if(col[i]==-1)
            {
                queue<int>q;
                q.push(i);
                col[i] =0;
                while(!q.empty())
                {
                    int p = q.front();
                        q.pop();
                    for(auto it : adj[p] )
                    {
                        if(col[it]==-1)
                        {
                            col[it] = col[p]^1;
                            q.push(it);
                        }
                        else if(col[it]== col[p])
                            bipartite =0;
                    }
                }
            }
        }
        if(! bipartite)
            cout<<"Graph is not bipartite\n";
        else cout<< "Graph is bipartite\n";
    return 0;
}

