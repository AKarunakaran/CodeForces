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

const int M = 998244353;
int add(int a, int b) {return (a+b)%M;}
int sub(int a, int b) {return (a+M-b)%M;}
int mult(int a, int b) {return ((ll)a*(ll)b)%M;}

const int N = 2e5+10;
int n, k, a[N], ans = 1;

void dumb_solve() {
	int ans = 1;
	FOR(i, 1, n) if(a[i] == -1) ans = mult(ans, k);
	cout << ans << endl;
	exit(0);
}

void bad() {
	cout << 0 << endl;
	exit(0);
}

int construct_array(vector<int>& v) {
	// for(int x : v) cout << x << ' ';
	// cout << endl;
	if(v.size() == 1) return v[0] == -1 ? k : 1;
	int res = 1;
	if(v.back() == -1) {
		int restricted = 0;
		REP(i, v.size()) {
			if(v[i] == -1) res = mult(res, k-restricted);
			restricted = 1;
		}
	} else {
		int back = v.back();
		vector<vector<int>> dp(v.size(), vector<int>(2, 0));
		if(v[0] == -1) {
			dp[0][0] = k-1;
			dp[0][1] = 1;
		} else {
			if(v[0] == back) {
				dp[0][0] = 0;
				dp[0][1] = 1;
			} else {
				dp[0][0] = 1;
				dp[0][1] = 0;
			}
		}
		FOR(i, 1, v.size()-1) {
			dp[i][0] = add(mult(k-2, dp[i-1][0]), mult(k-1, dp[i-1][1]));
			dp[i][1] = dp[i-1][0];
		}
		res = dp[v.size()-1][1];
	}
	// DEBUG(res);
	return res;
}

int solve(vector<int>& v) {
	// for(int x : v) cout << x << ' ';
	// cout << endl;
	int l = 0, r = v[0] == -1 ? 0 : 1, res = 1;
	while(r < v.size()) {
		while(r < v.size() && v[r] == -1) ++r;
		if(r == v.size()) --r;
		vector<int> small_v(r-l+1);
		FOR(i, l, r) small_v[i-l] = v[i];
		res = mult(res, construct_array(small_v));
		l = r++;
	}
	return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    if(n <= 2) dumb_solve();
    vector<int> v[2];
    FOR(i, 1, n) v[i & 1].push_back(a[i]);
    REP(i, 2) ans = mult(ans, solve(v[i]));
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
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)

