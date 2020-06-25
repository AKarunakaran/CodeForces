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
#define int long long
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

const int N = 3010, P = 10;
int n, m, p, s[P], ans[P], d[P];
char g[N][N];
queue<pii> nxt[P];

bool allempty() {
	bool res = true;
	FOR(i, 1, p) res &= nxt[i].empty();
	return res;
}

bool inbounds(int r, int c) {
	return r >= 1 && r <= n && c >= 1 && c <= m;
}

bool valid(int r, int c) {
	return inbounds(r, c) && g[r][c] == '.';
}

void expand(pii pos, queue<pii>& q, int curp) {
	// cout << curp << ' ' << pos.first << ' ' << pos.second << ' ' << s[curp] << endl;
	int curs = s[curp];
	pii nxpos[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	REP(j, 4) {
		FOR(i, 1, curs) {
			pii npos = {pos.first+nxpos[j].first*i, pos.second+nxpos[j].second*i};
			if(!valid(npos.first, npos.second)) break;
			g[npos.first][npos.second] = curp+'0';
			++ans[curp];
			q.push({npos.first, npos.second});
		}
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> p;
    FOR(i, 1, p) {
    	cin >> s[i];
    }
    FOR(i, 1, n) {
    	FOR(j, 1, m) {
    		cin >> g[i][j];
    		if(g[i][j] >= '1' && g[i][j] <= '9') {
    			nxt[g[i][j]-'0'].push({i, j});
    			ans[g[i][j]-'0']++;
    		}
    	}
    }
    // int done = 0;
    while(1) {
    	// simulate a turn
    	FOR(curp, 1, p) {
    		// DEBUG(curp);
    		// if(d[curp]) continue;
    		queue<pii> curq = nxt[curp];
    		while(!nxt[curp].empty()) nxt[curp].pop();
    		while(!curq.empty()) {
    			pii cur = curq.front();
    			curq.pop();
    			expand(cur, nxt[curp], curp);
    		}
    		// if(nxt[curp].empty()) {
    		// 	++done;
    		// 	d[curp] = 1;
    		// }
    	}
	    // FOR(i, 1, n) {
	    // 	FOR(j, 1, m) {
	    // 		cout << g[i][j] << ' ';
	    // 	}
	    // 	cout << endl;
	    // }
	    // cout << endl;
    	if(allempty()) break;
    }


    FOR(i, 1, p) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
