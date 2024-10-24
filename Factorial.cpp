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
ll fact[2 * N], in_fact[2 * N];

ll bigmod(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1) res = res * a % mod;
		a  = (a * a) % mod;
		b /= 2;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = (fact[i - 1] * i) % mod;
	in_fact[N - 1] = bigmod(fact[N - 1], mod - 2);

	for (int i = N - 2; i >= 0; i--)
		in_fact[i] = in_fact[i + 1] * (i + 1) % mod;
	ll  n, r, ans = 1;
	cin >> n >> r;
	ans = in_fact[n - r] * in_fact[r] % mod;
	ans = ans * fact[n] % mod;
	cout << ans << endl;

	return 0;
}
