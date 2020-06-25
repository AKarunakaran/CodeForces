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
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// #define int long long
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

const int N = 2e5+10;
int n, a[N];
vector<int> ig[N];
set<int> g[N];

void dfs(int s = 1, int p = 0) {
	g[p].insert(s);
	for(int v : ig[s]) if(v != p) dfs(v, s);
}

void bad() {
	cout << "No" << endl;
	exit(0);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n-1) {
    	int x, y;
    	cin >> x >> y;
    	ig[x].push_back(y);
    	ig[y].push_back(x);
    }
    REP(i, n) cin >> a[i];
    dfs();
    if(a[0] != 1) bad();
    int headidx = 0, childidx = 1;
    while(headidx < n) {
    	int head = a[headidx];
    	int children = g[head].size();
    	// DEBUG(head);
    	// DEBUG(children);
    	REP(i, children) {
    		if(childidx == n) bad();
    		int child = a[childidx];
    		// DEBUG(child);
    		if(g[head].count(child) != 1) bad();
    		++childidx;
    	}
    	++headidx;
    }
    cout << "Yes" << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - .size()-k underflow (WA, RTE, TLE)
// - const int N is correct (WA, RTE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
