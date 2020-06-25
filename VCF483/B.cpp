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
const int N = 1e2+2;
int n, m, g[N][N];

bool check(int r, int c) {
	int cnt = 0;
	FOR(i, r-1, r+1) {
		FOR(j, c-1, c+1) {
			if(g[i][j] == 9) ++cnt;
		}
	}
	return g[r][c] == cnt;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    FOR(i, 0, n+1) fill(g[i], g[i]+m, 0);
    FOR(i, 1, n) {
    	FOR(j, 1, m) {
	    	char ch;
	    	cin >> ch;
	    	if(ch == '*') g[i][j] = 9;
	    	else if(ch == '.') g[i][j] = 0;
	    	else g[i][j] = ch-'0';
    	}
    }
    FOR(i, 1, n) {
    	FOR(j, 1, m) {
    		if(g[i][j] != 9 && !check(i, j)) {
    			cout << "NO" << endl;
    			exit(0);
    		}
    	}
    }
    cout << "YES" << endl;


    return 0;
}