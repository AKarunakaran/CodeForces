#include <bits/stdc++.h>
using namespace std;
#define int long long
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

int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

int a, b, q, l, r, t;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    scanf("%lld", &t);
    while(t--) {
    	scanf("%lld %lld %lld", &a, &b, &q);
    	int lc = a*b/gcd(a, b), ans = 0;
    	vector<int> modans(lc, 0);
    	REP(i, lc) {
			if((i % a) % b != (i % b) % a) {
				modans[i] = 1;
			}
		}
		vector<int> pre(lc, 0), suf(lc, 0);
		pre[0] = modans[0];
		FOR(i, 1, lc-1) pre[i] = pre[i-1]+modans[i];
		suf[lc-1] = modans[lc-1];
		FORD(i, lc-2, 0) suf[i] = suf[i+1]+modans[i];
    	while(q--) {
    		scanf("%lld %lld", &l, &r);
    		int m = lc;
    		int ul = ((l+m-1)/m)*m;
    		int lr = ((r+1)/m)*m-1;
    		int upper = r-lr, lower = ul-l;

    		int ans = pre[lc-1]*((lr-ul+1)/m);
    		if(upper) ans += pre[upper-1];
    		if(lower) ans += suf[lc-lower];
    		cout << ans << ' ';
    	}
    	cout << '\n';
    }

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
