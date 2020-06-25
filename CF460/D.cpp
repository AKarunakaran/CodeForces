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

const int N = 300001;

bool path[N];
char let[N];
vector<int> g[N], rg[N];
int best[N][26], rdeg[N];

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m;
    cin >> n >> m;
    FOR(i, 1, n) {
    	path[i] = rdeg[i] = 0;
    	REP(j, 26) best[i][j] = 0;
    }

    FOR(i, 1, n) {
    	cin >> let[i];
    	best[i][let[i]-'a'] = 1;
    }
    REP(i, m) {
    	int s, e;
    	cin >> s >> e;
    	g[s].push_back(e);
    	rg[e].push_back(s);
    	++rdeg[s];
    }
    int ans = 0, touched = 0;
    queue<int> next;
    FOR(i, 1, n) if(rdeg[i] == 0) next.push(i);
    while(!next.empty()) {
    	int cur = next.front();
    	++touched;
    	// DEBUG(cur);
    	next.pop();
    	for(int v : rg[cur]) {
    		--rdeg[v];
    		if(rdeg[v] == 0) next.push(v);
    	}
    	for(int v : g[cur]) {
	    	FOR(c, 0, 25) {
	    		if(let[cur]-'a' == c) {
	    			best[cur][c] = max(best[v][c]+1, best[cur][c]);
	    		} else {
	    			best[cur][c] = max(best[v][c], best[cur][c]);
	    		}
	    		ans = max(ans, best[cur][c]);
	    	}
    	}
    }
    // FOR(i, 1, n) {
    // 	REP(j, 26) cout << best[i][j] << ' ';
    // 	cout << endl;
    // }
    cout << (touched != n ? -1 : ans) << endl;

    return 0;
}