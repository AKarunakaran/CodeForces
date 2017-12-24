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
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

ll choose2(ll n) {
	return n & 1 ? ((n-1)/2)*n : (n/2)*(n-1);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll n, m, loop = 0;
    cin >> n >> m;
    vector<vector<ll>> g(n+1);
    REP(i, m) {
    	ll s, e;
    	cin >> s >> e;
    	if(s == e) {
    		++loop;
    	} else {
    		g[s].push_back(e);
    		g[e].push_back(s);
    	}
    }
    vector<bool> vis(n+1, 0);
    vis[1] = 1;
    queue<ll> next;
    next.push(1);
    while(!next.empty()) {
    	ll cur = next.front();
    	next.pop();
    	for(ll v : g[cur]) {
    		if(!vis[v]) {
    			vis[v] = 1;
    			next.push(v);
    		}
    	}
    }
    FOR(i, 1, n) {
    	if(!vis[i]) {
    		cout << 0 << endl;
    		exit(0);
    	}
    }
    ll ans = 0;
    FOR(i, 1, n) ans += choose2(g[i].size());
    ans += loop*(m-1);
    ans -= choose2(loop);
    cout << ans << endl;

    return 0;
}