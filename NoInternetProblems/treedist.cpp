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
using namespace std; 
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

const int N = 1e5+1;
int n, k, hdi, h[N], curlen = -1, ans = 0;
vector<int> g[N];

pii far(int s, int p = -1) {
	pii res = {1, s};
	for(int v : g[s]) {
		if(v != p) {
			pii test = far(v, s);
			res = max(res, {test.first+1, test.second});
		}
	}
	return res;
}

bool findhalf(int s, int p, int dest, int l) {
	if(s == dest) return true;
	++curlen;
	for(int v : g[s]) {
		if(v != p) {
			if(findhalf(v, s, dest, l) && curlen == l/2) {
				hdi = s;
				return true;
			}
		}
	}
	--curlen;
	return false;
}

void diam() {
	int v = far(1).second;
	pii d = far(v);
	findhalf(v, -1, d.second, d.first);
}

int hdfs(int s, int p = -1) {
	int res = 1;
	for(int v : g[s]) {
		if(v != p) {
			res = max(res, hdfs(v));
		}
	}
	return h[s] = res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    REP(i, n-1) {
    	int a, b;
    	cin >> a >> b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }
    diam();
    hdfs(hdi);
    set<pair<int, pii>> s;
    for(int v : g[hdi]) {
    	s.insert({-h[v], {v, hdi}});
    }
    bool first = false;
    REP(i, k-1) {
    	int tgt = s.begin()->second.first;
    	int par = s.begin()->second.second;
    	s.erase({-h[tgt], {tgt, par}});
    	if(par != s || (par == s && first)) {
    		for(int v : g[par]) {
    			if(v != tgt) ans = max(ans, h[v]);
    			s.erase({-h[v], {v, par}});
    		}
    	} else if (par == s && !first) {
    		first = true;
    	}
    	for(int v : g[tgt]) {
    		s.insert({-h[v], {v, tgt}});
    	}
    }
    for(auto& p : s) {
    	ans = max(ans, -p.first);
    }
    cout << ans << endl;

    return 0;
}