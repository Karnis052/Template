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
int ln = 20;
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int lg[N];
	lg[1] = 0;
	for (int i = 2; i < N; i++) lg[i] = lg[i / 2] + 1;
	vector<vector<int>>table(ln, vector<int>(n + 5, -1));
	for (int i = 1; i < ln; i++)
	{
		for (int j = 0; j + (1 << i) <= n; j++)
		{
			table[i][j] = table[i - 1][j] + table[i - 1][j + (1 << (i - 1))];
		}
	}
	int l, r;
	int i = lg[r - l + 1];
	int ans = table[i][l] + table[i][r - (1 << i) + 1];
	/*
	sum query
	int sum =0;
	for(int i= ln-1;i>=0;i--)
	{
		if((1<<i)<= r-l+1)
		{
			sum+= table[i][l];
			l+= (1<<i);
		}

	}
	*/


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}