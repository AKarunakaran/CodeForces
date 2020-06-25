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
int n, p[N], rp[N], ans[N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(ans, 0, sizeof(ans));
    cin >> n;
    FOR(i, 1, n) cin >> p[i];
    FOR(i, 1, n) rp[p[i]] = i;
    FORD(i, n, 1) {
    	bool win = 0;
    	int idx = rp[i];
    	// DEBUG(i);
    	for(int j = idx+i; j <= n; j += i) {
    		if(p[j] > i && ans[j] == 2) {
    			// DEBUG(j);
    			win = 1;
    		}
    	}
    	for(int j = idx-i; j >= 1; j -= i) {
    		if(p[j] > i && ans[j] == 2) {
    			// DEBUG(j);
    			win = 1;
    		}
    	}
    	if(win == 0) {
    		ans[idx] = 2;
    	} else {
    		ans[idx] = 1;
    	}
    }
    FOR(i, 1, n) {
    	cout << (ans[i] == 1 ? 'A' : 'B');
    }
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
