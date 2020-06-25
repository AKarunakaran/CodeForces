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
typedef long long ll;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
// const int INF = (((1<<30)-1)<<1)+1;
// const int nINF = 1<<31;
// typedef unsigned long long ull;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const ll N = 1e5+10;
ll n, k, a[N], b[N], p[N], s[N];

bool poss(ll m) {
	// DEBUG(m);
	ll mo = k+1; // min ops to get distance of m
	FOR(i, 1, n) {
		ll cur = (i-1)*a[i]-p[i-1];
		ll id = upper_bound(a+1, a+1+n, a[i]+m)-a;
		cur += s[id]-((n+1)-id)*(a[i]+m);
		mo = min(mo, cur);

		// cout << i << ' ' << a[i] << "  " << i-1 << ' ' << id;

		cur = s[i+1]-((n+1)-(i+1))*a[i];
		id = upper_bound(b+1, b+1+n, a[i]-m, greater<ll>())-b;
		id = (n+1)-id;
		cur += id*(a[i]-m)-p[id];
		mo = min(mo, cur);

		// cout << "  " << id << ' ' << i+1 << endl;
	}
	return mo <= k;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    sort(a+1, a+1+n);

    // FOR(i, 1, n) cout << a[i] << ' ';
    // cout << endl;

    FOR(i, 1, n) b[i] = a[i];
    reverse(b+1, b+1+n);
    FOR(i, 1, n) p[i] = p[i-1]+a[i];
    FORD(i, n, 1) s[i] = s[i+1]+a[i];
    ll l = 0, r = 1e9;
    while(l < r) {
    	ll m = (l+r)/2;
    	if(poss(m)) r = m;
    	else l = m+1;
    }
    cout << l << endl;

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

