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

const ll N = 1e5+1, M = 1e9+7;
ll t, k, a, b, dp[N], ps[N];

ll add(ll x, ll y) {return (x+y) % M;}
ll sub(ll x, ll y) {return (x+M-y) % M;}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(dp, dp+N, 0);
    fill(ps, ps+N, 0);
    cin >> t >> k;
    dp[0] = 1;
    FOR(i, 1, N-1) {
    	dp[i] = add(dp[i], dp[i-1]);
    	if(i >= k) dp[i] = add(dp[i], dp[i-k]);
    }
    ps[0] = 1;
    FOR(i, 1, N-1) ps[i] = add(dp[i], ps[i-1]);
    while(t--) {
    	cin >> a >> b;
    	cout << sub(ps[b], ps[a-1]) << endl;
    }

    return 0;
}