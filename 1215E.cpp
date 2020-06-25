#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
// const int INF = 0x3f3f3f3f;
const int nINF = 1<<31;

/////////////////////////////////////////////////////////////////////

const int N = 20, K = 1 << 20, M = 4e5+10;
int n, cnt[M][N], a[M];
ll g[N][N], dp[K];

ll rec(int mask) {
	ll& memo = dp[mask];
	if(memo != INF) return memo;
	if((mask & (mask-1)) == 0) return memo = 0;
	ll res = INF;
	REP(i, 20) {
		if(!(mask & (1 << i))) continue;
		int next_mask = mask ^ (1 << i);
		ll cur = 0;
		REP(j, 20) {
			if(!(next_mask & (1 << j))) continue;
			cur += g[i][j];
		}
		res = min(res, cur+rec(next_mask));
	}
	return memo = res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(dp, INF, sizeof(dp));
    int mask = 0;
    cin >> n;
    FOR(i, 1, n) {
    	cin >> a[i];
    	--a[i];
    	mask |= (1 << a[i]);
    	REP(j, 20) cnt[i][j] += cnt[i-1][j] + (a[i] == j);
    }
    FOR(i, 1, n) {
    	int cur = a[i];
    	REP(j, 20) {
    		if(j == cur) continue;
    		g[j][cur] += cnt[i][j];
    	}
    }
    cout << rec(mask) << endl;


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
