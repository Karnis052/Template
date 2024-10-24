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
const int N = 1e5 + 5;
struct info
{
	ll a[2][2] = {{0, 0}, {0, 0}};
	info operator *(const info &other)const
	{
		info rem;
		for (int i = 0; i < 2; i++)
			for (int j =  0; j < 2; j++)
				for (int k = 0; k < 2; k++)
					rem.a[i][k] = (rem.a[i][k] + (a[i][j] * other.a[j][k]) % mod) % mod;

		return rem;
	}
};
info mat, pro;

void Matix_MUL(ll b)
{
	for (int i = 0; i < 2; i++)pro.a[i][i] = 1;
	while (b > 0)
	{
		if (b & 1)
			pro = pro * mat;
		mat = mat * mat;
		b >>= 1;
	}
}
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0);

	ll n;
	cin >> n;
	mat.a[0][0] = 0;
	mat.a[0][1] = 1;
	mat.a[1][0] = 1;
	mat.a[1][1] = 1;
	Matix_MUL(n);
	cout << fixed << setprecision(12) << pro.a[1][0] << endl;

	return 0;
}