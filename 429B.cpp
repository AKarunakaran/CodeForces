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

const int N = 1000;
int n, m, a[N][N], tl[N][N], tr[N][N], bl[N][N], br[N][N];

void print(int x) {
	REP(i, n) {
		// REP(j, m) cout << dp[x][i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    REP(i, n) REP(j, m) cin >> a[i][j];
    REP(i, n) {
    	REP(j, m) {
    		if(!i && !j) tl[i][j] = a[i][j];
    		else if (!i) tl[i][j] = a[i][j]+tl[i][j-1];
    		else if (!j) tl[i][j] = a[i][j]+tl[i-1][j];
    		else tl[i][j] = a[i][j]+max(tl[i][j-1], tl[i-1][j]);
    	}
    }
    REP(i, n) {
    	FORD(j, m-1, 0) {
    		if(!i && j == m-1) tr[i][j] = a[i][j];
    		else if (!i) tr[i][j] = a[i][j]+tr[i][j+1];
    		else if (j == m-1) tr[i][j] = a[i][j]+tr[i-1][j];
    		else tr[i][j] = a[i][j]+max(tr[i][j+1], tr[i-1][j]);
    	}
    }
    FORD(i, n-1, 0) {
    	REP(j, m) {
    		if(i == n-1 && !j) bl[i][j] = a[i][j];
    		else if (i == n-1) bl[i][j] = a[i][j]+bl[i][j-1];
    		else if (!j) bl[i][j] = a[i][j]+bl[i+1][j];
    		else bl[i][j] = a[i][j]+max(bl[i][j-1], bl[i+1][j]);
    	}
    }
    FORD(i, n-1, 0) {
    	FORD(j, m-1, 0) {
    		if(i == n-1 && j == m-1) br[i][j] = a[i][j];
    		else if (i == n-1) br[i][j] = a[i][j]+br[i][j+1];
    		else if (j == m-1) br[i][j] = a[i][j]+br[i+1][j];
    		else br[i][j] = a[i][j]+max(br[i][j+1], br[i+1][j]);
    	}
    }
    // REP(i, 4) print(i);
    int ans = 0;
    FOR(i, 1, n-2) {
    	FOR(j, 1, m-2) {
    		// p1 goes from tl to br, p2 goes from bl to tr
    		int p1enterl = tl[i][j-1], p1entert = tl[i-1][j];
    		int p1exitr = br[i][j+1], p1exitb = br[i+1][j];
    		int p2enterl = bl[i][j-1], p2enterb = bl[i+1][j];
    		int p2exitr = tr[i][j+1], p2exitt = tr[i-1][j];

    		int a1 = p1enterl + p1exitr + p2enterb + p2exitt;
    		int a2 = p1entert + p1exitb + p2enterl + p2exitr;


    		int a = max(a1, a2);

    		// DEBUG(a);

    		ans = max(ans, a);
    	}
    }
    cout << ans << endl;

    return 0;
}