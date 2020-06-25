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

const int N = 60, M = 2e4+30;

int n, m, k;
ll dp[N][M], p[N][M], g[N][M], ans; // dp[i][j] = max sum obtained with first i cameras and last camera ending on column j (j <= m+k-1)
ll prem[N][N], sufm[N][M];

void calculate_pre(int r) {
	FOR(i, 1, m+k-1) p[r][i] = p[r][i-1]+g[r][i];
}

ll row_query(int r, int c1, int c2) {
	return p[r][c2]-p[r][c1-1];
}

ll rect_query(int tr, int c1, int c2) {
	ll res = 0;
	FOR(i, tr, tr+1) res += row_query(i, c1, c2);
	return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> k;
    FOR(i, 1, n) FOR(j, 1, m) cin >> g[i][j];
    FOR(i, 1, n) calculate_pre(i);
    FOR(i, 1, m+k-1) dp[1][i] = rect_query(1, max(1, i-k+1), i);
    FOR(i, 2, n) {
    	ll curmx = 0;
    	FOR(j, 1, m+k-1) {
    		ll bc = j-k+1, lc = j;
    		ll cur_rect = rect_query(i, bc, j);
    		dp[i][j] = max(dp[i][j], max(prem[i-1][bc-1], sufm[i-1][lc+1+k-1])+cur_rect);
    		FOR(l, bc, lc+k-1) {
    			// l - last column of the above rectangle
    			ll tc1 = l-k+1, tc2 = l;
    			ll qc1 = max(bc, tc1), qc2 = min(lc, tc2);
    			ll sub = qc1 < 1 ? 0 : row_query(i, qc1, qc2);
    			dp[i][j] = max(dp[i][j], dp[i-1][l]+cur_rect-sub);
    		}
    		ans = max(ans, dp[i][j]);
    	}
    	FOR(j, 1, m+k-1) prem[i][j] = max(prem[i][j-1], dp[i][j]);
    	FORD(j, m+k-1, 1) prem[i][j] = max(prem[i][j+1], dp[i][j]);
    }
    cout << endl;
    FOR(i, 1, n) {
    	FOR(j, 1, m+k-1) cout << dp[i][j] << ' ';
    	cout << endl;
	}
	cout << endl;
    cout << ans << endl;

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
