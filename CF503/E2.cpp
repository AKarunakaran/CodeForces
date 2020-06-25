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

const int N = 1e6+10;
vector<int> g[N], rg[N];
int n, m, q[N], d[N], r[N];
set<pii> vd;

void qify(int s) {
	q[s] = 1;
	queue<int> nxt, dnxt;
	for(int v : g[s]) {
		if(!r[v]) {
			r[v] = 1;
			nxt.push(v);
			vd.erase({d[v], v});
			--d[v];
			vd.insert({d[v], v});
		}
	}
	while(!nxt.empty()) {
		int cur = nxt.front();
		nxt.pop();
		for(int v : g[cur]) {
			if(!r[v]) {
				r[v] = 1;
				dnxt.push(v);
				vd.erase({d[v], v});
				--d[v];
				vd.insert({d[v], v});
			}
		}
	}
	while(!dnxt.empty()) {
		int cur = dnxt.front();
		dnxt.pop();
		for(int v : g[cur]) {
			if(!r[v]) {
				r[v] = 1;
				vd.erase({d[v], v});
				--d[v];
				vd.insert({d[v], v});
			}
		}
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(q, 0, sizeof(q));
    memset(r, 0, sizeof(r));
    memset(d, 0, sizeof(d));
    cin >> n >> m;
    REP(i, m) {
    	int a, b;
    	cin >> a >> b;
    	g[a].push_back(b);
    	rg[a].push_back(a);
    	++d[b];
    }
    FOR(i, 1, n) vd.insert({d[i], i});
    while(vd.size()) {
    	int cur = vd.begin()->second;
    	vd.erase(vd.begin());
    	if(!r[cur]) {
    		bool bad = false;
    		for(int v : rg[cur]) if(q[v]) bad = true, break;
    		if(bad) continue;
    		r[cur] = 1;
    		qify(cur);
    	}
    }

    vector<int> ans;
    FOR(i, 1, n) if(q[i]) ans.push_back(i);
    cout << ans.size() << endl;
    for(int x : ans) cout << x << ' ';
    cout << endl;

    return 0;
}