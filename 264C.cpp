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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 1e5+10;
const ll LOW = -1e16;
int n, q, v[N], c[N];
bool used[N];
ll s[N], hi, shi;

ll solve(ll a, ll b) {
	fill(s, s+N, LOW);
	memset(used, 0, sizeof(used));
	hi = shi = LOW;
	ll ans = 0;
	REP(i, n) {
		int curc = c[i], curv = v[i];
		
		// Starting sequence with ball i
		ll newval = b*curv;

		// If we have seen this color before, use this ball
		if(used[curc]) newval = max(newval, s[curc]+a*curv);

		// If this color ends the sequence with the highest value so far, use the second highest value sequence
		// Otherwise, use the highest value sequence
		if(s[curc] != hi) {
			newval = max(newval, hi+b*curv);
		} else {
			newval = max(newval, shi+b*curv);
		}
		ans = max(ans, newval);

		if(newval > hi) {
			// If newval is new hi, then hi->shi and newval->hi
			if(s[curc] != hi) shi = hi;
			hi = newval;
		} else if(newval > shi && s[curc] != hi) {
			// If newval is not greater than hi, but greater than shi, then newval->shi
			shi = newval;
		}

		// Update our current sequence ending with color curc
		s[curc] = max(s[curc], newval);
		// We've seen this color now
		used[curc] = 1;

	}
	return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    scanf("%d %d", &n, &q);
    REP(i, n) scanf("%d", v+i);
    REP(i, n) scanf("%d", c+i);
    while(q--) {
    	int a, b;
    	scanf("%d %d", &a, &b);
    	cout << solve(a, b) << endl;
    }

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