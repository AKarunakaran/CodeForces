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

const int N = 3e5+10;
int n, a[N], seen[N], best = 0;
pii p[N];
vector<int> ans;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(seen, 0, sizeof(seen));
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) p[i] = {a[i], i};
    sort(p+1, p+n+1);
    FOR(num, 1, n) {
    	int idx = p[num].second;
    	if(seen[idx]) continue;
    	int l = idx, r = idx;
    	while(l >= 1 && a[l] % a[idx] == 0) --l;
    	while(r <= n && a[r] % a[idx] == 0) ++r;
    	FOR(i, l+1, r-1) seen[i] = 1;
    	if((r-1)-(l+1) > best) {
    		best = (r-1)-(l+1);
    		ans.clear();
    		ans.push_back(l+1);
    	} else if((r-1)-(l+1) == best) {
    		ans.push_back(l+1);
    	}
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << ' ' << best << endl;
    for(int x : ans) cout << x << ' ';
    cout << endl;

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
