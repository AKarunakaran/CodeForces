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
const int INF = 0x3f3f3f3f;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 1e5+10;
int n, m, d[N];
map<int, int> t[N];
vector<pii> g[N];
set<pii> nxt;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(d, INF, sizeof(d));
    cin >> n >> m;
    REP(i, m) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	g[a].push_back({b, c});
    	g[b].push_back({a, c});
    }
    FOR(i, 1, n) {
    	int k;
    	cin >> k;
    	auto& mp = t[i];
    	while(k--) {
    		int x;
    		cin >> x;
    		mp[x] = x+1;
    	}
    	for(auto itr = mp.rbegin(); itr != mp.rend(); ++itr) {
    		if(mp.find(itr->first+1) != mp.end()) 
    			mp[itr->first] = mp[itr->first+1];
    	}
    }
    d[1] = 0;
    nxt.insert({0, 1});
    while(!nxt.empty()) {
    	int cur = nxt.begin()->second;
    	nxt.erase(nxt.begin());
    	int add = t[cur].find(d[cur]) == t[cur].end() ? 0 : t[cur][d[cur]]-d[cur];
    	for(pii e : g[cur]) {
    		int v = e.first, w = e.second;
    		if(d[cur]+add+w < d[v]) {
    			nxt.erase({d[v], v});
    			d[v] = d[cur]+add+w;
    			nxt.insert({d[v], v});
    		}
    	}
    }
    cout << (d[n] == INF ? -1 : d[n]) << endl;

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
