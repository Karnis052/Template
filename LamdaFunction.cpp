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
const int INF = 2e9;
const int N = 1e5 + 5;


int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	//<return type (input parameter type)> name of the function
	function<bool(int)>parity = [&](int x) {
		return (x & 1);
	};
	cout << parity(2) << endl;
	cout << parity(3) << endl;

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
