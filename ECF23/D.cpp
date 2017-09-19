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
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

struct dpVal{
	int mn;
	int mx;
	int im;
};

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    /*
    vector<vector<dpVal>> dp(n, vector<dpVal>(n, {0, 0, 0}));
    REP(i, n) {
    	dp[i][i].mx = dp[i][i].mn = a[i];
    	dp[i][i].im = 0;
    }
    FOR(i, 1, n-1) {
    	FOR(j, 1, i) {
    		//DEBUG(i-j);
    		//DEBUG(i);
    		dp[i-j][i].mx = max(dp[i-j][i-1].mx, dp[i-j+1][i].mx);
    		dp[i-j][i].mn = min(dp[i-j][i-1].mn, dp[i-j+1][i].mn);
    		dp[i-j][i].im = dp[i-j][i].mx - dp[i-j][i].mn;
    	}
    }
    int ans = 0;
    REP(i, n) {
    	FOR(j, i, n-1) {
    		ans += dp[i][j].im;
    	}
    }
    cout << ans << endl;*/
    vector<dpVal> dp(n, {0, 0, 0}), dp2(n, {0, 0, 0});
    bool fts = 1;
    ll ans = 0;
    REP(i, n) dp[i].mx = dp[i].mn = a[i];
    REP(k, n-1) {
    	if(fts) {
    		REP(i, n-k-1) {
    			dp2[i].mx = max(dp[i].mx, dp[i+1].mx);
    			dp2[i].mn = min(dp[i].mn, dp[i+1].mn);
    			dp2[i].im = dp2[i].mx - dp2[i].mn;
    			ans += dp2[i].im;
    		}
    	} else {
    		REP(i, n-k-1) {
    			dp[i].mx = max(dp2[i].mx, dp2[i+1].mx);
    			dp[i].mn = min(dp2[i].mn, dp2[i+1].mn);
    			dp[i].im = dp[i].mx - dp[i].mn;
    			ans += dp[i].im;
    		}
    	}
    	fts = !fts;
    }
    cout << ans << endl;

    return 0;
}