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

const int N = 710;
int n, a[N], cp[N][N];
// vector<int> 
int dp[N][N][2];

int gcd(int x, int y) {return y ? gcd(y, x%y) : x;}

void solve(int l, int r) {
	if(dp[l][r][0] != -1 || dp[l][r][1] != -1) return;
	// DEBUG(l);
	// DEBUG(r);
	if(l == r) {
		dp[l][r][0] = !cp[l][l-1];
		dp[l][r][1] = !cp[r][r+1];
		return;
	}
	FOR(i, l, r) {
		if(i != l) {
			solve(l, i-1);
			if(!dp[l][i-1][1]) continue;
		}
		if(i != r) {
			solve(i+1, r);
			if(!dp[i+1][r][0]) continue;
		}
		if(!cp[i][l-1]) dp[l][r][0] = 1;
		if(!cp[i][r+1]) dp[l][r][1] = 1;
		if(dp[l][r][0] == 1 && dp[l][r][1] == 1) return;
	}
	if(dp[l][r][0] == -1) dp[l][r][0] = 0;
	if(dp[l][r][1] == -1) dp[l][r][1] = 0;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    a[0] = a[n+1] = 0;
    REP(i, n+2) REP(j, n+2) cp[i][j] = gcd(a[i], a[j]) == 1 ? 1 : 0;
    solve(1, n);
    cout << (dp[1][n][0] == 0 ? "No" : "Yes") << endl;

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
