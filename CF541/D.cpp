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

void bad() {
	cout << "No" << endl;
	exit(0);
}

// Initialize with std::iota(parent, parent+n+1, 0), std::fill(sz, sz+n+1, 1);

const int N = 2010; // Upper bound for n

int parent[N];
int sz[N];

// Uses path compression
int find(int x) {return parent[x] = (x == parent[x] ? x : find(parent[x]));}

bool disjoint(int x, int y) {return find(x) != find(y);}

void join(int x, int y) {
	if (!disjoint(x, y)) return;
	int newPar = find(x), newChild = find(y);
	// sz[newPar] += sz[newChild];
	parent[newChild] = newPar;
}

int dsuSize(int x) {return sz[find(x)];}

int n, m, s, ch[N][N], ans[N], onpath[N], vis[N];
vector<int> g[N];

void dfs(int s) {
	onpath[s] = vis[s] = 1;
	for(int v : g[s]) {
		if(onpath[v]) bad();
		if(!vis[v]) dfs(v);
	}
	int lo = 0;
	for(int v : g[s]) {
		lo = max(lo, ans[find(v)]);
	}
	ans[find(s)] = lo+1;
	onpath[s] = 0;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    s = n+m;
    std::iota(parent, parent+s+1, 0), std::fill(sz, sz+s+1, 1);
    REP(i, n) {
    	REP(j, m) {
    		char c;
    		cin >> c;
    		if(c == '=') {
    			ch[i][j] = 0;
    			join(i, n+j);
    		}
    		if(c == '>') ch[i][j] = 1;
    		if(c == '<') ch[i][j] = -1;
    	}
    }
    REP(i, n) {
    	REP(j, m) {
    		if(ch[i][j] == 1) {
    			g[find(i)].push_back(find(n+j));
    		} else if(ch[i][j] == -1) {
    			g[find(n+j)].push_back(find(i));
    		}
    	}
    }
    REP(i, n+m) if(!vis[i]) dfs(find(i));
    cout << "Yes" << endl;
    REP(i, n) cout << ans[find(i)] << ' ';
    cout << endl;
    REP(j, m) cout << ans[find(n+j)] << ' ';
    cout << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)

