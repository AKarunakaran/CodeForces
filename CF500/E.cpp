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

const int N = 5010, K = 2510, inf = 9e8;
int n, a[N], dp[N][K][2];

// l == 1 means k-2 was made into a hill
int makehill(int k, int l) {
	int cost = 0;
	if(k != 0) {
		int pre = a[k-1];
		if(l) pre = min(pre, a[k-2]-1);
		if(pre >= a[k]) cost += pre-(a[k]-1);
	}
	if(k != n-1) {
		int nxt = a[k+1];
		if(nxt >= a[k]) cost += nxt-(a[k]-1);
	}
	return cost;
}

int rec(int k, int h, int l) {
	int& memo = dp[k][h][l];
	if(memo != -1) return memo;
	if(h == 0) {
		if(l) return memo = inf;
		else return memo = 0;
	}
	int res = inf;
	if(l) {
		if(k > 1) {
			res = min(res, rec(k-2, h-1, 0)+makehill(k, 0));
			res = min(res, rec(k-2, h-1, 1)+makehill(k, 1));
		} else if(h == 1) {
			res = min(res, makehill(k, 0));
		}
	} else {
		if(k) {
			res = min(res, rec(k-1, h, 0));
			res = min(res, rec(k-1, h, 1));
		}
	}
	// cout << k << ' ' << h << ' ' << l << endl;
	// DEBUG(res);
	// cout << endl;
	return memo = res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    REP(i, N) REP(j, K) dp[i][j][0] = dp[i][j][1] = -1;
    cin >> n;
    REP(i, n) cin >> a[i];
    FORD(i, (n+1)/2, 1) {
    	rec(n-1, i, 0);
    	rec(n-1, i, 1);
    }
    FOR(i, 1, (n+1)/2) cout << min(dp[n-1][i][0], dp[n-1][i][1]) << ' ';
    cout << endl;

    return 0;
}