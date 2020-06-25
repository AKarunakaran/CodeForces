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

// struct Comp {
// 	bool operator()(const pii left, const pii right) const {
// 		return left.second < right.second || (left.second == right.second && left.first < right.first);
// 	}
// };

const int N = 1e5+10;
int n, ans = 0;//, l, r;
int l[N], r[N];

// multiset<pii> lh;
// multiset<pii, Comp> rh;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    // ans = n;
    // REP(i, n) {
    // 	cin >> l >> r;
    // 	ans += max(l, r);
    // 	if(l > r) lh.insert({l, r});
    // 	else if(l < r) rh.insert({l, r});
    // }
    // bool merged = true;
    // while(lh.size() && rh.size() && merged) {
    // 	//
    // }
    REP(i, n) cin >> l[i] >> r[i];
    sort(l, l+n);
    sort(r, r+n);
    REP(i, n) ans += max(l[i], r[i])+1;

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
