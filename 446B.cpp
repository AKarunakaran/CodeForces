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

const int N = 1000, K = 1e6;
int n, m, k, p, r[N], c[N], rv[K], cv[K];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> k >> p;
    REP(i, n) {
    	REP(j, m) {
    		int x;
    		cin >> x;
    		r[i] += x;
    		c[j] += x;
    	}
    }
    int coldec = 0, rowdec = 0;
    priority_queue<int> rpq, cpq;
    REP(i, n) rpq.push(r[i]);
    REP(i, m) cpq.push(c[i]);
    int ans = 0;
    REP(i, k) {
        int cur = rpq.top();
        rpq.pop();
        rv[i] = cur;
        rpq.push(cur-m*p);

        cur = cpq.top();
        cpq.pop();
        cv[i] = cur;
        cpq.push(cur-n*p);
    }
    int rs = 0, cs = 0;
    REP(i, k) rs += rv[i];
    REP(i, k+1) {
        ans = max(ans, rs+cs-i*(k-i)*p);
        if(i != k) {
            rs -= rv[k-1-i];
            cs += cv[i];
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
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
