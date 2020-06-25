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
const ll M = 1000000007;

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    vector<char> c(n);
    REP(i, n) cin >> c[i];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;
    REP(i, n-1) {
    	if(c[i] == 'f') {
    		dp[i+1][0] = 0;
    		FOR(j, 1, n-1) dp[i+1][j] = dp[i][j-1];
    	} else {
    		int s = 0;
    		FORD(j, n-1, 0) {
    			s = (s + dp[i][j]) % M;	
    			dp[i+1][j] = s;
    		}
    	}
    }
    int ans = 0;
    REP(i, n) ans = (ans+dp[n-1][i]) % M;
    cout << ans << endl;

    return 0;
}