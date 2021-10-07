// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int, int> pi;
typedef pair<ll, ll > pl;
typedef vector<int>vi;
typedef vector<ll>vl;
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;
#define FOR(i,n) for(int i=0;i<n; i++)
#define F0R(i,a, b) for(int i=a;i<b; i++)
#define FORd(i,n) for(int i=  n-1; i>=0;i--)
#define F0Rd(i, a, b) for(int i= b-1; i>=a; i--)
int n, m,  mat[17][17];
int dp[17][(1 << 17)];
int solve(int pos, int mask)
{
    if (mask == (1 << n) - 1)
    {
        return mat[pos][0];
    }
    if (dp[pos][mask] != -1)
        return dp[pos][mask];
    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        if (mat[pos][i] == INF) continue;
        if ((mask & (1 << i)) == 0)
        {
            int newmask = mask | (1 << i);
            int val = solve(i, newmask) + mat[pos][i];
            ans  = min(ans, val);
        }
    }
    return dp[pos][mask] = ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int  u, v, wei;
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) mat[i][j] = INF;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> wei;
        mat[u][v] = wei;
        mat[v][u] = wei;
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][i] =  mat[i][i] = 0;
    }
    int ans  = solve(0, 1);
    cout << ans << endl;
    return 0;
}
