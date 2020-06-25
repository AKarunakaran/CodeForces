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
int m, n, k, t, a[N], run_len;
pair<int, pii> tr[N];
set<pii> s;

set<pii>::iterator addInterval(set<pii>& is, int L, int R) {
	if (L == R) return is.end();
	auto it = is.lower_bound({L, R}), before = it;
	while (it != is.end() && it->first <= R) {
		R = max(R, it->second);
		run_len -= (it->second-it->first);
		before = it = is.erase(it);
	}
	if (it != is.begin() && (--it)->second >= L) {
		L = min(L, it->first);
		R = max(R, it->second);
		run_len -= (it->second-it->first);
		is.erase(it);
	}
	run_len += R-L;
	return is.insert(before, {L,R});
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> m >> n >> k >> t;
    REP(i, m) cin >> a[i];
    REP(i, k) {
    	int l, r, d;
    	cin >> l >> r >> d;
    	tr[i] = {-d, {l, r}};
    }
    sort(tr, tr+k);
    sort(a, a+m);
    int high_ag = -tr[0].first;
    int ans = a+m-lower_bound(a, a+m, high_ag);
    REP(i, k) {
    	addInterval(s, tr[i].second.first-1, tr[i].second.second);
    	if(tr[i].first != tr[i+1].first) {
	    	int curt = 2*(run_len) + n+1;
	    	if(curt <= t) {
		    	high_ag = -tr[i+1].first;
		    	ans = max(ans, (int)(a+m-lower_bound(a, a+m, high_ag)));
	    	}
    	}
    }
    cout << ans << endl;

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
