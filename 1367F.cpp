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

const int N = 2e5+10;

int t, n, a[N], b[N];

int solve() {
	REP(i, n) b[i] = a[i];
	sort(b, b+n);
	// REP(i, n) cout << b[i] << ' ';
	// cout << endl;
	unordered_map<int, int> pre, cnt, have;
	unordered_map<int, pii> dp; // {not full, full}
	pre[b[0]] = -1;
	REP(i, n) {
		if(i && b[i] != b[i-1]) pre[b[i]] = b[i-1];
		++cnt[b[i]];
	}
	int ans = 0;
	REP(i, n) {
		int cur = a[i];
		int p = pre[cur];
		++have[cur];

		// not full should recurse from pre{full}, or from cur, or from have[pre]
		// if first cur, full should recurse from pre[full] if have else from have[pre], else should recurse from self
		dp[cur].first = dp[cur].first+1;
		if(have[p] == cnt[p]) {
			dp[cur].first = max(dp[cur].first, dp[p].second+1);
		} else {
			dp[cur].first = max(dp[cur].first, have[p]+1);
		}
		if(have[cur] == 1) {
			if(have[p] == cnt[p]) {
				dp[cur].second = dp[p].second+1;
			} else {
				dp[cur].second = have[p]+1;
			}
		} else {
			dp[cur].second = dp[cur].second+1;
		}
		// cout << i << ' ' << cur << ' ' << dp[cur].first << ' ' << dp[cur].second << endl;
		ans = max(ans, max(dp[cur].first, dp[cur].second));
	}
	return n-ans;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> n;
    	REP(i, n) cin >> a[i];
    	cout << solve() << endl;
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
