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

const int N = 2e5+10;

int n, k, a[N], c[N];
vector<vector<int>> ans;

bool check(int num) {
	ans.clear();
	ans.resize(num);
	REP(i, n) ans[i%num].push_back(a[i]);
	// DEBUG(num);
	// REP(i, num) {
	// 	for(int x : ans[i]) cout << x << ' ';
	// 	cout << endl;
	// }
	REP(i, num) {
		map<int, int> curc;
		REP(j, ans[i].size()) ++curc[ans[i][j]];
		vector<pii> v;
		for(auto p : curc) v.push_back(p);
		int len = v.size();
		FORD(i, len-2, 0)
			v[i].second += v[i+1].second;
		// REP(i, len) cout << "(" << v[i].first << ' ' << v[i].second << ") ";
		// cout << endl;
		REP(i, len) {
			int id = upper_bound(c+1, c+1+k, v[i].second, greater<int>())-c;
			// cout << i << ' ' << id << endl;
			if(id <= v[i].first) return false;
		}
	}
	return true;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    sort(a, a+n);
    FOR(i, 1, k) cin >> c[i];
    int l = 1, r = n;
    while(l < r) {
    	int m = (l+r)/2;
    	if(check(m)) r = m;
    	else l = m+1;
    }
    check(l);
    cout << l << endl;
    for(auto& v : ans) {
    	cout << v.size() << ' ';
    	for(int x : v) cout << x << ' ';
    	cout << endl;
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
