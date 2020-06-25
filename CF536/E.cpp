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
typedef long long ll;
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
const ll lINF = 0x7fffffffffffffffLL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

struct event {
	int w, d;
	bool del;
};

const int N = 1e5+10, M = 210;
int n, m, k, poss[N][M];
ll dp[N][M];
vector<event> events[N];
multiset<pii> env;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    REP(i, N) REP(j, M) dp[i][j] = lINF;
    cin >> n >> m >> k;
    REP(i, k) {
    	int s, t, d, w;
    	cin >> s >> t >> d >> w;
    	events[s].push_back({w, d, 0});
    	events[t].push_back({w, d, 1});
    }

    poss[1][m] = 1;
    dp[1][m] = 0;
    FOR(i, 1, n) {
    	//process insert events
    	for(auto& ev : events[i]) if(!ev.del) env.insert({-ev.w, -ev.d});

    	pii cur{0, 0};
    	bool canmove = !env.empty();
    	if(canmove) cur = {-env.begin()->first, -env.begin()->second};

    	FORD(j, m, 0) {
    		if(!poss[i][j]) continue;
    		// cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << cur.first << ' ' << cur.second << endl;

	    	//alice disturbs
    		if(j && canmove) {
    			poss[i+1][j-1] = 1;
    			dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j]);
    		}
	    	//alice does not disturb
    		if(canmove) {
    			poss[cur.second+1][j] = 1;
    			dp[cur.second+1][j] = min(dp[cur.second+1][j], dp[i][j]+cur.first);
    		} else {
    			poss[i+1][j] = 1;
    			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
    		}
    	}

    	//process delete events
    	for(auto& ev : events[i]) if(ev.del) env.erase(env.find({-ev.w, -ev.d}));
    }
    ll ans = lINF;
    FORD(j, m, 0) ans = min(ans, dp[n+1][j]);
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
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)

