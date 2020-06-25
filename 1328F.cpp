#include <bits/stdc++.h>
using namespace std;
#define int long long
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

int n, k, a[N], b[N], s[N], sr[N];

int check(int target) {
	int aid = upper_bound(a, a+n, target)-a;
	int bid = upper_bound(b, b+n, target, greater<int>())-b;
	int anum = n-aid;
	int bnum = n-bid;
	int cur = n-anum-bnum;
	if(cur >= k) return 0;
	int need = k-cur;
	int acost = s[aid]-(target+1)*anum;
	int bcost = (target-1)*bnum-sr[bid];
	int res = LLONG_MAX;
	if(anum >= need) res = min(res, acost+need);
	if(bnum >= need) res = min(res, bcost+need);
	res = min(res, acost+bcost+need);
	return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    sort(a, a+n);
    REP(i, n) b[i] = a[n-1-i];
    FORD(i, n-1, 0) {
    	s[i] = s[i+1]+a[i];
    	sr[i] = sr[i+1]+b[i];
    }
    int ans = a[n-1]*n;
    REP(i, n) ans = min(ans, check(a[i]));
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
