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
const int N = 3e5 + 5;
ll tr[4 * N], lazy[4 * N], fib[N], a[N];
void build(int node, int l, int r)
{
	if (l == r)
	{
		tr[node] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(node << 1, l, mid);
	build(node << 1 | 1, mid + 1, r);
	tr[node] = tr[node << 1] + tr[node << 1 | 1];
}


void rangeupdate(int node, int l, int r, int lb, int rb, ll val)
{
	if (lazy[node])
	{
		tr[node] += lazy[node] * (r - l + 1);
		if (l != r)
		{
			lazy[node << 1] += lazy[node] ;
			lazy[node << 1 | 1] += lazy[node] ;
		}
		lazy[node] = 0;

	}
	if (l > rb or r < lb) return;
	if (lb <= l and r <= rb)
	{
		tr[node] += (r - l + 1) * val ;
		if (l != r)
		{
			lazy[node << 1] += val;
			lazy[node << 1 | 1] += val ;
		}
		return;
	}
	int mid = (l + r) / 2;
	rangeupdate(node << 1, l, mid, lb, rb, val);
	rangeupdate(node << 1 | 1, mid + 1, r, lb, rb, val);
	tr[node] = tr[node << 1] + tr[node << 1 | 1];
}
ll rangequery(int node, int l, int r, int lb, int rb)
{

	if (lazy[node])
	{
		tr[node] += lazy[node] * (r - l + 1);
		if (l != r)
		{
			lazy[node << 1] += lazy[node] ;
			lazy[node << 1 | 1] += lazy[node] ;
		}
		lazy[node] = 0;

	}
	if (l > r or l > rb or r < lb) return 0;
	if (lb <= l and r <= rb)
		return tr[node];
	int mid = (l + r) / 2;
	ll val1 = rangequery(node << 1, l, mid, lb, rb);
	ll val2 = rangequery(node << 1 | 1, mid + 1, r, lb, rb);
	return (val1 + val2);
}
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	int n, m, coun = 1;
	cin >> n >> m;
	fib[0] = fib[1] = 1;
	for (int i = 2; i < N; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	while (coun <= m)
	{

		ll type, lb, rb;
		cin >> type >> lb >> rb;
		if (type == 1)
		{
			rangeupdate(1, 1, n, lb, rb, fib[coun - lb]);
		}
		else
		{
			ll val = rangequery(1, 1, n, lb, rb);
			cout << val << endl;
		}
		coun++;
	}
	return 0;
}
