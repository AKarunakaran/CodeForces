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

vector<vector<int>> g;

int perm_h(int n, int r, int c, int k) {
	if(n == r*c) {
		REP(i, r) {
			int prod = 1;
			REP(j, c) {
				prod *= g[i][j];
			}
			if(prod != k) return 0;
		}
		REP(j, c) {
			int prod = 1;
			REP(i, r) {
				prod *= g[i][j];
			}
			if(prod != k) return 0;
		}
		return 1;
	}
	int i = n/c, j = n%c;
	int ans = 0;
	g[i][j] = 1;
	ans += perm_h(n+1, r, c, k);
	g[i][j] = -1;
	ans += perm_h(n+1, r, c, k);
	return ans;
}

int perm(int i, int j, int k) {
	g.clear();
	g.resize(i, vector<int>(j));
	return perm_h(0, i, j, k);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
	FOR(i, 1, 5) {
    	FOR(j, 1, 5) {
    		int ans = perm(i, j, 1);
    		int ans2 = perm(i, j, -1);
    		cout << i << " " << j << " " << 1 << " " << ans << endl;
    		cout << i << " " << j << " " << -1 << " " << ans2 << endl << endl;
    	}
    }


    return 0;
}