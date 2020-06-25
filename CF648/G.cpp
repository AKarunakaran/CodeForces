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

const int N = 1e3+10;

int n, q = 13;
ll ans[N];

void answer() {
	cout << "! ";
	FOR(i, 1, n) cout << ans[i] << ' ';
	cout << endl;
	exit(0);
}

void set_union(set<int>& a, set<int>& b) {
	for(int x : b) a.insert(x);
}

ll query(vector<int> v) {
	cout << "? " << v.size() << ' ';
	for(int x : v) cout << x << ' ';
	cout << endl;
	ll res;
	cin >> res;
	return res;
}

void solve_easy() {
	set<int> all;
	FOR(i, 1, n) all.insert(i);
	FOR(i, 1, n) {
		all.erase(i);
		vector<int> cur(all.begin(), all.end());
		ans[i] = query(cur);
		all.insert(i);
	}
	answer();
}

const int MAGIC = 5;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    if(n <= q) solve_easy();
    vector<int> query_masks;
    vector<set<int>> queries(q);
    vector<ll> answers(q);
    int full = (1 << q)-1;
    FOR(i, 0, full) {
    	if(__builtin_popcount(i) == MAGIC)
    		query_masks.push_back(i);
    	if(query_masks.size() == n)
    		break;
    }
    REP(i, n) {
    	int mask = query_masks[i];
    	while(mask) {
    		int cur = msbp(mask & -mask);
    		queries[cur].insert(i+1);
    		mask -= (mask & -mask);
    	}
    }
    REP(i, q) {
    	if(queries[i].size() == 0) continue;
    	answers[i] = query(vector<int>(queries[i].begin(), queries[i].end()));
    	FOR(j, 1, n) {
    		if(!queries[i].count(j)) {
    			ans[j] |= answers[i];
    		}
    	}
    }
    answer();

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
