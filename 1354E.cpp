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

const int N = 5e4+10;

int n, m, n1, n2, n3, c[N], l[N], vis[N];
vector<int> g[N];
set<int> red, blue;

void bad() {
	cout << "NO" << endl;
	exit(0);
}

void dfs(int s) {
	vis[s] = 1;
	if(l[s] == 1) red.insert(s);
	else blue.insert(s);
	for(int v : g[s]) {
		if(!vis[v]) {
			l[v] = 3-l[s];
			dfs(v);
		} else {
			if(l[v] == l[s]) bad();
		}
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> n1 >> n2 >> n3;
    REP(_, m) {
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    l[1] = 1;
    dfs(1);
    set<int> *twos, *oth;
    if(red.size() == n2) {
    	twos = &red;
    	oth = &blue;
    } else if(blue.size() == n2) {
    	twos = &blue;
    	oth = &red;
    } else {
    	bad();
    }
	for(int x : *twos) c[x] = 2;
	for(int x : *oth) {
		if(n1) {
			c[x] = 1;
			--n1;
		} else {
			c[x] = 3;
			--n3;
		}
	}
	cout << "YES" << endl;
	FOR(i, 1, n) cout << c[i];
	cout << endl;

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
