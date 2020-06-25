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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////
const int N = 5e3+2;
int n, q, a[N], two[21], dp[N][N], mid[N][N], ans[N][N];

int f(int l, int r) {
	int& memo = dp[l][r];
	if(memo != -1) return memo;
	if(l == r) return memo = a[l];
	int len = r-l+1;
	auto itr = lower_bound(two, two+21	, len);
	--itr;
	int ht = *itr;
	int rem = len-ht;
	return memo = (f(l, l+rem-1) ^ f(l+ht, l+ht+rem-1));
}

int main() {
    ios::sync_with_stdio(false);
    REP(i, N) {
    	fill(dp[i], dp[i]+N, -1);
    	fill(mid[i], mid[i]+N, 0);
    	fill(ans[i], ans[i]+N, 0);
    }
    //cout << fixed << setprecision(7);
    two[0] = 1;
    FOR(i, 1, 20) two[i] = two[i-1] << 1;
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) {
    	FOR(j, i, n) {
    		f(i, j);
    		mid[i][j] = max(mid[i][j-1], dp[i][j]);
    	}
    }

    // FOR(i, 1, n) {
    // 	FOR(j, i ,n) cout << dp[i][j] << ' ';
    // 	cout << endl;
    // }
    // cout << endl;
    FORD(j, n, 1) {
    	FORD(i, j, 1) {
    		ans[i][j] = max(ans[i+1][j], mid[i][j]);
    	}
    }
    cin >> q;
    while(q--) {
    	int l, r;
    	cin >> l >> r;
    	cout << ans[l][r] << endl;
    }

    return 0;
}