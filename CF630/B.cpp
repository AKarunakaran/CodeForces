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

const int N = 1e5+10;

int t, n, k;
string s;

int min_periodic(int id) {
	int off = k-1-id-id;
	map<char, int> m;
	int mx = 0;
	for(int i = id; i < n; i += k) {
		++m[s[i]];
		mx = max(mx, m[s[i]]);
		++m[s[i+off]];
		mx = max(mx, m[s[i+off]]);
	}
	// for(int i = id; i < n; i += k) {
	// 	s[i] = c;
	// }
	// DEBUG(id);
	// DEBUG(mx);
	return 2*n/k-mx;
}

int min_periodic_help(int id) {
	map<char, int> m;
	int mx = 0;
	for(int i = id; i < n; i += k) {
		++m[s[i]];
		mx = max(mx, m[s[i]]);
	}
	return n/k-mx;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> n >> k >> s;
    	int ans = 0;
    	REP(i, k/2) ans += min_periodic(i);
    	if(k & 1) {
    		ans += min_periodic_help(k/2);
    	}
    	// cout << s << endl;
    	cout << ans << endl;
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
