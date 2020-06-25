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

const int N = 2e5+10, M = 1e9+7;
int add(int a, int b) {return (a+b)%M;}
int mult(int a, int b) {return ((ll)a*b)%M;}
int n, l, r, a[3], lo[3], dp[N][3];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> l >> r;
    REP(i, 3) FOR(j, l, l+2) if(j % 3 == i) lo[i] = j;
    REP(i, 3) a[i] = (r-lo[i]+3)/3;
    // REP(i, 3) cout << a[i] << ' ';
    // cout << endl;
    dp[0][0] = 1;
    REP(i, n) {
    	REP(j, 3) {
    		dp[i+1][j] = add(dp[i+1][j], mult(dp[i][j], a[0]));
    		dp[i+1][(j+1)%3] = add(dp[i+1][(j+1)%3], mult(dp[i][j], a[1]));
    		dp[i+1][(j+2)%3] = add(dp[i+1][(j+2)%3], mult(dp[i][j], a[2]));
    	}
    }
    cout << dp[n][0] << endl;

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
