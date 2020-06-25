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

const int M = 1e9+7;
ll add(ll a, ll b) {return (a+b)%M;}
ll sub(ll a, ll b) {return (a-b+M)%M;}

const int N = 5010;
int n, a, b, k, dp[N][N], p[N];

int rangesum(int l, int r) {
	if(l > r) return 0;
	return sub(p[r], p[l-1]);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> a >> b >> k;
    if(a > b) {
    	b = n+1 - b;
    	a = n+1 - a;
    }
    dp[0][a] = 1;

    FOR(i, 1, k) {
    	FOR(j, 1, b) p[j] = add(p[j-1], dp[i-1][j]);
    	FOR(j, 1, b-1) {
    		int pos = b-1-j;
    		int onright = pos/2;
    		dp[i][j] = add(rangesum(1, j-1), rangesum(j+1, j+onright));
    	}
    }

    int ans = 0;
    FOR(i, 1, n) ans = add(ans, dp[k][i]);
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
