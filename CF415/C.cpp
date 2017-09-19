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
inline ull two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    int n;
    ull s = 0;
    scanf("%d", &n);
    vector<int> x(n);
    REP(i, n) scanf("%d", &x[i]);
    sort(x.begin(), x.end());
	ull preSum = 1;
	ull dist;
	dist = (x[n-1]-x[0]) % 1000000007;
    s = (s + dist) % 1000000007;
    FOR(i, 3, n) {
		preSum = (preSum * 2) % 1000000007;
		if(n/i > 1) {
			FOR(j, 0, i-2) {
				int idx = (n/(i-1)*(i-1)+j)-1 >= n ? (n/(i-1)*(i-1)+j)-i-2 : (n/(i-1)*(i-1)+j)-1;
				dist = preSum*(x[idx]-x[j]) % 1000000007;
				s = (s + dist) % 1000000007;
			}
		} else {
			FOR(j, 0, n-i) {
	    		dist = (preSum*(x[j+i-1]-x[j])) % 1000000007;
	    		s = (s + dist) % 1000000007;
	    	}
		}
    }
    cout << s << endl;

    return 0;
}