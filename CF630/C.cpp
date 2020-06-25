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
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 1e4+10;

int t, n, a[N], c[N], colors;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    FOR(i, 2, 1000) {
    	if(!c[i]) {
    		colors++;
	    	for(int j = i; j <= 1000; j += i) {
	    		if(!c[j]) c[j] = colors;
	    	}
    	}
    }
    while(t--) {
    	cin >> n;
    	REP(i, n) cin >> a[i];
    	map<int, int> m;
    	int curc = 0;
    	// REP(i, n) cout << c[a[i]] << ' ';
    	// cout << endl;
    	REP(i, n) if(!m.count(c[a[i]])) m[c[a[i]]] = ++curc;
    	cout << m.size() << endl;
    	REP(i, n) cout << m[c[a[i]]] << ' ';
    	cout << endl;
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
