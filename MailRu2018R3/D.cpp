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
int n, p[N], l[N], ans[N], mark[N];
set<int> leaves;
set<pii> pq;
vector<int> g[N];

int dfs(int s) {
	l[s] = g[s].size() ? 0 : 1;
	for(int v : g[s]) l[s] += dfs(v);
	return l[s];
}


signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    fill(l+1, l+n+1, N);
    FOR(i, 1, n) leaves.insert(i);
    FOR(i, 2, n) {
    	cin >> p[i];
    	leaves.erase(p[i]);
    	g[p[i]].push_back(i);
	}
	dfs(1);
	for(auto& v : leaves) pq.insert({l[v], v});
	int last = 0, curs = 0;
	while(!pq.empty()) {
		int curl = pq.begin()->first;
		vector<int> v;
		while(pq.size() && pq.begin()->first == curl) {
			int vert = pq.begin()->second;
			v.push_back(vert);
			pq.erase(pq.begin());
		}
		for(int vert : v) {
			int par = p[vert];
			++mark[par];
			if(mark[par] == g[par].size()) pq.insert({l[par], par});
			curs++;
		}
		FOR(i, last+1, curs) ans[i] = curl;
		last = curs;

	}
	FOR(i, 1, n) cout << ans[i] << ' ';
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
