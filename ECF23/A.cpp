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
    int x1, y1, x2, y2, x, y, xd, yd;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    xd = abs(x2-x1);
    yd = abs(y2-y1);
    if(xd % x != 0 || yd % y != 0) {
    	cout << "NO" << endl;
    	return 0;
    }
    int xj = xd/x, yj = yd/y;
	if((abs(xj-yj)) % 2 == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

    return 0;
}