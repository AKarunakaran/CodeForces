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
 
vector<ll> parent, sz, idxs;
vector<pll> a;
vector<vector<ll>> g;


// Returns the root element of the set
ll find(ll x) { return parent[x] = (x == parent[x] ? x : find(parent[x])); }
 
ll size(ll x) { return sz[find(x)]; }

// Union of two sets
void join(ll x, ll y) { 
	x = find(x);
	y = find(y);
	if(x == y) return;
	ll newS = sz[x]+sz[y];
	sz[x] = sz[y] = newS;
	parent[x] = y;
}
 
// Returns true, if sets containing elements `x` and `y` are disjoll
bool disjoll(ll x, ll y) { return find(x) != find(y); }

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll n;
    cin >> n;
    a.resize(n+1);
    idxs.resize(n+1);
    parent.resize(n+1);
    FOR(i, 1, n) parent[i] = i;
    sz.resize(n+1, 1);
    g.resize(n+1);
    FOR(i, 1, n) {
    	cin >> a[i].first;
    	a[i].second = i;
    }
    sort(a.begin(), a.end());
    FOR(i, 1, n) idxs[a[i].second] = i;
    REP(i, n-1) {
    	ll s, e;
    	cin >> s >> e;
    	g[s].push_back(e);
    	g[e].push_back(s);
    }
    ll maxS = 0, minS = 0;
    FOR(i, 1, n) {
    	ll cur = a[i].second;
    	// DEBUG(cur);
    	ll ps = 0, total = 1;
    	bool first = true;
    	for(ll v : g[cur]) {
    		if(idxs[v] < i) {
    			ll s = size(v);
    			total += s;
    			if(first) {
    				first = false;
    			} else {
    				total += ps*s;
    			}
    			ps += s;
    			join(v, cur);
    		}
    	}
    	// DEBUG(total);
    	maxS += a[i].first*total;
    }
    FOR(i, 1, n) parent[i] = i;
    fill(sz.begin(), sz.end(), 1);
    FORD(i, n, 1) {
    	ll cur = a[i].second;
    	// DEBUG(cur);
    	ll ps = 0, total = 1;
    	bool first = true;
    	for(ll v : g[cur]) {
    		if(idxs[v] > i) {
    			ll s = size(v);
    			total += s;
    			if(first) {
    				first = false;
    			} else {
    				total += ps*s;
    			}
    			ps += s;
    			join(v, cur);
    		}
    	}
    	// DEBUG(total);
    	minS += a[i].first*total;
    }
    cout << maxS-minS << endl;

    return 0;
}