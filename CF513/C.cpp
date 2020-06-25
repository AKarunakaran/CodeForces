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

const int N = 2010;
int n, m, a[N], b[N], x, ans = 0;
pii pairs[N*N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> b[i];
    cin >> x;
    int idx = 0;
    REP(i, n) {
    	int s = 0;
    	FOR(j, i, n-1) {
    		s += a[j];
    		pairs[idx++] = {s, j-i+1};
    	}
    }
    int numpairs = idx;
    sort(pairs, pairs+numpairs);
    FOR(i, 1, numpairs-1) {
    	pairs[i].second = max(pairs[i].second, pairs[i-1].second);
    }
    reverse(pairs, pairs+numpairs);
    idx = 0;
    REP(i, m) {
    	int s = 0;
    	FOR(j, i, m-1) {
    		s += b[j];
    		int need = x/s;
    		idx = lower_bound(pairs, pairs+numpairs, (pii){need, INF}, greater<pii>())-pairs;
    		// DEBUG(s);
    		// DEBUG(need);
    		// DEBUG(idx);
    		if(idx >= 0) {
    			// DEBUG(pairs[idx].first);
    			// DEBUG(pairs[idx].second);
    			ans = max(ans, (j-i+1)*(pairs[idx].second));
    			// DEBUG(ans);
    		}
    	}
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
