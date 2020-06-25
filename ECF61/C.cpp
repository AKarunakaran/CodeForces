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

const int N = 5010;
int n, q, a[N], s, ans, ex[N], c[N], b[N][N];
pii p[N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(c, -1, sizeof(c));
    cin >> n >> q;
    REP(i, q) {
    	cin >> p[i].first >> p[i].second;
    	// DEBUG(p[i].first);
    	// DEBUG(p[i].second);
    	FOR(j, p[i].first, p[i].second) ++a[j];
    }
    REP(i, q) {
    	int l = p[i].first, r = p[i].second;
    	FOR(j, l, r) {
    		if(a[j] == 1) ex[i]++;
    		if(a[j] == 2) {
    			if(c[j] == -1) c[j] = i;
    			else {
    				++b[c[j]][i];
    			}
    		}
    	}
    }
    // FOR(i, 1, n) cout << a[i] << ' ';
    // cout << endl;
    FOR(i, 1, n) if(a[i]) ++s;
    // DEBUG(s);
    REP(i, q) {
    	FOR(j, i+1, q-1) {
    		ans = max(ans, s-ex[i]-ex[j]-b[i][j]);
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
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)

