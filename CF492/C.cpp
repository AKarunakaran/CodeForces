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

const int N = 50, K = 100;
int n, k, g[4][N];
vector<pair<int, pii>> ans;
bool done = true, bad = false;
vector<pii> loop;

void fillcars() {
	REP(i, n) {
		if(g[1][i] && g[1][i] == g[0][i]) {
			// DEBUG(g[1][i]);
			// DEBUG(1);
			// DEBUG(i);
			ans.push_back({g[1][i], {0, i}});
			g[1][i] = 0;
		}
		if(g[2][i] && g[2][i] == g[3][i]) {
			// DEBUG(g[2][i]);
			// DEBUG(2);
			// DEBUG(i);
			ans.push_back({g[2][i], {3, i}});
			g[2][i] = 0;
		}
	}
	done = true;
	bad = true;
	REP(i, n) if(g[1][i] || g[2][i]) done = false;
	REP(i, n) if(!g[1][i] || !g[2][i]) bad = false;
}

void cycle() {
	int idx = 0;
	REP(i, 2*n) {
		if(!g[loop[i].first][loop[i].second]) {
			idx = i;
			break;
		}
	}
	// DEBUG(idx);
	REP(i, 2*n-1) {
		int nxt = (idx+1)%(2*n);
		if(g[loop[nxt].first][loop[nxt].second]) {
			// DEBUG(loop[nxt].first);
			// DEBUG(loop[nxt].second);
			// DEBUG(g[loop[nxt].first][loop[nxt].second]);
			// DEBUG(loop[idx].first);
			// DEBUG(loop[idx].second);
			// DEBUG(g[loop[idx].first][loop[idx].second]);
			ans.push_back({g[loop[nxt].first][loop[nxt].second], loop[idx]});
			g[loop[idx].first][loop[idx].second] = g[loop[nxt].first][loop[nxt].second];
			g[loop[nxt].first][loop[nxt].second] = 0;
		}
		idx = (idx+1) % (2*n);
	}
}

void print() {
	REP(i, 4) {
		REP(j, n) cout << g[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    REP(i, 4) REP(j, n) cin >> g[i][j];
    REP(i, n) loop.push_back({1, i});
    FORD(i, n-1, 0) loop.push_back({2, i});
    while(1) {
    	fillcars();
    	// print();
    	if(done || bad) break;
    	cycle();
    	// print();
    }
    if(bad) cout << -1 << endl;
    else {
    	cout << ans.size() << endl;
    	for(auto& p : ans) cout << p.first << ' ' << p.second.first+1 << ' ' << p.second.second+1 << endl;
    }

    return 0;
}