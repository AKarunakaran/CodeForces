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

const int N = 2100000;

int t, a[N], h, g, n, m;

int removal_depth(int id, int d) {
	int lc = 2*id, rc = 2*id+1;
	if(a[lc] > a[rc]) return removal_depth(lc, d+1);
	else if(a[rc] > a[lc]) return removal_depth(rc, d+1);
	else return d;
}

void f(int id) {
	int lc = 2*id, rc = 2*id+1;
	if(a[lc] > a[rc]) {
		a[id] = a[lc];
		f(lc);
	} else if(a[lc] < a[rc]) {
		a[id] = a[rc];
		f(rc);
	} else a[id] = 0;
}


signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> h >> g;
    	n = (1 << h)-1, m = (1 << g)-1;
    	FOR(i, 1, n) cin >> a[i];
    	vector<int> ans;
    	ans.reserve(n-m);
    	FOR(i, 1, n) {
    		while(a[i] && removal_depth(i, msbp(i)+1) > g) {
				f(i);
				ans.push_back(i);
    		}
    	}
    	ll sum = 0;
    	FOR(i, 1, m) sum += a[i];
    	cout << sum << '\n';
    	for(int x : ans) cout << x << ' ';
    	cout << '\n';
    	fill(a, a+n+1, 0);
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
