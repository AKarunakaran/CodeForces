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

const int N = 2e5+10, C = 26;

int f[N][C], n, q;
string s;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> s >> q;
    n = s.size();
    s = " " + s;
    FOR(i, 1, n)
    	REP(j, C)
    		f[i][j] = f[i-1][j] + (s[i] == 'a'+j);
    while(q--) {
    	int l, r;
    	cin >> l >> r;
    	if(r-l+1 == 1) {
    		cout << "Yes" << endl;
    		continue;
    	}
    	map<int, int> m;
    	REP(i, C) if(f[r][i] != f[l-1][i]) m[i] = f[r][i]-f[l-1][i];
    	int nc = m.size();
    	int ms = INF;
    	// cout << l << ' ' << r << ":" << endl;
    	for(auto [k, v] : m) {
    		// cout << k << ' ' << v << endl;
    		ms = min(ms, v);
    	}
    	bool eeq = s[l] == s[r];
    	// cout << lg << ' ' << rg << endl;
    	cout << (nc > 1 ? (nc == 2 && eeq ? "No" : "Yes") : "No") << endl;
    	// cout << endl;
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
