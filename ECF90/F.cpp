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

const int N = 2e6+10;

int t, n, a[N], b[N];
ll p[N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> n;
    	FOR(i, 1, n) cin >> a[i];
    	FOR(i, 1, n) cin >> b[i];
    	ll as = 0, bs = 0;
    	FOR(i, 1, n) {
    		int n1 = i, n2 = i == n ? 1 : i+1;
    		b[i] = min(b[i], a[n1]+a[n2]);
    		as += a[i];
    		bs += b[i];
    	}
    	FOR(i, n+1, 2*n) {
    		a[i] = a[i-n];
    		b[i] = b[i-n];
    	}
    	// REP(i, n) cout << a[i] << ' ';
    	// cout << endl;
    	// REP(i, n) cout << b[i] << ' ';
    	// cout << endl;
    	ll msf = 0, res = 0;
    	multiset<ll> ms;
    	ms.insert(0);
    	p[0] = 0;
    	reverse(a+1, a+2*n+1);
    	reverse(b+1, b+2*n+1);
    	FOR(i, 1, 2*n-1) {
    		p[i] = p[i-1] + a[i]-b[i];
    		ms.insert(p[i]);
    		if(i >= n-1) ms.erase(ms.find(p[i-(n-1)]));
    		msf = *ms.begin();
    		// cout << i << ' ' << p[i] << ' ' << msf << endl;
    		res = max(res, p[i]-msf-b[i+1]);
    	}
    	cout << (res > 0 || bs < as ? "NO" : "YES") << endl;
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
// - negative arithmetic, ceiling division, modulo (WA)
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
