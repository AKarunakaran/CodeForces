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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    if(min(a, b) != 1) {
    	cout << "NO" << endl;
    	exit(0);
    }
    if(a == 1 && b == 1 && (n == 2 || n == 3)) {
    	cout << "NO" << endl;
    	exit(0);
    }
    FOR(i, 1, n-max(a, b)) ans[i-1][i] = ans[i][i-1] = 1;
    if(a < b) {
    	REP(i, n) REP(j, n) if(i != j) ans[i][j] = 1-ans[i][j];
    }
    cout << "YES" << endl;
    REP(i, n) {
    	REP(j, n) cout << ans[i][j];
    	cout << endl;
    }

    return 0;
}