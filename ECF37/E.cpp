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

vector<int> par, sz;

int find(int x) {return par[x] = (x == par[x] ? x : find(par[x]));}


int findSize(int x) {return sz[find(x)];}

bool disjoint(int x, int y) {return find(x) != find(y);}

void join(int x, int y) {
	if(disjoint(x, y)) {
		sz[find(y)] += findSize(x);
		par[find(x)] = find(y);
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    par.resize(n+1);
    sz.resize(n+1, 1);
    FOR(i, 1, n) par[i] = i;
    REP(i, m) {
    	int s, e;
    	cin >> s >> e;
    	g[s].push_back(e);
    	g[e].push_back(s);
    }
    FOR(i, 1, n) sort(g[i].begin(), g[i].end(), [](auto& left, auto& right){return left > right;});
    FORD(i, n, 1) {
    	int lowest = (i == n ? n-1 : n), idx = 0;
    	// DEBUG(i);
    	while(idx < g[i].size() && g[i][idx] == lowest) {
    		++idx;
    		++lowest;
    		if(lowest == i) ++lowest;
    	}
		// DEBUG(lowest);
    	// DEBUG(i);
    	if(lowest <= n) {
    		// DEBUG(lowest);
    		join(i, lowest);
    	}
    }
    set<pii> sizes;
    FOR(i, 1, n) {
    	sizes.insert({findSize(i), find(i)});
    	// DEBUG(i);
    	// DEBUG(find(i));
    }
    cout << sizes.size() << endl;
    for(auto p : sizes) cout << p.first << ' ';
    cout << endl;

    return 0;
}