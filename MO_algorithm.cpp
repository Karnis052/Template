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
const int N = 2e5 + 5;
int a[N], block;
ll cnt[N], ans[N];
// 1 base indexing
struct info
{
	int lb, rb, idx;
	info () {}
	info(int x, int y, int i)
	{
		lb = x, rb = y, idx = i;
	}
}; info query[N];

bool comp(info q1, info q2)
{
	if (q1.lb / block != q2.lb / block)
		return q1.lb / block < q2.lb / block;
	return q1.rb > q2.rb;
}

int main()
{
	ios::sync_with_stdio(false);   cin.tie(0);

	int n, t, x, y;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	block = sqrt(n);
	for (int i = 0; i < t; i++)
	{
		cin >> x >> y;
		query[i].lb = x, query[i].rb = y, query[i].idx = i;
	}
	sort(query, query + t, comp);
	info cur;
	int left = query[0].lb, right = query[0].lb - 1;
	ll val = 0;
	int c1;
	for (int i = 0; i < t; i++)
	{
		while (query[i].lb < left)
		{
			left--;
			c1 = a[left];
			val -= (cnt[c1] * cnt[c1] * c1);
			cnt[c1]++;
			val += (cnt[c1] * cnt[c1] * c1);

		}
		while (query[i].lb > left)
		{
			c1 = a[left];
			val -= (cnt[c1] * cnt[c1] * c1);
			cnt[c1]--;
			val += (cnt[c1] * cnt[c1] * c1);
			left++;

		}
		while (query[i].rb > right)
		{
			right++;
			c1 = a[right];
			val -= (cnt[c1] * cnt[c1] * c1);
			cnt[c1]++;
			val += (cnt[c1] * cnt[c1] * c1);
		}
		while (query[i].rb < right)
		{
			c1 = a[right];
			val -= (cnt[c1] * cnt[c1] * c1);
			cnt[c1]--;
			val += (cnt[c1] * cnt[c1] * c1);
			right--;
		}
		ans[query[i].idx] = val;

	}
	for (int i = 0; i < t; i++)
		cout << ans[i] << "\n";
	return 0;
}