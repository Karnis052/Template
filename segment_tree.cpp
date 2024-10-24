

int a[N], tr[4 * N];
struct ST {

	ST(int n)
	{
		for (int i = 0; i < 4 * n; i++) tr[i] = 0;
	}
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
		tr[node] = max(tr[node << 1], tr[node << 1 | 1]);
	}
	void update(int node, int l, int r, int idx, int val)
	{
		if (l > idx or r<idx or l>r) return;
		if (l == r and l == idx)
		{
			tr[node] = val;
			return;
		}
		int mid = (l + r) / 2;
		update(node << 1, l, mid, idx, val);
		update(node << 1 | 1, mid + 1, r, idx, val);
		tr[node] = max(tr[node << 1], tr[node << 1 | 1]);
	}
	int query(int node, int l, int r, int lb, int rb)
	{
		if (l > r or l > rb or r < lb) return -INF;
		if (lb <= l and r <= rb)
			return tr[node];
		int mid = (l + r) / 2;
		int le = query(node << 1, l, mid, lb, rb);
		int rig = query(node << 1 | 1, mid + 1, r, lb, rb);
		return max(le, rig);
	}
};







/*// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int, int>PI;
typedef pair<ll, ll > PL;
typedef vector<int>VI;
typedef vector<ll>VL;
#define FF first
#define SS second
#define sz size()
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 2e5 + 5;
ll a[N], tr[4 * N];
void build(int node, int l, int r)
{
	if (l == r)
	{
		tr[node] = a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(node << 1, l, mid);
	build(node << 1 | 1, mid + 1, r);
	tr[node] = tr[node << 1] + tr[node << 1 | 1];

}
void update(int node, int l, int r, int pos, ll val)
{
	if (l > r or l > pos or r < pos)
		return ;
	if (l == pos and l == r )
	{
		tr[node] = val;
		a[pos] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(node << 1, l, mid, pos, val);
	update(node << 1 | 1, mid + 1, r, pos, val);
	tr[node] = tr[node << 1] + tr[node << 1 | 1];
}
ll  query(int node, int l, int r, int lb, int rb)
{
	if (l > r or l > rb or r < lb)
		return 0;
	if (lb <= l and r <= rb)
		return tr[node];
	int mid = (l + r) / 2;
	ll  ans1 = query(node << 1, l, mid, lb, rb);
	ll ans2  = query(node << 1 | 1, mid + 1, r, lb, rb);
	return ans1 + ans2;
}
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	ll n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)cin >> a[i];
	build(1, 1, n);
	while (q--)
	{
		ll type, l, r;
		cin >> type >> l >> r;
		if (type == 1)
			update(1, 1, n, l, r);
		else
		{
			ll val = query(1, 1, n, l, r);
			cout << val << endl;
		}
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}*/