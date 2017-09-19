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
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

ll n, a[200001], ans[200001] = {}, d[200001];
vector<int> path;
vector<pii> g[200001];

void bs() {
	ll v = path.back(), lo = 0, hi = path.size()-1;
	while(lo <= hi) {
		int mid = (hi+lo)/2;
		if (d[v]-d[path[mid]] <= a[v]) hi = mid-1;
		else lo = mid+1;
		if(d[v]-d[path[mid]] == a[v]) break;
	}
	++ans[path[path.size()-2]];
	if(hi > -1) --ans[path[hi]];
}

void dfs(ll cur) {
	for(auto i : g[cur]) {
		d[i.first] = d[cur]+i.second;
		path.push_back(i.first);
		dfs(i.first);
		path.pop_back();
	}
	if(cur > 1) bs();
	for(auto i : g[cur]) ans[cur] += ans[i.first];
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    scanf("%lld", &n);
    FOR(i, 1, n) scanf("%lld", a+i);
    FOR(i, 2, n) {
    	int p, w;
    	scanf("%d %d", &p, &w);
    	g[p].push_back({i, w});
    }
    path.push_back(1);
    d[1] = 0;
    dfs(1);
    FOR(i, 1, n) printf("%lld ", ans[i]);
    printf("\n");

    return 0;
}