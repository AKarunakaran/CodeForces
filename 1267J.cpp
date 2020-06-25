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

const int N = 2e6+10;
int t, n, c[N];

ll get_s(int num, int sz) {
	return (num + sz - 1) / sz;
}

bool poss(int num, int sz) {
	int upper = get_s(num, sz) * sz;
	int lower = get_s(num, sz) * (sz-1);
	return lower <= num && num <= upper;
}

void solve() {
	unordered_map<int, int> f, m;
	REP(i, n) ++f[c[i]];
	int hi = INF;
	for(auto [num, freq] : f) {
		++m[freq];
		hi = min(hi, freq);
	}
	ll ans = INF;
	FOR(i, 1, hi+1) {
		ll cur = 0;
		bool flag = true;
		for(auto [num, freq] : m) {
			if(!poss(num, i)) {
				flag = false;
				break;
			}
			cur += freq*get_s(num, i);
		}
		if(!flag) continue;
		ans = min(ans, cur);
	}
	cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> n;
    	REP(i, n) cin >> c[i];
    	solve();
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
