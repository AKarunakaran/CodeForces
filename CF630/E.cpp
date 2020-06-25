#include <bits/stdc++.h>
using namespace std;
#define int long long
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
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int M = 998244353, HALF = 499122177;

int half(int l, int r) {return ((r-l+1)+1)/2;}
int add(int a, int b) {return (a+b)%M;}
int sub(int a, int b) {return (a+M-b)%M;}
int mult(int a, int b) {return (a*b)%M;}

int fastPowMod(int base, int power) {
	base %= M;
    int res = 1;
    while(power) {
        if(power & 1) res = mult(res, base);
        base = mult(base, base);
        power >>= 1;
    }
    return res;
}

// a #even, b #odd
int n, m, l, r, a, b, p;

int solve_even() {
	return mult(HALF, add(fastPowMod(add(b, a), p), fastPowMod(abs(b-a), p)));
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> l >> r;
    a = half(((l+1)/2)*2, (r/2)*2), b = half((l/2)*2 + 1, ((r+1)/2)*2-1);
	p = n*m;
    if(p & 1) cout << fastPowMod(add(a, b), p) << endl;
    else cout << solve_even() << endl;

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
