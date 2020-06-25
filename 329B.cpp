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
#include <unordered_map>
#include <unordered_set>
using namespace std;
// #define int long long
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

const int N = 1000;
int r, c, g[N][N], vis[N][N], d[N][N];
pii s, e;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(vis, 0, sizeof(vis));
    memset(d, INF, sizeof(d));
    cin >> r >> c;
    REP(i, r) {
    	REP(j, c) {
    		char ch;
    		cin >> ch;
    		if(ch == 'E') e = {i, j};
    		if(ch == 'S') s = {i, j};
    		if(ch == 'T') g[i][j] = -1;
    		else if(ch >= '0' && ch <= '9') g[i][j] = ch-'0';
    		else g[i][j] = 0;
    	}
    }

    queue<pii> nxt;
    nxt.push(e);
    vis[e.first][e.second] = 1;
    d[e.first][e.second] = 0;
    while(!nxt.empty()) {
    	pii cur = nxt.front();
    	nxt.pop();
    	if(cur.first > 0 && !vis[cur.first-1][cur.second] && g[cur.first-1][cur.second] != -1) {
    		vis[cur.first-1][cur.second] = 1;
    		d[cur.first-1][cur.second] = d[cur.first][cur.second]+1;
    		nxt.push({cur.first-1, cur.second});
    	}
    	if(cur.first < r-1 && !vis[cur.first+1][cur.second] && g[cur.first+1][cur.second] != -1) {
    		vis[cur.first+1][cur.second] = 1;
    		d[cur.first+1][cur.second] = d[cur.first][cur.second]+1;
    		nxt.push({cur.first+1, cur.second});
    	}
    	if(cur.second > 0 && !vis[cur.first][cur.second-1] && g[cur.first][cur.second-1] != -1) {
    		vis[cur.first][cur.second-1] = 1;
    		d[cur.first][cur.second-1] = d[cur.first][cur.second]+1;
    		nxt.push({cur.first, cur.second-1});
    	}
    	if(cur.second < c-1 && !vis[cur.first][cur.second+1] && g[cur.first][cur.second+1] != -1) {
    		vis[cur.first][cur.second+1] = 1;
    		d[cur.first][cur.second+1] = d[cur.first][cur.second]+1;
    		nxt.push({cur.first, cur.second+1});
    	}
    }

    int ds = d[s.first][s.second];
    int ans = 0;
    REP(i, r) REP(j, c) if(d[i][j] <= ds) ans += g[i][j];
    cout << ans << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
