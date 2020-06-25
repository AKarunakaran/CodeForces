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
const int INF = (((1LL << 60)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 2e5+10;
int n, a[N], onpath[N][2], dp[N][2]; //0 increase, 1 decrease

int dfs(int s, int dec) {
	if(s > n || s <= 0) return 0;
	int& memo = dp[s][dec];
	if(onpath[s][dec]) return memo = INF;
	if(memo != -1) return memo;
	onpath[s][dec] = 1;
	int dest = dec ? s-a[s] : s+a[s];
	int temp = dfs(dest, 1-dec);
	onpath[s][dec] = 0;
	return memo = (temp == INF ? INF : a[s]+temp);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    FOR(i, 2, n) cin >> a[i];
    onpath[1][0] = 1;
    FOR(i, 2, n) {
    	dfs(i, 0);
    	dfs(i, 1);
    }
    FOR(i, 1, n-1) {
    	cout << (dp[1+i][1] == INF ? -1 : dp[1+i][1]+i) << endl;
    }

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
