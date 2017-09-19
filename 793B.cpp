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
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

bool g[1000][1000];
int ex = 0, ey = 0;
int n, m;

bool pathExists(int x, int y, int tl, int d) {
	//DEBUG(x);
	//DEBUG(y);
	if(x < 0 || x >= m || y < 0 || y >= n || tl < 0) return false;
	if(x == ex && y == ey) return true;
	if(!g[y][x]) return false;
	if(d != 3) if(pathExists(x+1, y, tl-(d!=1), 1)) return true;
	if(d != 4) if(pathExists(x, y+1, tl-(d!=2), 2)) return true;
	if(d != 1) if(pathExists(x-1, y, tl-(d!=3), 3)) return true;
	if(d != 2) if(pathExists(x, y-1, tl-(d!=4), 4)) return true;
	return false;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int sx = 0, sy = 0;
    char c, s;
    cin >> n >> m;
    REP(i, n) {
    	REP(j, m) {
    		cin >> c;
    		g[i][j] = (c != '*');
    		if(c == 'S') {
    			sx = j;
    			sy = i;
    		}
    		if(c == 'T') {
    			ex = j;
    			ey = i;
    		}
    	}
    }
    /*REP(i, n) {
    	REP(j, m) {
    		cout << g[i][j] << " ";
    	}
    	cout << endl;
    }*/
    if(pathExists(sx, sy, 2, 1)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}