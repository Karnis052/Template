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
#define FOR(i,n) for(int i=0;i<n; i++)
#define F0R(i,a, b) for(int i=a;i<b; i++)
#define FORd(i,n) for(int i=  n-1; i>=0;i--)
#define F0Rd(i, a, b) for(int i= b-1; i>=a; i--)
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;

ll k , dp[12][100][100][2];
vector<int>num;
ll solve(int pos, int sum, int rem, int flag)
{
	if (pos >= num.size() )
	{
		if (sum == 0 and rem == 0)
			return 1;
		else
			return 0;
	}
	if (dp[pos][sum][rem][flag] != -1)
		return dp[pos][sum][rem][flag];
	int last = num[pos];
	if (flag) last = 9;
	ll ans = 0;
	for (int i = 0; i <= last; i++)
	{
		ans += solve(pos + 1, (sum * 10 + i) % k, (rem + i) % k, flag | (i < last));
	}
	return dp[pos][sum][rem][flag] = ans;

}
ll func(int n)
{
	num.clear();
	while (n)
	{
		num.push_back(n % 10);
		n /= 10;
	}
	reverse(num.begin(), num.end());
	memset(dp, -1, sizeof(dp));
	ll ans = solve(0, 0, 0, 0);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);   cin.tie(0);
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++)
	{
		ll lb, rb;
		cin >> lb >> rb >> k;
		ll ans = 0;
		if (k < 91)
			ans = func(rb) - func(lb - 1);
		cout << "Case " << test << ": " << ans << endl;
	}
	return 0;
}