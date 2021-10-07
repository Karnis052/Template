// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;
// Number of different substring using prefix function

vector<int> prefix_func(string &s1)
{
	int sz = s1.size(), k = 0;
	vector<int>lps(sz, 0);
	for (int i = 1; i < sz; i++)
	{
		while (k > 0 and s1[k] != s1[i])
			k = lps[k - 1];
		if (s1[k] == s1[i])k++;
		lps[i] = k;
	}
	return lps;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s1, s2;
	cin >> s1;
	ll ans = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		s2 =  s1[i] + s2;
		reverse(s2.begin(), s2.end());
		vector<int>vt = prefix_func(s2);
		int mx = 0;
		for (int j = 0; j <= i; j++)
		{
			mx = max(mx, vt[j]);
		}
		ans += (i + 1) - mx;

	}
	cout << ans << "\n";
	// Time complexity O(n^2)
	return 0;
}
