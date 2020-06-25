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
typedef pair<int, char> pic;

/////////////////////////////////////////////////////////////////////

int dp[101][101][26];
vector<vector<pic>> g;

int rec(int a, int b, char c) {
	if(dp[a][b][c-'a'] != -1) return dp[a][b][c-'a'];
	bool good = false, canWin = false;
	for(pic e : g[a]) {
		if(e.second >= c) {
			good = true;
			canWin |= !rec(b, e.first, e.second);
		}
	}
	if(!good) dp[a][b][c-'a'] = 0;
	else dp[a][b][c-'a'] = canWin;
    
	return dp[a][b][c-'a'];
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    REP(i, m) {
    	int s, e;
    	char c;
    	cin >> s >> e >> c;
    	g[s].push_back({e, c});
    }
    FOR(i, 1, n) FOR(j, 1, n) REP(k, 26) dp[i][j][k] = -1;
    FOR(i, 1, n) FOR(j, 1, n) rec(i, j, 'a');
    FOR(i, 1, n) {
    	FOR(j, 1, n) cout << (dp[i][j][0] ? 'A' : 'B');
    	cout << endl;
    }

    return 0;
}