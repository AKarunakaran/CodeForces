#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline int msbp(int x) {return 31-__builtin_clz(x);}
inline int msb(int x) {return 1 << msbp(x);}
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 1e5+10;

int n, k, a[N], t;
set<int> s;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    scanf("%d", &t);
    while(t--) {
    	s.clear();
    	scanf("%d %d", &n, &k);
    	REP(i, n) {
    		scanf("%d", &a[i]);
    		s.insert(a[i]);
    	}
    	if(s.size() > k) {
    		cout << -1 << '\n';
    		continue;
    	}
    	vector<int> period;
    	for(int x : s) period.push_back(x);
    	while(period.size() < k) period.push_back(period.back());
    	vector<int> ans;
    	int id = 0;
    	while(id < n) {
    		for(int x : period) {
    			if(id < n && a[id] == x) {
    				++id;
    			}
    			ans.push_back(x);
    		}
    	}
    	cout << ans.size() << '\n';
    	for(int x : ans) cout << x << ' ';
    	cout << '\n';
    }

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE) CHECK IF IT SHOULD BE 2*N!!!!
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
// - not clearing DS between test cases EVEN FOR INPUT (WA, RTE, TLE, MLE)
