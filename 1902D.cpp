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
const int N = 2e5 + 5;
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	string s1;
	cin >> s1;
	//vector<map<int, int>>pre;
	map<PI, vector<int>>mp;
	// L = x-1, R = x+1, U = y+1 D = y-1
	int x = 0, y = 0;
	mp[ {x, y}].push_back(0);
	for (int i = 0; i < n; i++)
	{
		if (s1[i] == 'L')
			x -= 1;
		else if (s1[i] == 'R')
			x += 1;
		else if (s1[i] == 'U')
			y += 1;
		else y -= 1;
		mp[ {x, y}].push_back(i + 1);
	}
	for (auto [pos, idx] : mp)
	{
		cout << pos.FF << " " << pos.SS << "     ";
		for (auto it : idx)
			cout << it << " ";
		cout << endl;
	}





	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}