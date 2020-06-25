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

const int N = 3e5+10;
int n, m, k, len, onpath[N], vis[N], cyc, pathid[N];
vector<int> g[N], cycles[N], path;

void anspath() {
	cout << "PATH" << endl;
	cout << path.size() << endl;
	for(int x : path) cout << x << ' ';
	cout << endl;
	exit(0);
}

void anscycle() {
	cout << "CYCLES" << endl;
	REP(i, cyc) {
		cout << cycles[i].size() << endl;
		for(int v : cycles[i]) cout << v << ' ';
		cout << endl;
	}
	exit(0);
}

void addcycle(int rep) {
	// for(int v : path) cout << v << ' ';
	// cout << endl;
	vector<int> nb;
	for(int v : g[rep]) {
		if(onpath[v]) {
			nb.push_back(pathid[v]);
			if(nb.size() == 3) break;
		}
	}
	sort(nb.begin(), nb.end());
	// for(int v : nb) cout << v << ' ';
	// cout << endl;
	vector<int>& cur = cycles[cyc++];
	int l, r;
	if((nb[1]-nb[0]) % 3 != 1) {
		l = nb[0], r = nb[1];
	} else if((nb[2]-nb[1]) % 3 != 1) {
		l = nb[1], r = nb[2];
	} else {
		l = nb[0], r = nb[2];
	}

	cur.push_back(rep);
	FOR(i, l, r) cur.push_back(path[i]);

	if(cyc >= k) anscycle();
}

void dfs(int s) {
	onpath[s] = 1;
	pathid[s] = path.size();
	vis[s] = 1;
	path.push_back(s);

	bool leaf = true;
	for(int v : g[s]) {
		if(!vis[v]) {
			leaf = false;
			dfs(v);
		}
	}
	if(path.size() >= len) anspath();
	if(leaf) addcycle(s);

	path.pop_back();
	pathid[s] = -1;
	onpath[s] = 0;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(pathid, -1, sizeof(pathid));
    cin >> n >> m >> k;
    len = (n+k-1)/k;
    REP(i, m) {
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(1);

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
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
