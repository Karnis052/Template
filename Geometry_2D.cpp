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
	PT operator +(const PT &a)const  	  { return PT(x + a.x, y + a.y); }
	PT operator -(const PT &a)const    	  { return PT(x - a.x, y - a.y); }
	PT operator *(const double a)const    { return PT(x * a, y * a); }
	PT operator /(const double a)const    { return PT(x / a, y / a); }
	bool operator == (PT a)const          { return (sign(a.x - x) == 0 and sign(a.y - y) == 0); }
	bool operator != (PT a)const 		  { return !(*this == a); }
	bool operator <(PT a)const 			  { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
	bool operator > (PT a)const 		  { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
	PT perp()                    		  { return PT(-y, x); }
	double arg()                          { return atan2(y, x); }
	double  norm()                        { return sqrt(x * x + y * y);}
	double norm2()						  { return x * x + y * y; }


};

istream &operator >> (istream &in, PT &p)	{ return in >> p.x >> p.y; }
ostream &operator << (ostream &out, PT &p) 	{ return out << "(" << p.x << "," << p.y << ")"; }




PT translate(PT a, PT b)        { return PT{a.x + b.x, a.y + b.y};}
PT scale(PT c, double factor, PT p) { return  PT{c.x + (p.x - c.x)*factor, c.y + (p.y - c.y)*factor	};}


double dot(PT a, PT b)                { return a.x * b.x + a.y * b.y; }
bool isPerpendicular(PT a, PT b)      { return dot(a, b) == 0;}
double dist(PT a, PT b)               { return (sqrt(dot(a - b, a - b))); }
double dist2(PT a, PT b)              { return dot(a - b, a - b); }
double cross(PT a, PT b)			  { return a.x * b.y - a.y * b.x; }
double cross2(PT a, PT b, PT c)       { return cross(b - a, c - a); }
int orientation(PT a, PT b, PT c)     { return sign(cross(b - a, c - a));}
PT perp(PT a)						  { return PT(-a.y, a.x);}
double SQ(double x)					  { return x * x; }
double deg_to_rad(double d) { return (d * PI / 180.0);}
double rad_to_deg(double c) { return (c * 180.0) / PI;}

// rotation of a point around origin
PT rotateCCW90(PT a)             { return PT(-a.y, a.x);}
PT rotateCW90(PT a)               { return PT(a.y, -a.x); }
PT rotateCCW(PT a, double t)      { return PT(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t));}
PT rotateCW(PT a, double t)      { return PT(a.x * cos(t) + a.y * sin(t), -a.x * sin(t) + a.y * cos(t));}

double angle(PT a, PT b) {
	double costhetha =  dot(a, b) / a.norm() / b.norm();
	return acos(max((double) - 1.0, min((double)1.0, costhetha)));
}

bool isPointInAngle(PT a, PT b, PT c, PT p) {  // does point p lie in angle <bac
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
	assert(p.x != 0 || p.y != 0);
	return (p.y > 0 or (p.y == 0 and p.x < 0));
}


void polarSort(vector<PT>&v) { //sort points in counterclockwise starting from 3rd co-ordinate
	sort(v.begin(), v.end(), [](PT a, PT b) {
		return make_tuple(half(a), 0.0, a.norm2()) < make_tuple(half(b), cross(a, b), b.norm2());
	});
}


void polarSort(vector<PT>&v, PT o) { // sort points in counterclockwise with respect to point o instead of origin (0,0)
	sort(v.begin(), v.end(), [&](PT & a, PT & b) {
		return make_tuple(half(a - o), 0.0, (a - o).norm2()) < make_tuple(half(b - o), cross(a - o, b - o), (b - o).norm2());
	});

}


bool isConvex(vector<PT>p) {
	bool hasPos = false, hasNeg = false;
	for (int i = 0, n = p.size(); i < n; i++) {
		int orient = orientation(p[i], p[(i + 1) % n], p[(i + 2) % n]);
		if (orient > 0) hasPos = 1;
		if (orient < 0)  hasNeg = 1;
	}
	return !(hasPos & hasNeg);
}

struct line {
	PT v; double c;
	line() {v = {0, 0}; c = 0;}
	line(PT v, double c): v(v), c(c) {} // v = direction vector of line = (b, -a)
	line(double a, double b, double c): v(b, -a), c(c) {}  // from equation ax+by=c
	line(PT p, PT q): v(q - p), c(cross(v, p)) {} // V = (b,-a) = PQ and PQ = q-p, c = (V x P)

	// side(P)>0 if on the left, side(P) <0 if on the right, 0 if on the line
	int side_of_point_respect_to_line(PT p)   { return cross(v, p) - c; } // for point P = (x, y) and  side(P) = ax + by-c => (V x P) - c
	double dist_from_point_to_line(PT p)      { return abs(cross(v, p) - c) / v.norm(); } //distance = |a·x + b·y - c| / |v|   => (|side(p)|) / |v|
	double sqDist_from_point_to_line(PT p)    { return ((cross(v, p) - c) * (cross(v, p) - c) / v.norm2());}
	line perpThrough(PT p)                    { return {p, p + perp(v)}; }
	bool cmpProj(PT p, PT q)                  { return dot(v, p) < dot(v, q); }  //sort along line
	line translate(PT t)  					  { return {v, c + cross(v, t)}; } // translate line l by vector vector(t)

