#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 2e5+10;
int n, m, t, a, b, vis[N];
vector<int> g[N];

void dfs(int s, int block, set<int>& st) {
	vis[s] = 1;
	st.insert(s);
	if(s != block) for(int v : g[s]) if(!vis[v]) dfs(v, block, st);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> n >> m >> a >> b;
    	FOR(i, 1, n) g[i].clear();
    	FOR(i, 1, m) {
    		int u, v;
    		cin >> u >> v;
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
    	set<int> sa, sb;

    	fill(vis, vis+n+1, 0);
    	dfs(a, b, sa);

    	fill(vis, vis+n+1, 0);
    	dfs(b, a, sb);
    	
    	vector<int> va, vb;
    	for(int x : sa) if(sb.count(x) == 0) va.push_back(x);
    	for(int x : sb) if(sa.count(x) == 0) vb.push_back(x);
    		
    	ll ans = (ll)va.size()*vb.size();
    	cout << ans << endl;
    }

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
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
