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

const int N = 1e5+10, M = 998244353;
int add(int a, int b) {return (a+b)%M;}
int sub(int a, int b) {return (a+M-b)%M;}
int n, k, a[N], dp[N], pre[N], win[N], have[N], f[N];
int range_add(int l, int r) {return l ? sub(pre[r], pre[l-1]) : pre[r];}


signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    int last = 1;
    for(int i = 1; i <= n; ) {
    	if(have[a[i]] == k) {
    		--have[a[last]];
    		++last;
    	} else {
    		win[i] = last;
    		++have[a[i]];
    		++i;
    	}
    }
    FOR(i, 1, n) cout << win[i] << ' ';
    cout << endl;
    // FOR(i, 1, n) cout << dp[i] << ' ';
    // cout << endl;
    dp[0] = pre[0] = 1;
    FOR(i, 1, n) {
    	dp[i] = range_add(win[i]-1, i-1);
    	pre[i] = add(dp[i], pre[i-1]);
    }
    FOR(i, 1, n) cout << dp[i] << ' ';
    cout << endl;

    cout << dp[n] << endl;

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

