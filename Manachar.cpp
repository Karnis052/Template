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
// Manachar algorithm find longest palindrome of a string in O(N)
int main()
{
  ios::sync_with_stdio(false);   cin.tie(0);
  int n;
  string s1, ns = "";
  cin >> s1;
  for (int i = 0; i < s1.size(); i++)
  {
    ns += '#';
    ns += s1[i];
  }
  ns += "#";
  n = ns.size();
  vector<int>pal(n);
  int rb = 0, cen = 0;
  for (int i = 0; i < n; i++)
  {
    int mir = cen - (i - cen);
    if (i < rb)
      pal[i] = min(rb - i, pal[mir]);
    int l = i - pal[i] - 1, r = i + pal[i] + 1;
    while (l >= 0 and r < n and ns[l] == ns[r])
      pal[i]++, l--, r++;
    if (i + pal[i] > rb)
    {
      rb = i + pal[i];
      cen = i;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, pal[i]);
  cout << ans << endl;
  return 0;
}