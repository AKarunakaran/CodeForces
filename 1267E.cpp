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

const int N = 110;
int n, m, s[N];
vector<int> a[N], cancel(N);

void check(int c) {
	sort(a, a+m, [&](auto& left, auto& right){return left[n-1]-left[c] > right[n-1]-right[c];});
	int id = 0, dc = 0, dn = 0;
	vector<int> cur;
	while(s[n-1]-dn > s[c]-dc) {
		dc += a[id][c];
		dn += a[id][n-1];
		cur.push_back(a[id][n]);
		++id;
	}
	if(cur.size() < cancel.size()) cancel = cur;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    REP(i, m) {
    	a[i].resize(n);
    	REP(j, n) {
    		cin >> a[i][j];
    		s[j] += a[i][j];
    	}
    	a[i].push_back(i);
    }
    FOR(i, 0, n-2) check(i);
    cout << cancel.size() << endl;
    for(int x : cancel) cout << x+1 << ' ';
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
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
