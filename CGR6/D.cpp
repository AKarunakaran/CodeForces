#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 1e5+10;
int n, m;
ll d[N];
queue<int> nxt;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    REP(i, m) {
    	int u, v, debt;
    	cin >> u >> v >> debt;
    	d[u] -= debt;
    	d[v] += debt;
    }
    FOR(i, 1, n) if(d[i] > 0) nxt.push(i);
    vector<pair<pii, ll>> ans;
    FOR(i, 1, n) {
    	while(d[i] < 0) {
    		ll debt = min(-d[i], d[nxt.front()]);
    		ans.push_back({{i, nxt.front()}, debt});
    		d[i] += debt;
    		d[nxt.front()] -= debt;
    		if(d[nxt.front()] == 0) nxt.pop();
    	}
    }
    cout << ans.size() << endl;
    for(auto& debt : ans) cout << debt.first.first << ' ' << debt.first.second << ' ' << debt.second << endl;

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
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