	line shiftLeft(double dist)               { return {v, c + dist * v.norm()}; }
	PT proj(PT p)					          { return p - perp(p) * side_of_point_respect_to_line(p) / v.norm2(); }
	PT refl(PT p) 							  { return  p - perp(p) * 2 * side_of_point_respect_to_line(p) / v.norm2(); }

};

line bisector(line l1, line l2, bool interior)
{
	assert(cross(l1.v, l2.v) != 0);
	double sign = interior ? 1 : -1 ;
	return { l2.v / l2.v.norm() + l1.v / l1.v.norm()*sign,
	         l2.c / abs(l2.c) + l1.c / abs(l1.c)*sign };
}


// Point P on the disk of diameter [AB] if angle is <=90 degree
bool inDisk(PT a, PT b, PT p)
{
	return dot(a - p, b - p) <= 0;
}

// Point P on the segment [AB] if lies on the line AB and inDisk of [AB]
bool onSegment(PT a, PT b, PT p)
{
	return orientation(a, b, p) == 0  and inDisk(a, b, p);
}

//find two segment [AB] and [CD] has proper intersection
bool segment_segment_intersection(PT a, PT b, PT c, PT d, PT &out)
{
	double oa = orientation(c, d, a);
	double ob = orientation(c, d, b);
	double oc = orientation(a, b, c);
	double od = orientation(a, b, d);

	// proper intersection exist iff opposite sign
	if (oa * ob < 0 and oc * od < 0)
	{
		out = (a * ob - b * oa) / (ob - oa); // intersection point
		return true;
	}
	return false;
}

struct cmpX {
	bool operator()( const PT &a, const PT b) const {
		return make_pair(a.x, a.y) < make_pair(b.x, b.y);
	}
};
// s size 0 = no intersection, s size 1 = proper or one end intersection, s size 2 = stays within line

set<PT, cmpX> segment_segment_intersection_inside(PT a, PT b, PT c, PT d) {
	PT out;
	if (segment_segment_intersection(a, b, c, d, out)) return {out};
	set<PT, cmpX>s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return s;
}
double segment_point_distance(PT a, PT b, PT p)
{
	if (a != b) {
		line l(a, b);
		if (l.cmpProj(a, p) and l.cmpProj(p, b)) // if closest to projection
			return l.dist_from_point_to_line(p);  // output distance to line

	}
	return min((p - a).norm(), (p - b).norm());
}

double segement_segment_distance(PT a, PT b, PT c, PT d)
{
	PT dummy;
	if (segment_segment_intersection(a, b, c, d, dummy)) return 0;
	return min({
		segment_point_distance(a, b, c), segment_point_distance(a, b, d),
		segment_point_distance(c, d, a), segment_point_distance(c, d, b)
	});
}
double areaTriangle(PT a, PT b, PT c) {
	return abs(cross(b - a, c - a)) / 2.0;
}

double areaPolygon(vector<PT>p) {
	double  area = 0.0;
	for (int i = 0, n = p.size(); i < n; i++)
	{
		area += cross(p[i], p[(i + 1) % n]);
	}
	return abs(area) / 2.0;
}

bool above(PT a, PT p)
{
	return p.y >= a.y;
}

bool crossesRay(PT a, PT p, PT q)
{
	return (above(a, q) - above(a, p)) * orientation(a, p, q) > 0;
}

// Point a is in polygon area, on boundary, out of boundary
bool inPolygon(vector<PT>p, PT a, bool strict = true)
{
	int numCrossings = 0;
	for (int i = 0, n = p.size(); i < n; i++)
	{
		if (onSegment(p[i], p[(i + 1) % n], a))
			return !strict;
		numCrossings += crossesRay(a, p[i], p[(i + 1) % n]);

	}
	return numCrossings & 1;

}

double angleTravelled(PT a, PT p, PT q)
{
	double ampli = angle(p - a, q - a);
	if (orientation(a, p, q) > 0) return ampli;
	else return -ampli;
}

struct angleType {
	PT d; int t = 0;
	angleType(PT d): d(d) {}
	angleType(PT d, int t): d(d), t(t) {}
	angleType t180() { return {d*(-1), t + half(d)}; }
	angleType t360() { return {d, t + 1}; }
};

bool operator<(const angleType a, const angleType b) {
	return make_tuple(a.t, half(a.d), 0) < make_tuple(b.t, half(b.d), cross(a.d, b.d));
}



angleType moveTo(angleType a, PT newD)
{
	assert(!onSegment(a.d, newD, {0, 0}));
	angleType b{newD, a.t};
	if (a.t180() < b)
		b.t--;
	if (b.t180() < a)
		b.t++;
	return b;
}

int windingNumber(vector<PT>p, PT x)
{
	angleType a(x);
	for (PT d : p)
		a = moveTo(a, d);
	return a.t;
}

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




// signed length of the projection of vector(w) onto the line that contains vector(v)