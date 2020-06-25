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

const int N = 5201;
int n;
int g[N][N];

int conv(char c) {return (c >= '0' && c <= '9' ? c-'0' : c-'A'+10);}
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) {
    	REP(j, n >> 2) {
    		char ch;
    		cin >> ch;
    		int mask = conv(ch);
    		REP(k, 4) g[i][4*j+(3-k)] = (mask & (1 << k) ? 1 : 0);
    	}
    }
    REP(i, n) {
    	g[i][n] = 2;
    	g[n][i] = 2;
    }

    // REP(i, n+1) {
    // 	REP(j, n+1) cout << g[i][j];
    // 	cout << endl;
    // }

    int ans = 0;

    REP(i, n) {
    	int last = 0;
    	REP(j, n+1) {
    		if(g[i][j] != g[i][last]) {
    			int len = j-last;
    			ans = gcd(ans, len);
    			last = j;
    		}
    	}
    }
    REP(j, n) {
    	int last = 0;
    	REP(i, n+1) {
    		if(g[i][j] != g[last][j]) {
    			int len = i-last;
    			ans = gcd(ans, len);
    			last = i;
    		}
    	}
    }
    cout << (ans ? ans : n) << endl;

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
// - round announcements (WA)

