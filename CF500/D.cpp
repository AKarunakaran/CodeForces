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

const int N = 2e5+1;
int n, m, q, visr[N], visc[N], r[N], c[N];
vector<int> gr[N], gc[N];

void dfs(int row, int col, int fr) {
	visr[row] = 1;
	visc[col] = 1;
	if(fr != 1) {
		for(int x : gr[row]) {
			if(!visc[x]) dfs(row, x, 1);
		}
	}
	if(fr != 2) {
		for(int x : gc[col]) {
			if(!visr[x]) dfs(x, col, 2);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(visr, 0, sizeof(visr));
    memset(visc, 0, sizeof(visc));
    cin >> n >> m >> q;
    REP(i, q) {
    	cin >> r[i] >> c[i];
    	gr[r[i]].push_back(c[i]);
    	gc[c[i]].push_back(r[i]);
    }
    int ans = 0, g = 0;
    REP(i, q) {
    	if(!visr[r[i]] || !visc[c[i]]) {
    		dfs(r[i], c[i], 0);
    		++g;
    	}
    }
    ans = g-1;
    FOR(i, 1, n) if(!visr[i]) ++ans;
    FOR(i, 1, m) if(!visc[i]) ++ans;
    cout << ans << endl;

    return 0;
}