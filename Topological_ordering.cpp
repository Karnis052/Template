// Bismillahir Rahmanir Rahim
/*#include<bits/stdc++.h>
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
// Topological odering in Directed acyclic graph. Graph must be acyclic
int color[N], cyclic;
vector<int>adj[N], order;
void dfs(int node)
{
	col[node] = 1;
	for (auto it : adj[node])
	{
		if (col[it]==0)
		dfs(it);
		else if(col[it]==1)
		cyclic =1;
	}
	col[node] =2;
	order.push_back(node);
}
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	int n, m, u, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 0; i < n; i++)
	{
		if (!col[i])
		{
			dfs(i);
		}
	}
	if(cyclic){
	cout<<"Graph is cyclic"<<endl;
	return  0;
	}
	reverse(order.begin(), order.end());
	for (auto it : order)
		cout << it << " ";
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}*/


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
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	int n, m, u, v;
	cin >> n >> m;
	vector<int>inorder(n + 5), vis(n + 5);
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		inorder[v]++;
	}
	queue<int>qu;
	for (int i = 1; i <= n; i++)
		if (inorder[i] == 0)
			qu.push(i), vis[i] = 1;
	vector<int>ordering;
	while (!qu.empty())
	{
		int node = qu.front(); qu.pop();
		ordering.push_back(node);
		for (auto it : adj[node])
		{
			if (!vis[it])
			{
				inorder[it]--;
				if (inorder[it] == 0)
					qu.push(it), vis[it] = 1;
			}
		}
	}
	for (auto it : ordering)
		cout << it << " ";
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}