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
using namespace std;
#define int long long
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

int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

// Finds constants {u, v} s.t. a*u+b*v = g for g = gcd(a, b)
// Call with egcd(a, b)
pii egcd(int a, int b, pii x = {1, 0}, pii y = {0, 1}) {
	return (b == 0) ? x : egcd(b, a % b, y, {x.first - a/b * y.first, x.second - a/b * y.second});
}

// Finds x s.t. (a*x) % n == 1
// Assumes a is not zero divisor (i.e. gcd(a, n) == 1)
int modInv(int a, int n) {
	return ((egcd(a, n).first % n) + n) % n;
}

const int N = 1010, M = 998244353;
int n, m, g[N][N], r, c;
pair<int, pii> vals;

struct frac {
	int n, d;
	
	void simp() {
		int gc = gcd(n, d);
		n /= gc, d /= gc;
		n %= M;
	}

	frac(int in_n, int in_d) {
		n = in_n, d = in_d;
		simp();
	}
	frac(int in_n) {n = in_n, d = 1;}
	frac() {n = 0, d = 1;}

	frac operator+(frac& other) {return frac(other.d*n+other.n*d, other.d*d);}
	frac operator-(frac& other) {return frac(other.d*n-other.n*d, other.d*d);}
	frac operator*(frac& other) {return frac(other.n*n, other.d*d);}
	frac operator/(frac& other) {return frac(other.d*n, other.n*d);}

};

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> g[i][j];
    cin >> r >> c;
    FOR(i, 1, n) FOR(j, 1, m) vals[(i-1)*m+(j-1)] = {g[i][j], {i, j}};
    sort(vals, vals+n*m);
    frac s(vals[0].first), ps;
    FOR(i, 1, n*m) {
    	if(vals[i].first != vals[i-1].first) {
    		s = s+ps;
    		ps = frac(0, 1);
    	} else {
    		ps = ps+frac(vals[i].first);
    	}
    }
    cout << s.n*modInv(s.d, M) << endl;

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
