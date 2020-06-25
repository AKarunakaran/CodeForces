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
#include <unordered_map>
#include <unordered_set>
using namespace std;
// #define int long long
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
typedef pair<double, double> pdd;

/////////////////////////////////////////////////////////////////////

const int N = 110;
int n;
double p[N];

signed main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin >> n;
    REP(i, n) cin >> p[i];
    sort(p, p+n);
    if(EQ(p[n-1], 1)) {
    	cout << 1 << endl;
    	exit(0);
    }
    double ans = 0;
    FOR(l, 1, n) {
    	REP(s, n+1-l) {
    		double cp = 1;
    		FOR(i, s, s+l-1) {
    			cp *= (1-p[i]);
    		}
    		double cur = 0;
    		FOR(i, s, s+l-1) cur += cp*p[i]/(1-p[i]);
    		ans = max(ans, cur);
    	}
    }
    cout << ans << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
