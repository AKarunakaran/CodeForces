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
// const int nINF = INT_iN;
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_iN;

/////////////////////////////////////////////////////////////////////

const int N = 2e5+10, M = 998244353;

int add(int a, int b) {return (a+b)%M;}
int sub(int a, int b) {return (a+M-b)%M;}
int mult(ll a, ll b) {return (a*b)%M;}
int fastPowMod(int base, int power) {
    int res = 1;
    while(power) {
        if(power & 1) res = mult(res, base);
        base = mult(base, base);
        power >>= 1;
    }
    return res;
}
int divd(int a, int b) {return mult(a, fastPowMod(b, M-2));}

int f[N];

int stirling(int n, int k) {
	int ch = 1;
	int res = 0;
	FOR(i, 0, k-1) {
		if(i) {
			ch = mult(ch, k+1-i);
			ch = divd(ch, i);
		}
		int inter = mult(fastPowMod(k-i, n), ch);
		if(i & 1) res = sub(res, inter);
		else res = add(res, inter);
	}
	res = divd(res, f[k]);
	return res;
}

int choose(int n, int k) {
	int res = 1;
	FOR(i, 1, k) {
		res = mult(res, n+1-i);
		res = divd(res, i);
	}
	return res;
}

ll n, k;

void precalc() {
	f[0] = 1;
	FOR(i, 1, n) f[i] = mult(f[i-1], i);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    precalc();
    if(k == 0) {
    	cout << f[n] << endl;
    	exit(0);
    }
    if(k >= n) {
    	cout << 0 << endl;
    	exit(0);
    }
    k = n-k;
    // DEBUG(choose(n, k));
    int st = stirling(n, k);
    // DEBUG(st);
    int ans = mult(2, mult(mult(stirling(n, k), f[k]), choose(n, k)));
    cout << ans << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE) CHECK IF IT SHOULD BE 2*N!!!!
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare istakes made in the past:
// - divdision by 0 (WA)
// - integer divdision (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting max to 0 instead of -INF/in to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
// - not clearing DS between test cases EVEN FOR INPUT (WA, RTE, TLE, MLE)
