#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline int msbp(int x) {return 31-__builtin_clz(x);}
inline int msb(int x) {return 1 << msbp(x);}
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 1e5+10, M = 998244353, S = 3e5+10;

int add(int a, int b) {return (a+b)%M;}
int sub(int a, int b) {return (a+M-b)%M;}
int mult(ll a, ll b) {return (a*b)%M;}
int fastPowMod(int base, int power) {
    if(power == 0) return 1;
    if(power & 1) return mult(base, fastPowMod(base, power-1));
    return fastPowMod(mult(base, base), power/2);
}
int divd(int a, int b) {return mult(a, fastPowMod(b, M-2));}

int n, a[N], f[S], s, C, suf[S], ans; // f[i] - expected time to go from i to i+1. suf[i] - expected time to go from i to S.

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) {
    	cin >> a[i];
    	s += a[i];
    }
    REP(i, s) {
    	if(i == 0) f[0] = n-1;
    	else f[i] = divd(add(1, mult(divd(i, s), f[i-1])), mult(divd(s-i, s), divd(1, n-1)));
    }
    FORD(i, s-1, 0) suf[i] = add(suf[i+1], f[i]);
    C = suf[0];
    REP(i, n) ans = add(ans, suf[a[i]]);
    ans = sub(ans, mult(C, n-1));
    ans = divd(ans, n);
    cout << ans << endl;

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
// - not clearing DS between test cases EVEN FOR INPUT (WA, RTE, TLE, MLE)
