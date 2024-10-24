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
    int n, sum;
    cin >> n >> sum;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll>dp(sum + 5);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j <= sum; j++)
            dp[j] += dp[j - a[i]];

    }
    //for (int i = 1; i <= sum; i++)cout << dp[i] << " ";
    cout << dp[sum] << endl;

    return 0;
}
