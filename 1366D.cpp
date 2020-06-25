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

const int N = 5e5+10, K = 1e7+10;

int n, a[N], ans[2][N], sieve[K];

pii solve(int x) {
	pii res{1, 1};
	while(x != 1) {
		int p = sieve[x];
		if(res.first == 1) res.first *= p;
		else if((res.first % p) && (res.second % p)) res.second *= p;
		x /= p;
	}
	if(res.second == 1) return {-1, -1};
	else return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    for(int i = 2; i < K; ++i) if(!sieve[i]) for(int j = i; j < K; j += i) sieve[j] = i;
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) tie(ans[0][i], ans[1][i]) = solve(a[i]);
    REP(i, 2)  {
    	REP(j, n) cout << ans[i][j] << ' ';
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
