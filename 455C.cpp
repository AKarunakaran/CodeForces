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
#include <numeric>
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

// Initialize with std::iota(parent, parent+n+1, 0), std::fill(sz, sz+n+1, 1);

const int N = 3e5+1; // Upper bound for n
int n, m, q, vis[N];
vector<int> g[N];

int parent[N];
int sz[N];

// Uses path compression
int find(int x) {return parent[x] = (x == parent[x] ? x : find(parent[x]));}

bool disjoint(int x, int y) {return find(x) != find(y);}

void join(int x, int y, bool s) {
	if (!disjoint(x, y)) return;
	int newPar = find(x), newChild = find(y);
	// DEBUG(sz[newPar]);
	// DEBUG(sz[newChild]);
	if(s) sz[newPar] = max(max(sz[newChild], sz[newPar]), (sz[newPar]+2)/2 + (sz[newChild]+2)/2);
	// DEBUG(sz[newPar]);
	parent[newChild] = newPar;
}

int dsuSize(int x) {return sz[find(x)];}

pii far(int s, int p) {
	vis[s] = 1;
	pii res = {1, s};
	for(int v : g[s]) {
		if(v != p) {
			pii cur = far(v, s);
			res = max(res, {cur.first+1, cur.second});
		}
	}
	return res;
}

int diam(int s) {return far(far(s, -1).second, -1).first;}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    iota(parent, parent+N, 0);
    fill(sz, sz+N, 0);
    fill(vis, vis+N, 0);
    cin >> n >> m >> q;
    REP(i, m) {
    	int a, b;
    	cin >> a >> b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    	join(a, b, 0);
    }
    FOR(i, 1, n) {
    	if(!vis[i]) {
    		sz[find(i)] = diam(i);
    	}
    }

    while(q--) {
    	int t, x, y;
    	cin >> t;
    	if(t == 1) {
    		cin >> x;
    		cout << dsuSize(x)-1 << endl;
    	} else {
    		cin >> x >> y;
    		join(x, y, 1);
    	}
    }

    return 0;
}