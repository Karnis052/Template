// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;
vector<vector<int>>dp;
string s1, s2;
int n, m;
int solve(int i, int j)
{
	if (min(i, j) == 0)
		return max(i, j);
	if (dp[i][j] != -1)
		return dp[i][j];
	if (s1[i] == s2[j] ) dp[i][j] = solve(i - 1, j - 1);
	else
		dp[i][j] = 1 + min({ solve(i - 1, j - 1), solve(i - 1, j), solve(i, j - 1)});
	return dp[i][j];

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> s1 >> s2;
	n = s1.size(), m = s2.size();
	s1 = "#" + s1;
	s2 = "#" + s2;
	dp.clear(); dp.resize(n + 5, vector<int>(m + 5, -1));
	int ans = solve(n, m);
	cout << ans << "\n";
	return 0;
}
