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
const int N = 10;
int n, k, ans = INF;
vector<pii> a;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    for(int i = 1; i < n; i *= 2, ++k);
    REP(i, n) {
    	int x;
    	cin >> x;
    	a.push_back({i, x});
    }
    do {
    	vector<pii> ta = a;
    	int cur = 0;
    	REP(i, k) {
    		vector<pii> na;
    		for(int j = 0; j < ta.size(); j += 2) {
    			pii p1 = ta[j], p2 = ta[j+1];
    			if(p1.second == -1) {
    				na.push_back(p1);
    				if(p2.first > p1.first) cur += p2.second;
    			} else if(p2.second == -1) {
    				na.push_back(p2);
    				if(p1.first > p2.first) cur += p1.second;
    			} else if(p1.first > p2.first) {
    				na.push_back(p1);
    			} else {
    				na.push_back(p2);
    			}
    		}
    		ta = na;
    	}
    	ans = min(ans, cur);
    } while(next_permutation(a.begin(), a.end()));

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
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
