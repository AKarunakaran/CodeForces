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

const int N = 2e3+10;

int t, n;

bool check(vector<int> a, int m) {
	vector<vector<int>> v(m);
	vector<pii> ans;
	int k = a.size();
	REP(i, k) v[a[i] % m].push_back(i+1);
	int rem = k;
	int id = 0;
	while(rem > 2 && id < m) {
		auto& cur = v[id];
		if(id == 0 || 2*id == m) {
			if(cur.size() >= 2) {
				ans.push_back({cur[cur.size()-2], cur[cur.size()-1]});
				cur.resize(cur.size()-2);
				rem -= 2;
			} else {
				++id;
			}
		} else {
			auto& oth = v[m-id];
			if(cur.size() && oth.size()) {
				ans.push_back({cur[cur.size()-1], oth[oth.size()-1]});
				cur.pop_back();
				oth.pop_back();
				rem -= 2;
			} else {
				++id;
			}
		}
	}
	if(rem == 2) {
		for(auto [x, y] : ans) cout << x << ' ' << y << endl;
	}
	return rem == 2;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> n;
    	int k = 2*n;
    	vector<int> a(k);
    	REP(i, k) cin >> a[i];
    	FOR(i, 2, 2*n) if(check(a, i)) break;
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
// - negative arithmetic, ceiling division, modulo (WA)
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
