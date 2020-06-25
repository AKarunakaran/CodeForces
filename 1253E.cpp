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

const int N = 90, M = 1e5+10;
int n, m, dp[N][M]; //dp[i][j] - covers integers from 1..j where i is the rightmost used antenna
pii p[N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(dp, INF, sizeof(dp));
    cin >> n >> m;
    FOR(i, 1, n) cin >> p[i].first >> p[i].second;
    sort(p+1, p+1+n, [](auto& left, auto& right){
    	return left.first-left.second < right.first-right.second || (left.first-left.second == right.first-right.second && left.first+left.second > right.first+right.second);
    });
    dp[0][0] = dp[1][0] = 0;
    FOR(i, 1, m) {
    	int l = p[1].first-p[1].second, r = p[1].first+p[1].second;
    	dp[1][i] = max(0, max(l-1, i-r));
    }
    FOR(i, 2, n) {
    	int l = p[i].first-p[i].second, r = p[i].first+p[i].second;
    	FOR(j, max(1, l), m) {
			int cost = max(0, j-r);
			FORD(k, i-1, 1) dp[i][j] = min(dp[i][j], dp[k][max(l-cost-1, 0)]+cost);
    	}
    }
    int ans = INF;
    FOR(i, 1, n) ans = min(ans, dp[i][m]);
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
