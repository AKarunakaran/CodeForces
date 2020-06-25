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

void good(int x) {
	cout << x << endl;
	exit(0);
}

const int N = 5e5+10;

int t[2*N];

void build(int *a, int n) {  // build the tree
    REP(i, n) t[i+n] = a[i];
    FORD(i, n-1, 0) t[i] = min(t[i<<1], t[i<<1|1]);
}

void modify(int p, int value, int n) {  // set value at position p
    for(t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

int query(int l, int r, int n) {  // sum on interval [l, r)
    int res = LLONG_MAX;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l&1) res = min(res, t[l++]);
        if(r&1) res = min(res, t[--r]);
    }
    return res;
}


int n, a[N], b[N], p[N], x, sum, halfc;

bool check(int k) {
	int start = (k-halfc)*x+sum;
	if(start <= 0) return false;
	int remaining = n-k;
	// DEBUG(k);
	// DEBUG(start);
	// DEBUG(remaining);
	//check first remaining elements of segtree
	if(remaining) {
		// DEBUG(query(0, remaining, halfc));
		// if we end up taking away too much at any point, bad
		if(start+query(0, remaining, halfc) <= 0) return false;
	}
	return true;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    halfc = (n+1)/2;
    REP(i, halfc) {
    	cin >> a[i];
    	sum += a[i];
    }
    cin >> x;
    REP(i, halfc) {
    	b[i] = x-a[i];
    	if(i) p[i] = p[i-1]+b[i];
    	else p[i] = b[i];
    }
    build(p, halfc);

    // REP(i, halfc) cout << a[i] << ' ';
    // cout << endl;
    // REP(i, halfc) cout << b[i] << ' ';
    // cout << endl;
    // REP(i, halfc) cout << p[i] << ' ';
    // cout << endl;

    FOR(i, halfc, n) {
    	if(check(i)) {
    		good(i);
    	}
    }
    cout << -1 << endl;

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
// - forgetting to rename recursive call when copy/pasting recursive mintion (WA)
// - not clearing DS between test cases EVEN FOR INPUT (WA, RTE, TLE, MLE)
