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

const int N = 1e5+10;
int n, m, k, vis[N], onpath[N], d[N], cycle, ord[N];
vector<pii> g[N];
vector<int> ans;
pii edge[N];

void getans() {
	memset(d, 0, sizeof(d));
	memset(vis, 0, sizeof(vis));
	FOR(i, 1, n) {
		for(pii e : g[i]) {
			if(e.second <= k) continue;
			int v = e.first;
			++d[v];
		}
	}
	queue<int> nxt;
	FOR(i, 1, n) if(d[i] == 0) nxt.push(i);
	int idx = 1;
	while(!nxt.empty()) {
		int cur = nxt.front();
		ord[cur] = idx++;
		nxt.pop();
		for(pii e : g[cur]) {
			if(e.second <= k) continue;
			int v = e.first;
			--d[v];
			if(d[v] == 0) nxt.push(v);
		}
	}
	FOR(i, 1, m) if(ord[edge[i].second] < ord[edge[i].first]) ans.push_back(i);
}

void dfs(int s) {
	onpath[s] = vis[s] = 1;
	for(pii e : g[s]) {
		if(e.second <= k) continue;
		int v = e.first;
		if(onpath[v]) cycle = 1;
		if(!vis[v]) dfs(v);
	}
	onpath[s] = 0;
}

bool check(int num) {
	k = num;
	memset(vis, 0, sizeof(vis));
	cycle = 0;
	FOR(i, 1, n) if(!vis[i]) dfs(i);
	return !cycle;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    int lo = 0, hi = 1;
    FOR(i, 1, m) {
    	int u, v, c;
    	cin >> u >> v >> c;
    	edge[i] = {u, v};
    	g[u].push_back({v, c});
    	hi = max(hi, c);
    }
    while(lo < hi) {
    	int mid = (lo+hi)/2;
    	if(check(mid)) hi = mid;
    	else lo = mid+1;
    }
    k = lo;
    getans();
    cout << k << ' ' << ans.size() << endl;
    for(int x : ans) cout << x << ' ';
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
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
