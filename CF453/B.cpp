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

int ans = 0;
vector<int> c;
vector<vector<int>> g;

void dfs(int v, int cur, int par) {
	if(c[v] != cur) ++ans;
    for(auto i : g[v]) {
        if(i != par) dfs(i, c[v], v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    g.resize(n+1);
    REP(i, n-1) {
    	int e;
    	cin >> e;
    	g[i+2].push_back(e);
    	g[e].push_back(i+2);
    }
    c.resize(n+1);
    REP(i, n) cin >> c[i+1];
    dfs(1, 0, -1);
    cout << ans << endl;

    return 0;
}