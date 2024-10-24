// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef __int128  ll;
typedef pair<int, int>PI;
typedef pair<ll, ll > PL;
typedef vector<int>VI;
typedef vector<ll>VL;
#define FF first
#define SS second
#define sz size()
const int mod = 1e9 + 7;
const int INF = 1e9;
const ll N = 1e18;
//everything should be read by read function and write with write function variation
// ll is define as __int128
// select C++ 20 (64)

ll read()
{
  ll w = 0, h = 1; char ch = getchar();
  while (ch < '0' || ch > '9') {if (ch == '-')h = -h; ch = getchar();}
  while (ch >= '0' && ch <= '9') {w = w * 10 + ch - '0'; ch = getchar();}
  return w * h;
}
void write(ll x)//print
{
  if (x > 9)write(x / 10);
  putchar(x % 10 + '0');
}
void writeln(ll x) {write(x); puts("");}// print with end line
void writech(ll x) {write(x); putchar(' ');}// print with space


int main()
{

  int q;
  q = read();
  while (q--)
  {
    ll l, r;
    l = read(), r = read();
    ll ans = 0;
    //ll ans = (calc(r) - calc(l - 1) + mod) % mod;
    writeln(ans);

  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}