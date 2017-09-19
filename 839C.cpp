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
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

vector<vector<int>> g;
vector<bool> checked;

double prob(int src) {
	int deg = 0;
	double ret = 0;
	REP(i, g[src].size()) if(!checked[g[src][i]]) ++deg;
	REP(i, g[src].size()) {
		if(!checked[g[src][i]]) {
			checked[g[src][i]] = 1;
			double add = 1+prob(g[src][i]);
			//DEBUG(src);
			//DEBUG(g[src][i]);
			//DEBUG(add);
			ret += add/deg;
		}
	}
	return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(7);
    int n;
    cin >> n;
    g.resize(n);
    checked.resize(n, 0);
    checked[0] = 1;
    REP(i, n-1) {
    	int a, b;
    	cin >> a >> b;
    	g[a-1].push_back(b-1);
    	g[b-1].push_back(a-1);
    }
    double ans = prob(0);
    cout << ans << endl;

    return 0;
}