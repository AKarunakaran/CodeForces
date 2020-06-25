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
#include <ctime>
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

const int N = 1e5+10;
int n, a[N], is[N], ds[N], ans[N], best;

int lis() {
    int ans = 1;
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    REP(i, n) {
        int idx = lower_bound(dp.begin(), dp.end(), a[i+1]) - dp.begin();
        dp[idx] = min(dp[idx], a[i+1]);
        ans = max(ans, idx);
    }
    return ans;
}

// int three = 0;

// pii rec(int l, int r, int par = 0) {
// 	int len = r-l+1;
// 	if(len <= 2) {
// 		if(len == 1) {
// 			a[l] = 1;
// 		} else if(len == 2) {
// 			if(par) {
// 				a[l] = 2;
// 				a[r] = 1;
// 			} else {
// 				a[l] = 1;
// 				a[r] = 2;
// 			}
// 		}
// 		return {1, len};
// 	}
// 	if(len == 3) {
// 		if(three) {
// 			a[l] = 2;
// 			a[l+1] = 3;
// 			a[r] = 1;
// 		} else {
// 			a[l] = 2;
// 			a[l+1] = 1;
// 			a[r] = 3;
// 		}
// 		three = 1-three;
// 		return {1, len};
// 	}
// 	int m = (l+r)/2;
// 	pii lef = rec(l, m, 1-par);
// 	pii rig = rec(m+1, r, 1-par);
// 	if(par) {
// 		int shif = rig.second;
// 		FOR(i, l, m) a[i] += shif;
// 	} else {
// 		int shif = lef.second;
// 		FOR(i, m+1, r) a[i] += shif;
// 	}
// 	return {1, rig.second+lef.second};
// }

// void solve() {
// 	for(int len = 2; len <= n; len *= 2) {
// 		for(int i = 1; i+len-1 <= n; i += len) {
// 			reverse(a+i, a+i+len);
// 		}
// 	}
// }

void solve() {
    srand(time(NULL));
	best = 2*n;
	FOR(i, 1, 3) {
		random_shuffle(a+1, a+n+1);
		int lo = lis();
	    reverse(a+1, a+n+1);
	    int hi = lis();
	    if(lo+hi < best) {
	    	FOR(i, 1, n) ans[i] = a[i];
	    	best = lo+hi;
	    }
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    iota(a, a+n+1, 0);
    solve();
    FOR(i, 1, n) cout << ans[i] << ' ';
    cout << endl;
    // cout << best << endl;

    return 0;
}