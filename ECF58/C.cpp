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

/////////////////////////////////////////////////////////////////////

const int N = 1e5+10;
int T, n, ans[N], hi[2], have;
pair<pii, int> seg[N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> T;
    while(T--) {
    	have = 0;
    	cin >> n;
    	REP(i, n) {
    		cin >> seg[i].first.first >> seg[i].first.second;
    		seg[i].second = i;
    	}
    	sort(seg, seg+n);
    	ans[seg[0].second] = 0;
    	hi[0] = seg[0].first.second;
    	hi[1] = 0;
    	FOR(i, 1, n-1) {
    		pii cur = seg[i].first;
    		if(cur.first <= hi[0]) {
    			ans[seg[i].second] = 0;
    			hi[0] = max(hi[0], cur.second);
    		} else if(cur.first <= hi[1]) {
    			ans[seg[i].second] = 1;
    			hi[1] = max(hi[1], cur.second);
    		} else {
    			if(have) {
    				ans[seg[i].second] = 0;
    				hi[0] = max(hi[0], cur.second);
    			} else {
    				ans[seg[i].second] = 1;
    				hi[1] = max(hi[1], cur.second);
    				have = 1;
    			}
    		}
    	}
    	if(!have) {
    		cout << -1 << endl;
    		continue;
    	}
    	REP(i, n) cout << ans[i]+1 << ' ';
    	cout << endl;
    }

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
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
