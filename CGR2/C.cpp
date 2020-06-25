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

const int N = 510;
int n, m, a[N][N], b[N][N], c[N][N];

void bad() {
	cout << "No" << endl;
	exit(0);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
    FOR(i, 1, n) FOR(j, 1, m) cin >> b[i][j];
    FOR(i, 1, n) FOR(j, 1, m) c[i][j] = a[i][j] ^ b[i][j];
    FOR(i, 1, n-1) {
    	FOR(j, 1, m-1) {
	    	if(c[i][j] == 1) {
	    		c[i][j] ^= 1;
	    		c[i+1][j] ^= 1;
	    		c[i][j+1] ^= 1;
	    		c[i+1][j+1] ^= 1;
	    	}
    	}
    }
    FOR(i, 1, n) if(c[i][m] == 1) bad();
    FOR(i, 1, m) if(c[n][i] == 1) bad();
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

