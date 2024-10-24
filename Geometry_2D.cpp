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
const  int INF = 1e9;
const int N = 1e5 + 5;
const double inf = 1e100;
const double eps = 1e-9;
const double pi = acos((double) - 1.0);
int sign(double x) { return (x > eps)  - (x < -eps); }
struct PT {
	double x, y;
	PT() { x = 0, y = 0 ;}
	PT(double x, double y): x(x), y(y) {}
	PT(const PT &a): x(a.x) , y (a.y) {}
	PT operator +(const PT &a)   			 const { return PT(x + a.x, y + a.y); }
	PT operator -(const PT &a)    			 const { return PT(x - a.x, y - a.y); }
	PT operator *(const double a)  			 const { return PT(a * x, a * y); }
	PT operator /(const double a)  			 const { return PT(x / a, y / a); }
	bool operator == (PT a)   				 const { return (sign(a.x - x) == 0 and sign(a.y - y) == 0); }
	bool operator != (PT a)  				 const { return !(*this == a); }
	bool operator <(PT a)      				 const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
	bool operator > (PT a)                   const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
	PT perpendicular()                             { return PT(-y, x); }
	double arg()                                   { return atan2(y, x); }
	double normal()                                { return sqrt(x * x + y * y);}
};

double dot(PT a, PT b)                { return a.x * b.x + a.y * b.y; }
double dist2(PT a, PT b)              { return dot(a - b, a - b); }
double dist(PT a, PT b)               { return (sqrt(dot(a - b, a - b))); }
double cross(PT a, PT b)			  { return a.x * b.y - a.y * b.x; }
double cross2(PT a, PT b, PT c)       { return cross(b - c, c - a); }
double angle(PT a, PT b)              { return acos(max((double) - 1.0, min((double)1.0, dot(a, b) / a.normal() / b.normal())));}



// rotation of a point around origin
PT RotateCCW90(PT a)             { return PT(-a.y, a.x);}
PT RotateCW90(PT a)               { return PT(a.x, -a.y); }
PT RotateCCW(PT a, double t)      { return PT(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t));}
PT translation(PT a, PT b)        { return PT{a.x + b.x, a.y + b.y};}

double SQ(double x)        { return x * x ;}
double deg_to_rad(double d) { return (d * pi / 180.0);}
double rad_to_deg(double c) { return (c * 180.0) / pi;}

void debug(PT a)
{
	cout << a.x << " " << a.y << endl;
}
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	int x1, y1, x2, y2, factor = 2;
	cin >> x1 >> y1 >> x2 >> y2 >> factor;
	PT p1(x1, y1);
	PT p2(x2, y2);
	double an = angle(p1, p2);
	cout << an << endl;
	//debug(p1);
	return 0;
}
