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
vector<pii> g[N];
int n, m, t[N], s[N], vis[N], ans[N];
map<pii, int> mp;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    FOR(i, 1, m) {
    	int u, v, c;
    	cin >> u >> v >> c;
    	g[u].push_back({v, c});
    	g[v].push_back({u, c});
    	s[u] += c;
    	s[v] += c;
    	mp[{u, v}] = i;
    	mp[{v, u}] = -i;
    }
    int src = 1;
    queue<int> nxt;
    nxt.push(src);
    while(!nxt.empty()) {
    	int cur = nxt.front();
    	nxt.pop();
    	vis[cur] = 1;
    	for(pii e : g[cur]) {
    		int v = e.first, c = e.second;
    		if(vis[v]) continue;
    		t[v] += c;
    		if(v != n && t[v] == s[v]/2) nxt.push(v);
    		int idx = mp[{cur, v}];
    		if(idx < 0) ans[-idx] = 1;
    		else ans[idx] = 0;
    	}
    }
    FOR(i, 1, m) cout << ans[i] << endl;

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
