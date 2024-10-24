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
const double pi = acos((double) - 1.0);
struct PT {
	double x, y;
	PT() {x = 0; y = 0;}
	PT(double x, double y): x(x), y(y) {}
	PT(const PT &a): x(a.x), y(a.y) {}
	PT operator +(const PT &a)    			const { return PT(x + a.x, y + a.y); }
	PT operator -(const PT &a)				const {return PT(x - a.x, y - a.y);}
	PT operator *(const double a)			const {return PT(x * a, y * a);}
	PT operator /(const double a)  			const { return PT(x / a, y / a); }
};
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	PT p1(x1, y1);
	PT p2(x2, y2);
	p1 = p1 - p2;
	cout << p1.x << " " << p1.y << endl;
	cout << pi << endl;
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}