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
const int INF = 0x3f3f3f3f;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////
const int MAXN = 10;
vector<vector<pii>> g;
int d[MAXN];
bool mark[MAXN];
int n;
int prim(){
	fill(d, d + n, INF);
	fill(mark, mark + n, false);
	int x,v;
	int res = 0;
	while(true){
		x = INF;
		v = -1;
		for(int i = 0;i < n;i ++) {
			if(!mark[i] and x >= d[i]) {
				x = d[i], v = i;
			}
		}
		if(v == -1)
			break;
		d[v] = 0;
		mark[v] = true;
		res += (x == INF ? 0 : x);

		for(auto p : g[v]){ //adj[v][i] = pair(vertex, weight)
			int u = p.first, w = p.second;
			d[u] = min(d[u], w);
		}
	}
	return res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    g.resize(n);
    REP(i, n) {
    	REP(j, n) if(i != j) g[i].push_back({j, i ^ j});
    }
    cout << prim() << endl;

    return 0;
}