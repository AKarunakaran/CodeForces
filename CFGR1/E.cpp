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

int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

const int N = 1e5+10;
int n, t[2 * N], a[N], b[N];

void build() {  // build the tree
    REP(i, n) t[i+n] = a[i];
    FORD(i, n-1, 0) t[i] = gcd(t[i<<1], t[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
    for(t[p += n] = value; p > 1; p >>= 1) t[p>>1] = gcd(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l&1) res = gcd(res, t[l++]);
        if(r&1) res = gcd(res, t[--r]);
    }
    return res;
}

void bad() {
	cout << "No" << endl;
	exit(0);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    build();
    if(a[0] != b[0] || a[n-1] != b[n-1]) bad();
    FOR(i, 1, n-2) if((b[i]+a[i]) % gcd(query(i+1, n), query(0, i)) != 0) bad();
    cout << "Yes" << endl;

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

