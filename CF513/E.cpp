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
#define int long long
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
int n, par[N], dp1[N], dp2[N], sts[N];
vector<int> g[N], gc[N];

void getgc(int gf, int s, int d, int p) {
	if(d == 2) {
		gc[gf].push_back(s);
		return;
	}
	for(int v : g[s]) if(v != p) getgc(gf, v, d+1, s);
}

int getpar(int s, int p = -1) {
	par[s] = p;
	for(int v : g[s]) if(v != p) sts[s] += getpar(v, s);
	return ++sts[s];
}

void dfs(int s, int p = -1, int sibs = 0) {
	int children = (p != -1 ? g[s].size()-1 : g[s].size());
	for(int v : g[s]) {
		if(v != p) {
			dfs(v, s, children-1);
		}
	}
	for(int v : gc[s]) {
		dp1[s] += dp1[v]+sts[v];
	}
	dp1[s] += children;
	dp2[s] = dp1[s]+gc[s].size();
	vector<int> csz;
	for(int v : g[s]) {
		if(v != p) {
			csz.push_back(sts[v]);
		}
	}
	int csum = 0;
	for(int x : csz) csum += x;
	int ps = 0, totsum = 0;
	REP(i, csz.size()) {
		totsum += ps*csz[i];
		ps += csz[i];
	}
	dp2[s] += totsum;
	for(int v : g[s]) {
		if(v != p) {
			dp2[s] += dp1[v]*(csum-sts[v]);
		}
	}
	DEBUG(s);
	DEBUG(dp1[s]);
	DEBUG(dp2[s]);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(sts, 0, sizeof(sts));
    cin >> n;
    REP(i, n-1) {
    	int a, b;
    	cin >> a >> b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }
    getpar(1);
    FOR(i, 1, n) getgc(i, i, 0, par[i]);
    dfs(1);
    cout << dp2[1] << endl;

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
