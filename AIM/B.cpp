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

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    ll two[61];
    two[0] = 1;
    FOR(i, 1, 60) two[i] = 2LL*two[i-1];
    REP(i, n) REP(j, m) cin >> g[i][j];
    REP(i, n) {
    	int one = 0;
    	REP(j, m) one += g[i][j];
    	ans += two[one]-1;
    	ans += two[m-one]-1;
    }
    REP(j, m) {
    	int one = 0;
    	REP(i, n) one += g[i][j];
    	ans += two[one]-one-1;
    	ans += two[n-one]-(n-one)-1;
    }
    cout << ans << endl;

    return 0;
}