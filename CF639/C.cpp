#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline int msbp(int x) {return 31-__builtin_clz(x);}
inline int msb(int x) {return 1 << msbp(x);}
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

void bad() {
	cout << -1 << endl;
	exit(0);
}

const int N = 2e5+10;

vector<int> g[N], rg[N];
int n, m, vis[N], d[N], num;
string ans;

void cycle() {
	int touched = 0;
	queue<int> nxt;
	FOR(i, 1, n) if(d[i] == 0) nxt.push(i);
	while(!nxt.empty()) {
		int cur = nxt.front();
		nxt.pop();
		++touched;
		for(int v : g[cur]) {
			--d[v];
			if(d[v] == 0) nxt.push(v);
		}
	}
	if(touched != n) bad();
}

void dfs(int s) {
	vis[s] = 1;
	for(int v : g[s])
		if(!vis[v])
			dfs(v);
}

void rdfs(int s) {
	vis[s] = 1;
	for(int v : rg[s])
		if(!vis[v])
			rdfs(v);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    ans.resize(n, 'E');
    REP(i, m) {
    	int a, b;
    	cin >> a >> b;
    	g[a].push_back(b);
    	rg[b].push_back(a);
    	++d[b];
    }
    cycle();
    FOR(i, 1, n) {
    	if(!vis[i]) {
    		++num;
    		ans[i-1] = 'A';
    	}
		dfs(i);
		rdfs(i);
    }
    cout << num << endl;
    cout << ans << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE) CHECK IF IT SHOULD BE 2*N!!!!
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
// - not clearing DS between test cases EVEN FOR INPUT (WA, RTE, TLE, MLE)
