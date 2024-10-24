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
int tr[N];
void update(int idx, int val)
{
	while (idx < N)
	{
		tr[idx] = max(tr[idx], val);
		idx += (idx & -idx);
	}
}
int query(int idx)
{
	int sum = 0;
	while (idx > 0)
	{
		sum = max(sum, tr[idx]);
		idx -= (idx & -idx);
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	int n, ans = 0;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		int  cur = query(a[i] - 1);
		update(a[i], cur + 1);
		ans = max(ans, cur + 1);
	}
	cout << ans << endl;


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}