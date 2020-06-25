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

ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}

ll n, k, a, b, num;
ll g_small, g_big = 0;

ll before(ll s, ll d) {
	return ((s-d+num-1)%num)+1;
}

ll after(ll s, ll d) {
	return ((s+d-1)%num)+1;
}

ll dist(ll x, ll y) {
	return x < y ? y-x : num-(x-y);
}

void trys(ll s) {
	// DEBUG(s);
	REP(i, n) {
		ll f = i*k+1;
		// DEBUG(before(f, b));
		// DEBUG(after(f, b));
		ll d = dist(s, before(f, b));
		ll g = gcd(d, num);
		g_small = min(g_small, g);
		g_big = max(g_big, g);
		d = dist(s, after(f, b));
		g = gcd(d, num);
		g_small = min(g_small, g);
		g_big = max(g_big, g);
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k >> a >> b;
    num = n*k;
    g_small = num+10;
    trys(1+a);
    trys(k+1-a);
    cout << num/g_big << ' ' << num/g_small << endl;

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

