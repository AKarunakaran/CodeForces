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
const ll INF = 0x7fffffffffffffffLL;
const int nINF = 1<<31;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 1e5+10;
int n, a[N];
string s;
ll dp[N][4];


signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    REP(i, N) fill(dp[i], dp[i]+4, INF);
    cin >> n >> s;
    REP(i, n) cin >> a[i];
    dp[0][0] = 0;
    string lets = "hard";
    REP(i, n) {
    	REP(j, 4) {
    		if(dp[i][j] == INF) continue;
    		if(s[i] == lets[j]) {
    			dp[i+1][j] = min(dp[i+1][j], dp[i][j]+a[i]);
    			if(j != 3) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
    		} else {
    			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
    		}
    	}
    }
    ll ans = INF;
    REP(i, 4) ans = min(ans, dp[n][i]);
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
