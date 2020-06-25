#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()

template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

typedef Point<double> P;
double ccRadius(const P& A, const P& B, const P& C) {
	return (B-A).dist()*(C-B).dist()*(A-C).dist()/
			abs((B-A).cross(C-A))/2;
}
P ccCenter(const P& A, const P& B, const P& C) {
	P b = C-A, c = B-A;
	return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}

pair<double, P> mec2(vector<P>& S, P a, P b, int n) {
	double hi = INFINITY, lo = -hi;
	rep(i,0,n) {
		auto si = (b-a).cross(S[i]-a);
		if (si == 0) continue;
		P m = ccCenter(a, b, S[i]);
		auto cr = (b-a).cross(m-a);
		if (si < 0) hi = min(hi, cr);
		else lo = max(lo, cr);
	}
	double v = (0 < lo ? lo : hi < 0 ? hi : 0);
	P c = (a + b) / 2 + (b - a).perp() * v / (b - a).dist2();
	return {(a - c).dist2(), c};
}
pair<double, P> mec(vector<P>& S, P a, int n) {
	random_shuffle(S.begin(), S.begin() + n);
	P b = S[0], c = (a + b) / 2;
	double r = (a - c).dist2();
	rep(i,1,n) if ((S[i] - c).dist2() > r * (1 + 1e-8)) {
		tie(r,c) = (n == sz(S) ?
			mec(S, S[i], i) : mec2(S, a, S[i], i));
	}
	return {r, c};
}
pair<double, P> enclosingCircle(vector<P> S) {
	auto r = mec(S, S[0], sz(S));
	return {sqrt(r.first), r.second};
}

int n;
const double eps = 1e-9;

void bad() {
	cout << -1 << endl;
	exit(0);
}

signed main() {
	srand(time(NULL));
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin >> n;
    vector<P> v(n);
    const double XL = -(1e7+1), XR = 1e7+1;
    double xl = XR, xr = XL;
    REP(i, n) cin >> v[i].x >> v[i].y;
    if(n == 1) {
    	cout << abs(v[0].y/2) << endl;
    	exit(0);
    }
    REP(i, n) {
    	xl = min(v[i].x, xl);
    	xr = max(v[i].x, xr);
    }
    pair<double, P> circ = enclosingCircle(v);
    // cout << circ.first << ' ' << circ.second.x << ' ' << circ.second.y << endl;
    if(!EQ(circ.first, abs(circ.second.y)) && circ.first > abs(circ.second.y)) bad();
    double l = xl, r = xr;
    pair<double, P> c1, c2;
    while((r-l) >= eps) {
    	double m1 = (2*l+r)/3, m2 = (l+2*r)/3;
	    P riv1(m1, 0), riv2(m2, 0);
	    v.push_back(riv1);
	    c1 = enclosingCircle(v);
	    v.pop_back();
	    v.push_back(riv2);
	    c2 = enclosingCircle(v);
	    v.pop_back();
	    if(c1.first >= c2.first) l = m1;
	    if(c1.first <= c2.first) r = m2;
    }
    P p(l, 0);
    v.push_back(p);
    circ = enclosingCircle(v);
    v.pop_back();

    // cout << circ.first << ' ' << circ.second.x << ' ' << circ.second.y << endl;
    cout << circ.first << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
