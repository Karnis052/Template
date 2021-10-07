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
const int N = 1e6 + 5;
int ca[N], cb[N], len[N], tr[N], lazy[N];

/*void build(int node, int l, int r)
{
    if(l==r)
    {
        tr[node] = a[l];
        return ;
    }
    int mid =(l+r)/2;
    build(node<<1, l, mid);
    build(node<<1|1, mid+1, r);
    tr[node] = gcd(tr[node<<1],tr[node<<1|1]);
 
}
int query(int node, int l, int r, int lb, int rb)
{
        if(l>r or l>rb or r<lb)
        return 0;
        if(lb<= l and r<= rb)
             return tr[node];
        int mid = (l+r)/2;
        int ans1 = query(node<<1, l, mid, lb, rb);
        int ans2  = query(node<<1|1, mid+1, r, lb, rb);
        int ans  = gcd(ans2, ans1);
        return ans;
}*/
 
void upd(int id, int val)
{
	lazy[id] = 1;
	tr[id] = val;
}
 
void shift(int id, int l, int r)
{
	//int mid = (l + r) / 2;
	upd(id << 1, tr[id]);
	upd(id << 1 | 1, tr[id]);
	lazy[id] = 0;
}
 
void update(int id, int l, int r, int lb, int rb, int val)
{
	if (lb > r or rb < l)
		return ;
	if (lb <= l and r <= rb)
	{
		upd(id, val);
		return;
	}
	if (lazy[id])
		shift(id, l, r);
	int mid = (l + r) / 2;
	update(id << 1, l, mid, lb, rb, val);
	update(id << 1 | 1, mid + 1, r, lb, rb, val);
}
 
int get(int id, int l, int r, int pos)
{
	if (l == r)
		return tr[id];
	if (lazy[id])
		shift(id, l, r);
	int mid = (l + r) / 2;
	if (pos <= mid)
		return get(id << 1, l, mid, pos);
	else return get(id << 1 | 1, mid + 1, r, pos);
}

int main()
{
	ios::sync_with_stdio(false);   cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	int a[n], b[n];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= m; i++)
	{
		int type;
		cin >> type;
		if (type == 2)
		{
			int pos;
			cin >> pos;
			//pos--;
			int col = get(1, 1, n, pos);
			if (col == 0)
				cout << b[pos] << endl;
			else {
				//cout << pos - cb[col] + ca[col] << " ";
				cout << a[pos - cb[col] + ca[col]] << endl;
			}
		}
		else
		{
			cin >> ca[i] >> cb[i] >> len[i];
			//ca[i]--; cb[i]--;
			update(1, 1, n, cb[i], cb[i] + len[i] - 1, i);
 
		}
	}
 
	return 0;
}