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

vector<vector<char>> g;
vector<vector<bool>> vis;

void bfs(int r, int c) {
	vis[r][c] = 1;
	if(!vis[r-1][c] && g[r-1][c] == g[r][c]) bfs(r-1, c);
	if(!vis[r+1][c] && g[r+1][c] == g[r][c]) bfs(r+1, c);
	if(!vis[r][c-1] && g[r][c-1] == g[r][c]) bfs(r, c-1);
	if(!vis[r][c+1] && g[r][c+1] == g[r][c]) bfs(r, c+1);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m, v[4];
    REP(i, 4) v[i] = 0;
    cin >> n >> m;
    g.resize(n+2, vector<char>(m+2, 0));
    vis.resize(n+2, vector<bool>(m+2, 0));
    FOR(i, 1, n) FOR(j, 1, m) cin >> g[i][j];
    FOR(i, 1, n) FOR(j, 1, m) {
    	if(!vis[i][j]){
    		v[g[i][j]-'A']++;
    		// DEBUG(g[i][j]);
    		bfs(i, j);
    	}
    }
    REP(i, 4) cout << v[i] << ' ';
    cout << endl;

    return 0;
}