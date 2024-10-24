/*
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
int n;
ll dist2 (PI a, PI b)
{
    return 1LL * (a.FF - b.FF) * (a.FF - b.FF) + 1LL * (a.SS - b.SS) * (a.SS - b.SS);
}

pair<int, int>closest_pair(vector<pair<int, int>>pr)
{
    assert(n >= 2);
    vector<pair<pair<int, int>, int>>a(n);
    for (int i = 0; i < pr.size(); i++)
        a[i].FF = pr[i], a[i].SS = i;
    sort(a.begin(), a.end());
    ll ans = dist2(a[0].FF, a[1].FF);
    pair<int, int>rem = {0, 1};
    int lb = 0, rb = 2;
    while (rb < n)
    {
        while (lb < rb and 1LL * (a[lb].FF.FF - a[rb].FF.FF) * (a[lb].FF.FF - a[rb].FF.FF) >= ans) lb++;
        for (int i = lb; i < rb; i++)
        {
            ll cur = dist2(a[i].FF, a[rb].FF);
            if (cur < ans)
            {
                ans = cur;
                rem.FF = a[i].SS, rem.SS = a[rb].SS;
            }
        }
        rb++;
    }
    return rem;
}
int main()
{
    ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
    //cout.fixed;
    //cout.precision(7);

    cin >> n;
    vector<pair<int, int>>pr(n);
    for (int i = 0; i < n; i++)
        cin >> pr[i].FF >> pr[i].SS;
    pair<int, int>indices = closest_pair(pr);
    if (indices.FF > indices.SS) swap(indices.FF, indices.SS);
    cout << indices.FF << " " << indices.SS << " ";
    cout << fixed << setprecision(6) << sqrtl(dist2(pr[indices.FF], pr[indices.SS])) << endl;


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}*/


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
const ll INF = 1e18;
const int N = 1e5 + 5;

struct info {
    int x, y;
};
bool comp1(info a, info b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
bool comp2(info a, info b)
{
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}
ll dist2(info a, info b)
{
    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}
ll bruteForce(info px[], int n)
{
    ll ans = INF;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            ans = min(ans, dist2(px[i], px[j]));
    }
    return ans;
}


ll mindistance(info px[], info py[], int n)
{
    if (n <= 3)
    {
        return bruteForce(px, n);
    }
    int mid = n / 2;
    info midpoint = px[mid];
    info pyl[mid];
    info pyr[n - mid];
    int lb = 0, rb = 0;
    for (int i = 0; i < n; i++)
    {
        if (py[i].x < midpoint.x  or (py[i].x == midpoint.x and py[i].y < midpoint.y))
            pyl[lb++] = py[i];
        else pyr[rb++] = py[i];
    }
    ll dl = mindistance(px, pyl, mid);
    ll dr = mindistance(px + mid, pyr, n - mid);
    ll d = min(dl, dr);
    info strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if ((py[i].x - midpoint.x) * (py[i].x - midpoint.x) < d)
            strip[j++] = py[i];

    }
    ll ans = d;
    lb = 0, rb = 1;
    while (rb < j)
    {
        while (lb < rb and 1LL * (strip[lb].y - strip[rb].y) * (strip[lb].y - strip[rb].y) >= ans)
            lb++;
        for (int i = lb; i < rb; i++)
        {
            ll cur = dist2(strip[lb], strip[rb]);
            ans = min(cur, ans);
        }
        rb++;
    }
    return ans;

}

int main()
{
    ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    info a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    info px[n], py[n];
    for (int i = 0; i < n; i++)
    {
        px[i] = a[i];
        py[i] = a[i];
    }
    sort(px, px + n, comp1);
    sort(py, py + n, comp2);
    ll ans = mindistance(px, py, n);
    cout << sqrtl(ans) << endl;

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}