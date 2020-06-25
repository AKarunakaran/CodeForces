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

const int N = 1010;
int n, l, k;
string s, ans[N];
map<char, int> m;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> l >> k >> s;
    --k;
    REP(i, s.size()) ++m[s[i]];
    int eeq = 0;
    REP(_, l) {
    	if(m.begin()->second == 0) m.erase(m.begin());
    	FOR(i, eeq, k) {
    		if(m.begin()->second == 0) {
    			m.erase(m.begin());
    			eeq = i;
    		}
    		char c = m.begin()->first;
    		ans[i].push_back(c);
    		--m[c];
    	}
    }
    if(m.begin()->second == 0) m.erase(m.begin());
    FOR(i, 0, n-1) {
    	while(ans[i].size() < l) {
    		char c = m.begin()->first;
    		ans[i].push_back(c);
    		--m[c];
    		if(m[c] == 0) m.erase(c);
    	}
    }
    REP(i, n) cout << ans[i] << endl;

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
