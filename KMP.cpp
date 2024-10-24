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
string s1, pat;
vector<int>lps(N);
void LPS(string s1)
{
	int k = 0;
	for (int i = 1; i < s1.size(); i++)
	{
		while (k > 0 and s1[i] != s1[k])
			k = lps[k - 1];
		if (s1[i] == s1[k])k++;
		lps[i] = k;
	}
}
void KMP(string s1, string pat)
{
	int n = s1.size(), m = pat.size();
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		while (k > 0 and s1[i] != pat[k])
			k = lps[k - 1];
		if (s1[i] == pat[k])k++;
		if (k >= m)
		{
			cout << "Found at " << i - m + 1 << endl;
			k = lps[k - 1];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	cin >> s1 >> pat;
	LPS(pat);
	KMP(s1, pat);
	return 0;
}
