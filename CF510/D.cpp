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
#define int long long
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

const int N = 2e5+10;
int n, t[2 * N], a[N], c[N], x;
pii need[N];
map<int, int> m;

/******************************************************** Range Sum Query ********************************************************/

void build() {  // build the tree
    REP(i, n) t[i+n] = a[i];
    FORD(i, n-1, 0) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
	a[p] = value;
    for(t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(a, 0, sizeof(a));
    memset(t, 0, sizeof(t));
    cin >> n >> x;
    REP(i, n) cin >> c[i];
    int s = 0;
    REP(i, n) {
    	s += c[i];
    	need[i] = {s-x, i};
    }
    sort(need, need+n, greater<pii>());
    REP(i, n) m[need[i].second] = i;

    // REP(i, n) cout << need[i].first << ' ';
    // cout << endl;
    // REP(i, n) cout << m[i] << ' ';
    // cout << endl;

    auto pr = upper_bound(need, need+n, (pii){0, 0}, greater<pii>());
    int idx = pr-need;
    if(idx < n) modify(idx, a[idx]+1);
    s = 0;
    int ans = 0;
    REP(i, n) {
    	s += c[i];
    	pr = upper_bound(need, need+n, (pii){s, 0}, greater<pii>());
    	idx = pr-need;
    	// DEBUG(s);
    	// DEBUG(idx);
    	ans += query(0, m[i]+1);
    	if(idx < n) modify(idx, a[idx]+1);
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
