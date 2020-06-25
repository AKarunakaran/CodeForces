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
const ll N = 1e5;
ll n, a[N], f[N], dp[N], h = 0;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(f, f+N, 0);
    fill(dp, dp+N, 0);
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) h = max(h, a[i]);
    if(n == 1) {
    	cout << a[0] << endl;
    	exit(0);
    }
    REP(i, n) f[a[i]-1] += a[i];
    // REP(i, h) cout << f[i] << ' ';
    // cout << endl;
    dp[0] = f[0];
    dp[1] = max(f[1], dp[0]);
    FOR(i, 2, h-1) dp[i] = max(dp[i-1], f[i]+dp[i-2]);
    cout << dp[h-1] << endl;

    return 0;
}