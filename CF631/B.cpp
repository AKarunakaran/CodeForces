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
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////
int t, d, m;

int add(int a, int b) {
	a %= m;
	b %= m;
	return (a+b)%m;
}
int sub(int a, int b) {
	a %= m;
	b %= m;
	return (a+m-b)%m;
}
int mult(ll a, ll b) {
	a %= m;
	b %= m;
	return (a*b)%m;
}

int solve() {
	int cur = 1; // power of 2
	int ans = 0;
	int last = 0;
	// each iteration gives up to everything with at most cur as msb
	while(cur <= d) {
		last = add(ans, 1);
		int nxt = cur*2;
		if(nxt > d) {
			// same msb
			ans = add(ans, mult(last, sub(add(d, 1), cur)));
		} else {
			// add last repeatedly
			ans = add(ans, mult(last, sub(nxt, cur)));
		}
		cur = nxt;
	}
	return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> d >> m;
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
