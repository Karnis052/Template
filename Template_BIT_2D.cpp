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
const int N = 1e3 + 5;

int n, m, tree[N][N];
void update(int x, int y, int val)
{
	while (x <= n)
	{
		int y1 = y;
		while (y1 <= m)
		{
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}
int query(int x, int y)
{
	int sum = 0;
	while (x > 0)
	{
		int y1 = y;
		while (y1 > 0)
		{
			sum += tree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m;
	int a[n + 5][m + 5];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			update(i, j, a[i][j]);
		}
	}
	int q;
	cin >> q;
	while (q--)
	{
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		x1++, y1++, x2++, y2++;
		int ans  = query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
		cout << ans << endl;
	}

	return 0;
}
