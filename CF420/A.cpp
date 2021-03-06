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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    REP(i, n) REP(j, n) cin >> a[i][j];
    REP(i, n) {
    	REP(j, n) {
    		bool good = (a[i][j] == 1);
    		REP(k, n) {
    			REP(m, n) {
    				if(k == i || m == j) continue;
    				if(!good && a[k][j]+a[i][m] == a[i][j]) good = true;
    			}
    		}
    		if(!good) {
    			cout << "No" << endl;
    			return 0;
    		}
    	}
    }
    cout << "Yes" << endl;

    return 0;
}