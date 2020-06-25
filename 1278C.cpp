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

const int N = 2e5+10;
int t, n, a[N], b[N], ida[N], idb[N];

void fill_ids(int *v, int *p, int val) {
	int num = 0;
	p[num] = 0;
	FOR(i, 1, n) {
		if(v[i] == val) ++num;
		else --num;
		if(num > 0 && p[num] == -1) p[num] = i;
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> n;
    	fill(ida, ida+2*n+1, -1);
    	fill(idb, idb+2*n+1, -1);
    	int n1 = 0, n2 = 0;
    	FORD(i, n, 1) {
    		cin >> a[i];
    		if(a[i] == 1) ++n1;
    		else ++n2;
    	}
    	FOR(i, 1, n) {
    		cin >> b[i];
    		if(b[i] == 1) ++n1;
    		else ++n2;
    	}
    	int g = n1 > n2 ? 1 : 2;
    	int delta = abs(n1-n2);
    	fill_ids(a, ida, g);
    	fill_ids(b, idb, g);
    	// DEBUG(g);
    	// DEBUG(delta);
    	// FOR(i, 0, n) cout << ida[i] << ' ';
    	// cout << endl;
    	// FOR(i, 0, n) cout << idb[i] << ' ';
    	// cout << endl;
    	int ans = 2*n;
    	FOR(i, 0, delta) if(ida[i] != -1 && idb[delta-i] != -1) ans = min(ans, ida[i] + idb[delta-i]);
    	cout << ans << endl;
    }

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
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
