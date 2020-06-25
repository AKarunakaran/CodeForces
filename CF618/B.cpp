#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 1e5+10;

const double EPS = 1e-8;
const double PI = acos(-1.0);

struct CPoint { 
	ll x, y;
	bool operator==(CPoint oth) {return x == oth.x && y == oth.y;}
	bool operator!=(CPoint oth) {return !(*this == oth);}
 };
const CPoint origin{0, 0};
double sqr(double x) { return x * x; }
int dcmp(ll x) {
    if (x < -EPS) return -1; else return (x > EPS);
}
ll cross(CPoint p0, CPoint p1, CPoint p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
double dot(CPoint p0, CPoint p1, CPoint p2) {
    return (p1.x - p0.x) * (p2.x - p0.x) + (p1.y - p0.y) * (p2.y - p0.y);
}
double dissqr(CPoint p1, CPoint p2) {
    return sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
}
double dis(CPoint p1, CPoint p2) {
    return sqrt(dissqr(p1, p2));
}
int PointEqual(const CPoint &p1, const CPoint &p2) {
    return dcmp(p1.x - p2.x) == 0 && dcmp(p1.y - p2.y) == 0;
}
CPoint pminus(CPoint p1, CPoint p2) {return CPoint{p1.x-p2.x, p1.y-p2.y};}

int n;
CPoint p[N];

void bad() {
	cout << "NO" << endl;
	exit(0);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> p[i].x >> p[i].y;
    if(n & 1) bad();
    p[n] = p[0];
    int half = n/2;
    REP(i, half) if(pminus(p[i], p[i+1]) != pminus(p[half+i+1],p[half+i])) bad();
	cout << "YES" << endl;
	exit(0);

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE) CHECK IF IT SHOULD BE 2*N!!!!
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
