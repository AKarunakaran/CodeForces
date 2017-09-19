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

ll ts, tf, t, n, p[100000], s[100000], best, ans;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    scanf("%lld %lld %lld %lld", &ts, &tf, &t, &n);
    REP(i, n) scanf("%lld", &p[i]);
    if(n == 0 || p[0] > ts) {
    	printf("%lld", ts);
    	return 0;
    }
    s[0] = max(ts, p[0]);
    FOR(i, 1, n-1) s[i] = max(s[i-1]+t, p[i]);
    best = max(ts, p[0]-1)-(p[0]-1);
    ans = p[0]-1;
    FOR(i, 1, n-1) {
    	if(s[i-1]+t >= tf) break;
    	if(p[i]-p[i-1] > 1) {
    		if(max(s[i-1]+t, p[i]-1)-(p[i]-1) < best) {
    			best = max(s[i-1]+t, p[i]-1)-(p[i]-1);
    			ans = p[i]-1;
    		}
    	}
    }
    if(s[n-1]+t <= tf-t) ans = s[n-1]+t;
    printf("%lld\n", ans);

    return 0;
}