#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int nINF = 1<<31;

/////////////////////////////////////////////////////////////////////
const int N = 3e5+10;
int n, at[2 * N], bt[2 * N], a[N], b[N], ans[N];

void build(int *t, int* arr, int sz) {  // build the tree
    REP(i, sz) t[i+sz] = arr[i];
    FORD(i, sz-1, 0) t[i] = max(t[i<<1], t[i<<1|1]);
}

void modify(int *t, int p, int value, int sz) {  // set value at position p
    for(t[p += sz] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

int query(int *t, int l, int r, int sz) {  // sum on interval [l, r)
    int res = -1;
    for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
        if(l&1) res = max(res, t[l++]);
        if(r&1) res = max(res, t[--r]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> a[i];
    FOR(j, 1, 2) REP(i, n) a[n*j+i] = a[i];
    
    // REP(i, 3*n) cout << a[i] << ' ';
    // cout << endl;

    build(at, a, 3*n);
    // REP(i, 6*n) cout << at[i] << ' ';
    // cout << endl;
    REP(i, 3*n) {
    	int l = -1, r = i-1;
    	while(l < r) {
    		int m = (l+r+1)/2;
    		// DEBUG(m);
    		// DEBUG(query(at, m, i, 3*n));
    		// DEBUG(a[i]);
    		if(query(at, m, i, 3*n) > 2*a[i]) l = m;
    		else r = m-1;
    	}
    	b[i] = l;
    }
    build(bt, b, 3*n);
    // REP(i, 3*n) cout << b[i] << ' ';
    // cout << endl;
    // REP(i, 6*n) cout << bt[i] << ' ';
    // cout << endl;

    REP(i, n) {
    	int l = i+1, r = 3*n;
    	while(l < r) {
    		int m = (l+r)/2;
    		// DEBUG(m);
    		// DEBUG(a[i]);
    		// DEBUG(query(bt, i+1, m+1, 3*n));
    		if(query(bt, i+1, m+1, 3*n) >= i) r = m;
    		else l = m+1;
    	}
    	// DEBUG(l);
    	if(l == 3*n) ans[i] = -1;
    	else ans[i] = l-i;
    }
    REP(i, n) cout << ans[i] << ' ';
    cout << endl;

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
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive maxtion (WA)
