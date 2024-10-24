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
int main()
{
    ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n + 5];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<ll>>dp(n + 5, vector<ll>(n + 5));
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INF;
            ll ans = 0;
            for (int k = i; k < j; k++)
            {
                ans = dp[i][k] + dp[k + 1][j] + a[i - 1] * a[j] * a[k];
                dp[i][j] = min(dp[i][j], ans);
            }
        }
    }
    cout << dp[1][n - 1] << endl;
    return 0;
}
