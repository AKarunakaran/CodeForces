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
int ts[N], te[N], lcat = 0;
vector<int> g[N], ba[N];

void lcadfs(int s, int p = 0, int d = 0) {
	ts[s] = lcat++;
	ba[s].push_back(p);
	for(int i = 1; d - (1 << i) >= 0; ++i)
		ba[s].push_back(ba[ba[s][i-1]][i-1]);

	for(int v : g[s])
		if(v != p)
			lcadfs(v, s, d+1);
	te[s] = lcat++;
}

bool anc(int u, int v) {return ts[u] <= ts[v] && te[u] >= te[v];}

int lca(int u, int v) {
	if(anc(u, v)) return u;
	if(anc(v, u)) return v;
	int l = ba[u].size()-1;
	FORD(i, l, 0) {
		if(i < ba[u].size() && !anc(ba[u][i], v))
			u = ba[u][i];
	}
	return ba[u][0];
}

int n, k, ans[N], beg[N], fin[N];
map<pii, int> m;

int dfs(int s, int p = 0) {
	int cur = 0;
	for(int v : g[s]) {
		if(v != p) {
			int eid = m[{s, v}];
			int res = dfs(v, s);
			ans[eid] += res;
			cur += res;
		}
	}
	cur += beg[s]-2*fin[s];
	return cur;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n-1) {
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    	m[{u, v}] = m[{v, u}] = i;
    }
    lcadfs(1);
    cin >> k;
    REP(i, k) {
    	int a, b;
    	cin >> a >> b;
    	++beg[a];
    	++beg[b];
    	++fin[lca(a, b)];
    }
    dfs(1);

    REP(i, n-1) cout << ans[i] << ' ';
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
