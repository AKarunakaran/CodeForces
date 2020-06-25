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
typedef long long ll;
typedef unsigned long long ull;
const ull INF = 0xffffffffffffffff;
const int nINF = 1<<31;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

ull count(ull n, ull p) {
	ull d = p, res = 0;
	while(n/d > 0) {
		res += n/d;
		ull nd;
        if(__builtin_mul_overflow(d, p, &nd)) break;
		d = nd;
	}
	return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ull n, b, nb;
    cin >> n >> b;
    ull ans = INF;
    nb = b;
    for(ull i = 2; i*i <= nb; ++i) {
		ull cur = 0;
    	while(b % i == 0) {
    		++cur;
    		b /= i;
    	}
    	if(cur) ans = min(ans, count(n, i)/cur);
    }
    if(b > 1) ans = min(ans, count(n, b));
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
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)

