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
int n, t[2 * N], a[N], v[N], w[N], wid = 1, ans[N];
map<int, int> m;

void build() {  // build the tree
    REP(i, n) t[i+n] = a[i];
    FORD(i, n-1, 0) t[i] = max(t[i<<1], t[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
	a[p] = value;
    for(t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(res, t[--r]);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(a, 0, sizeof(a));
    cin >> n;
    REP(i, n) cin >> v[i];
    REP(i, n) w[i] = v[i];
    sort(w, w+n);
    REP(i, n) if(m.find(w[i]) == m.end()) m[w[i]] = wid++;
    REP(i, n) v[i] = m[v[i]];
    build();
    FORD(i, n-1, 0) {
    	int q = query(1, v[i]);
    	if(q == 0) ans[i] = -1;
    	else ans[i] = q-i-1;
    	if(a[v[i]] == 0) modify(v[i], i);
    }
    REP(i, n) cout << ans[i] << ' ';
    cout << endl;

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
