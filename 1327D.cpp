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
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 2e5+10;

int n, t, vis[N], p[N], c[N];
vector<vector<int>> divisors(N);

int vector_answer(vector<int>& v) {
	int len = v.size();
	int res = len;
	for(int d : divisors[len]) {
		REP(i, d) {
			bool good = true;
			for(int j = i+d; j < len; j += d) if(v[j] != v[j-d]) good = false;
			if(good) res = min(res, d);
		}
	}
	return res;
}

int cycle_answer(int id) {
	vector<int> colors;
	while(!vis[id]) {
		vis[id] = 1;
		colors.push_back(c[id]);
		id = p[id];
	}
	return vector_answer(colors);
}

int solve() {
	int ans = n;
	FOR(i, 1, n) if(!vis[i]) ans = min(ans, cycle_answer(i));
	return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    FOR(i, 1, N-1) for(int j = i; j < N; j += i) divisors[j].push_back(i);
    cin >> t;
    while(t--) {
    	cin >> n;
    	fill(vis, vis+n+1, 0);
    	FOR(i, 1, n) cin >> p[i];
    	FOR(i, 1, n) cin >> c[i];
    	cout << solve() << endl;
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
