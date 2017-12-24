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

vector<vector<char>> g(9, vector<char>(9));

bool gridFull(int tr, int tc) {
	FOR(i, 3*tr, 3*tr+2) {
		FOR(j, 3*tc, 3*tc+2) {
			if(g[i][j] == '.') {
				return false;
			}
		}
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    REP(i, 9) REP(k, 3) REP(j, 3) cin >> g[i][3*k+j];
    int r, c;
    cin >> r >> c;
    --r; --c;
    int tr = r%3, tc = c%3;
    if(!gridFull(tr, tc)) {
    	FOR(i, 3*tr, 3*tr+2) {
    		FOR(j, 3*tc, 3*tc+2) {
    			if(g[i][j] == '.') {
    				g[i][j] = '!';
    			}
    		}
    	}
    } else {
    	REP(i, 9) {
    		REP(j, 9) {
    			if(g[i][j] == '.') {
    				g[i][j] = '!';
    			}
    		}
    	}
    }
    REP(i, 9) {
    	REP(k, 3) {
			REP(j, 3) cout << g[i][3*k+j];
			cout << " ";
    	}
    	cout << endl;
    	if(i % 3 == 2) cout << endl;
    }

    return 0;
}