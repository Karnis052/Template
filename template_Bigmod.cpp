// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int, int> PII;
const int mod =  998244353;
#define MAX ((int)1e9+5)
const int N = 2e5 + 5;
ll fact[N], in_fact[N];
ll bigmod(ll a, ll b)
{
    if (b == 0) return 1;
    ll ans = bigmod(a, b / 2);
    ans = (ans * ans) % mod;
    if (b & 1)
        ans = a * ans % mod;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % mod;
    in_fact[N - 1] = bigmod(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) in_fact[i] = in_fact[i + 1] * (i + 1) % mod;
    for (int i = 0; i < 5; i++) cout << in_fact[i] << " ";
    // cout << bigmod(6, mod - 2) << endl;
    return 0;
}

