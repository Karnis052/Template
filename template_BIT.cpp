// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int, int> PII;
const int mod = 1e9 + 7, INF = 1e9;
const int N = 1e5 + 5;
ll a[N], tree[N], n;
// 1 base indexing
void update(int idx , int val)
{
    while (idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
ll query(int idx)
{
    ll sum = 0;
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //  int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int i, j;
        cin >> i >> j;
        /// for online  (query, update) function work properly
        ll ans  = query(j) - query(i - 1);
        cout << ans << "\n";
    }
    return 0;
}



