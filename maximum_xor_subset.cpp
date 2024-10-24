//Given an array of number. Find maximum sebset xor of the array

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
#define sz size()
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;

ll check_bit(ll x, ll idx)
{
    return ((x >> idx) & 1);
}

ll gaussian_elimination(vector<ll>a)
{
    int n = a.size();
    int idx = 0;
    for (ll bit = 62; bit >= 0; bit--)
    {
        int i = idx;
        while (i < n and (check_bit(a[i], bit) == 0))
            i++;
        if (i == n) continue;
        swap(a[i], a[idx]);
        for (int j = 0; j < n; j++)
        {
            if (j != idx and check_bit(a[j], bit))
                a[j] ^= a[idx];
        }
        idx++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans ^= a[i];
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<ll>a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    ll ans = gaussian_elimination(a);
    cout << ans << endl;


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}