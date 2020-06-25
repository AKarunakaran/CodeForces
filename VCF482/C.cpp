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
const int N = 3e5+1;
int n, x, y, path[2];
vector<int> g[N];

bool findpath(int s, int p) {
	for(int v : g[s]) {
		if(v != p) {
			if(v == y) {
				path[1] = s;
				if(s == x) path[0] = v;
				return true;
			}
			if(findpath(v, s)) {
				if(s == x) path[0] = v;
				return true;
			}
		}
	}
	return false;
}

ll dfs(int s, int p) {
	ll tot = 1;
	for(int v : g[s]) if(v != p) tot += dfs(v, s);
	return tot;
}

ll choose(ll a) {
	return (a*(a-1))/2;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> x >> y;
    REP(i, n-1) {
    	int a, b;
    	cin >> a >> b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }
    ll s[4];
    fill(s, s+4, 0);
    findpath(x, -1);
    // DEBUG(path[0]);
    // DEBUG(path[1]);
    s[0] = dfs(x, path[0]), s[1] = dfs(y, path[1]);
    s[2] = n-s[0]-s[1];
    // REP(i, 3) cout << s[i] << ' ';
    // cout << endl;
    int s1 = 0, s2 = 1, mid = 2;
    ll ans = choose(s[s1]+s[mid])+choose(s[s2]+s[mid])+choose(n)-choose(s[mid]);
    cout << ans << endl;

    return 0;
}