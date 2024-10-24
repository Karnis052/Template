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
	int n, W;
	cin >> n >> W;
	int a[n], wt[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	vector<vector<int>>dp(n + 5, vector<int>(W + 5, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (wt[i - 1] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + a[i - 1]);
			else dp[i][j] = dp[i - 1][j];

		}
	}
	cout << dp[n][W] << endl;
	return 0;
}
