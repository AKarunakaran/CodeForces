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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> g(n, vector<bool>(m));
    REP(i, n) {
    	REP(j, m) {
	    	char c;
	    	cin >> c;
	    	g[i][j] = (c != '.');
    	}
    }
    ll ans = 0;
    if(m >= k) {
	    REP(i, n) {
	    	int s = 0;
	    	FOR(j, 0, k-2) s += g[i][j];
	    	FOR(j, k-1, m-1) {
	    		s += g[i][j];
	    		if(s == 0) ++ans;
	    		s -= g[i][j-(k-1)];
	    	}
	    }
	}
    if(n >= k && k != 1) {
	    REP(j, m) {
	    	int s = 0;
	    	FOR(i, 0, k-2) s += g[i][j];
	    	FOR(i, k-1, n-1) {
	    		s += g[i][j];
	    		if(s == 0) ++ans;
	    		s -= g[i-(k-1)][j];
	    	}
	    }
    }
    cout << ans << endl;

    return 0;
}