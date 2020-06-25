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

const int N = 5010;
string g[N];
int n, m, dp[N][N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    REP(i, n) cin >> g[i];
    REP(i, n) {
    	int cur = 0;
    	FORD(j, m-1, 0) {
    		cur = g[i][j] == '1' ? cur+1 : 0;
    		++dp[j][cur];
    	}
    }
    int ans = 0;
    REP(i, m) {
    	int sum = 0;
    	FORD(j, m, 1) {
    		sum += dp[i][j];
    		ans = max(ans, j*sum);
    	}
    }
    cout << ans << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - .size()-k underflow (WA, RTE, TLE)
// - const int N is correct (WA, RTE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
