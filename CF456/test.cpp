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
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> f(n+1, vector<int>(m+1, 0));
    FOR(i, 1, n-r+1) {
    	FOR(j, 1, m-r+1) {
    		REP(k, r) {
    			REP(l, r) {
    				++f[i+k][j+l];
    			}
    		}
    	}
    }
    FOR(i, 1, n) {
    	FOR(j, 1, m) cout << f[i][j] << " ";
    	cout << endl;
    }
    cout << endl;
    FOR(tr, 1, min(r-1, min(n, m)-r)) {
    	int s = 0;
    	FOR(i, tr, n-tr+1) {
    		s += f[i][tr]+f[i][m-tr+1];
    	}
    	// DEBUG(s);
    	FOR(i, tr+1, m-tr) {
    		s += f[tr][i]+f[n-tr+1][i];
    	}
    	// DEBUG(s);
    	cout << tr << " " << s << endl;
    }

    return 0;
}