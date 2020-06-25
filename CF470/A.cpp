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
vector<vector<int>> g;
int r, c;

bool good(int i, int j) {
	if(i+1 < r) {
		if(g[i+1][j] == 2) return false;
		else if(g[i+1][j] == 0) g[i+1][j] = 3;
	}
	if(i > 0) {
		if(g[i-1][j] == 2) return false;
		else if(g[i-1][j] == 0) g[i-1][j] = 3;
	}
	if(j+1 < c) {
		if(g[i][j+1] == 2) return false;
		else if(g[i][j+1] == 0) g[i][j+1] = 3;
	}
	if(j > 0) {
		if(g[i][j-1] == 2) return false;
		else if(g[i][j-1] == 0) g[i][j-1] = 3;
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> r >> c;
    g.resize(r, vector<int>(c, 0));
    REP(i, r) {
    	REP(j, c) {
    		char ch;
    		cin >> ch;
    		if(ch == 'W') g[i][j] = 2;
    		else if(ch == 'S') g[i][j] = 1;
    	}
    }
    REP(i, r) {
    	REP(j, c) {
    		if(g[i][j] == 1) {
    			if(!good(i, j)) {
    				cout << "No" << endl;
    				exit(0);
    			}
    		}
    	}
    }
    cout << "Yes" << endl;
    // DEBUG(r);
    // DEBUG(c);
    REP(i, r) {
    	REP(j, c) {
    		if(g[i][j] == 0) cout << '.';
    		else if(g[i][j] == 1) cout << 'S';
    		else if(g[i][j] == 2) cout << 'W';
    		else if(g[i][j] == 3) cout << 'D';
    	}
    	cout << endl;
    }


    return 0;
}