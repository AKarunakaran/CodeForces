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
const int N = 50;

int g[N][N], n, m;

bool use(int r, int c) {
	vector<int> rows, cols;
	REP(i, n) if(g[i][c]) rows.push_back(i);
	REP(j, m) if(g[r][j]) cols.push_back(j);
	vector<bool> urow(n, 0), ucol(m, 0);
	for(int row : rows) urow[row] = 1;
	for(int col : cols) ucol[col] = 1;
	for(int row : rows) {
		REP(j, m) {
			if((ucol[j] && !g[row][j]) || (!ucol[j] && g[row][j])) return false;
		}
	}
	for(int col : cols) {
		REP(i, n) {
			if((urow[i] && !g[i][col]) || (!urow[i] && g[i][col])) return false;
		}
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    REP(i, n) {
    	REP(j, m) {
    		char c;
    		cin >> c;
    		g[i][j] = (c == '.' ? 0 : 1);
    	}
    }
    REP(i, n) {
    	REP(j, m) {
    		if(g[i][j]) {
    			if(!use(i, j)) {
    				cout << "No" << endl;
    				exit(0);
    			}
    		}
    	}
    }
    cout << "Yes" << endl;

    return 0;
}