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

const int N = 1010;
int n, m, g[N][N];

void bad() {
	cout << "NO" << endl;
	exit(0);
}

bool possmark(int r, int c) {
	if(r+1 >= n || c+1 >= m) return false;
	if(r-1 < 0 || c-1 < 0) return false;
	FOR(i, r-1, r+1) {
		FOR(j, c-1, c+1) {
			if(i == r && j == c) continue;
			if(!g[i][j]) return false;
		}
	}
	return true;
}

bool poss(int r, int c) {
	FOR(i, r-1, r+1) {
		FOR(j, c-1, c+1) {
			if(i >= n || j >= m) continue;
			if(i < 0 || j < 0) continue;
			if(i == r && j == c) continue;
			if(possmark(i, j)) return true;
		}
	}
	return false;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    REP(i, n) {
    	REP(j, m) {
	    	char c;
	    	cin >> c;
	    	g[i][j] = (c == '#' ? 1 : 0);
    	}
    }
    REP(i, n) {
    	REP(j, m) {
    		if(g[i][j] && !poss(i, j)) bad();
    	}
    }

    cout << "YES" << endl;

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
