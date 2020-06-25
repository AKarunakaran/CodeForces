#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
const ll lINF = 0x7fffffffffffffffLL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 401, M = 250000;
int n, m, a[N], dp[N][N][N]; 	//dp[i][j][k] - smallest tank needed to go from city i to city j with k refills, and c = 1
								//dp[i][j][k] = \min_{i <= r < j}(max(sum(r, j), dp[i][r][k-1])) This is unimodal, so binary search

int dist(int i, int j) {return a[j]-a[i];}

int rec(int l, int r, int f) {
	if(l == r) return 0;
	if(f == 0) return dist(l, r);
	int& memo = dp[l][r][f];
	if(memo != INF) return memo;
	int res = INF;
	int lo = l, hi = r-1;
	while(lo < hi) {
		int mid = (lo+hi)/2;
		int d1 = rec(l, mid, f-1)-dist(mid, r);
		if(d1 < 0) lo = mid+1;
		else hi = mid;
	}
	if(lo == l) res = max(rec(l, lo, f-1), dist(lo, r));
	else res = min(max(rec(l, lo, f-1), dist(lo, r)), max(rec(l, lo-1, f-1), dist(lo-1, r)));
	// cout << l << ' ' << r << ' ' << a[l] << ' ' << a[r] << ' ' << f << ' ' << lo << ' ' << res << endl;
	return memo = res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    REP(i, N) REP(j, N) REP(k, N) dp[i][j][k] = INF;
    scanf("%d %d", &n, &m);
    FOR(i, 1, n) scanf("%d", a+i);
    ll ans = 0;
    REP(i, m) {
    	int s, f, c, r;
    	scanf("%d %d %d %d", &s, &f, &c, &r);
    	ans = max(ans, (ll)c*rec(s, f, r));
    	// cout << ans << endl;
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
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
