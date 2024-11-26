// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
const double inf = 1e18;
const double eps = 1e-9;
const double PI = acos((double) - 1.0);
int sign(double x) { return (x > eps)  - (x < -eps); }
struct PT {
	double x, y;
	PT() { x = 0, y = 0 ;}
	PT(double x, double y): x(x), y(y) {}
	PT(const PT &a): x(a.x) , y (a.y) {}
	PT operator +(const PT &a)  	const { return PT(x + a.x, y + a.y); }
	PT operator -(const PT &a)    	const { return PT(x - a.x, y - a.y); }
	PT operator *(const double a)  	const { return PT(x * a, y * a); }
	PT operator /(const double a)  	const { return PT(x / a, y / a); }
	bool operator == (PT a)   		const { return (sign(a.x - x) == 0 and sign(a.y - y) == 0); }
	bool operator != (PT a)  		const { return !(*this == a); }
	bool operator <(PT a)      		const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
	bool operator > (PT a)          const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
	PT perp()                    		  { return PT(-y, x); }
	double arg()                          { return atan2(y, x); }
	double  norm()                        { return sqrt(x * x + y * y);}
	double norm2()						  { return x * x + y * y; }


};

istream &operator >> (istream &in, PT &p)	{ return in >> p.x >> p.y; }
ostream &operator << (ostream &out, PT &p) 	{ return out << "(" << p.x << "," << p.y << ")"; }



double dot(PT a, PT b)                { return a.x * b.x + a.y * b.y; }
double dist2(PT a, PT b)              { return dot(a - b, a - b); }
double dist(PT a, PT b)               { return (sqrt(dot(a - b, a - b))); }
double cross(PT a, PT b)			  { return a.x * b.y - a.y * b.x; }
double cross2(PT a, PT b, PT c)       { return cross(b - c, c - a); }
int orientation(PT a, PT b, PT c)     { return sign(cross(b - a, c - a));}
PT perp(PT a)						  { return PT(-a.y, a.x);}
double SQ(double x)					  { return x * x; }
double deg_to_rad(double d) { return (d * PI / 180.0);}
double rad_to_deg(double c) { return (c * 180.0) / PI;}

// rotation of a point around origin
PT rotateCCW90(PT a)             { return PT(-a.y, a.x);}
PT rotateCW90(PT a)               { return PT(a.x, -a.y); }
PT rotateCCW(PT a, double t)      { return PT(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t));}
PT rotateCW(PT a, double t)      { return PT(a.x * cos(t) + a.y * sin(t), -a.x * sin(t) + a.y * cos(t));}

double angle(PT a, PT b) {
	double costhetha =  dot(a, b) / a.norm() / b.norm();
	return acos(max((double) - 1.0, min((double)1.0, costhetha)));
}

bool isPointInAngle(PT a, PT b, PT c, PT p) {
	assert(orientation(a, b, c) != 0);
	if (orientation(a, b, c) < 0) swap(b, c);
	return orientation(a, b, p) >= 0 and orientation(a, c, p) <= 0;
}

double orientatedAngle(PT a, PT b, PT c) {
	if (orientation(a, b, c) >= 0)
		return angle(b - a, c - a);
	else
		return 2 * PI - angle(b - a, c - a);
}

bool half(PT p) {
	return (p.y > 0 or (p.y == 0 and p.x < 0));
}


void polarSort(vector<PT>&v) { //sort points in counterclockwise starting from 3rd co-ordinate
	sort(v.begin(), v.end(), [](PT a, PT b) {
		return make_tuple(half(a), 0.0, a.norm2()) < make_tuple(half(b), cross(a, b), b.norm2());
	});
}


void polarSort(vector<PT>&v, PT o) {
	sort(v.begin(), v.end(), [](PT a, PT b) {
		return make_tuple(half(a - o), 0.0, (a - o).norm2()) < make_tuple(half(b - o), cross(a - o, b - o), (b - o).norm2());
	});

}


PT translation(PT a, PT b)        { return PT{a.x + b.x, a.y + b.y};}



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
