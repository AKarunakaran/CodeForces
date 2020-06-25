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

const int N = 51;
ll n, k, a[N], dp[N][N][N+10];
// dp[i][j][k] - the highest bitwise-AND after using j groups, with the jth group ending at index i-1, that has the kth bit as highest

int highestBit(ll x) {
	ll mask = 1LL << 62;
	int res = 63;
	while(mask) {
		if(mask & x) break;
		mask >>= 1;
		--res;
	}
	return res;
}

// void print() {
// 	REP(h, 8) {
// 		cout << "Bit " << h << ":" << endl;
// 		REP(i, n+1) {
// 			REP(j, k+1) {
// 				// cout << (dp[i][j][h] == 0x7fffffffffffffff ? "inf" :) << ' ';
// 			}
// 			cout << endl;
// 		}
// 		cout << endl;
// 	}
// }

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    REP(i, N) REP(j, N) REP(k, N+10) dp[i][j][k] = -1;
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    FOR(h, 0, N+9) dp[0][0][h] = 0x7fffffffffffffff;
    FOR(i, 0, n-1) { // i - current elt
		ll s = 0, cur;
    	FOR(j, i, n-1) { // j - next elt
    		s += a[j];
    		FOR(g, 0, k-1) { // g = current group
    			FOR(h, 0, N+9) { // h - current highest bit of previous groups
    				if(dp[i][g][h] == -1) continue;
    				// DEBUG(i);
    				// DEBUG(g);
    				// DEBUG(h);
    				cur = s & dp[i][g][h];
    				ll hb = highestBit(cur);
    				if(hb != h) continue;
    				dp[j+1][g+1][hb] = max(dp[j+1][g+1][hb], cur);
    			}
    		}
    	}
    	// dp[0][0][0] = 0;
    	print();
    }
    ll ans = 0;
    FOR(i, 0, N+9) {
    	DEBUG(dp[n-1][k][i]);
    	ans = max(ans, dp[n-1][k][i]);
    }
    cout << ans << endl;

    return 0;
}