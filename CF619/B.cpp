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

int t, n, a[N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	set<int> s;
    	cin >> n;
    	FOR(i, 1, n) cin >> a[i];
    	a[0] = a[2];
    	a[n+1] = a[n-1];
    	FOR(i, 1, n) {
    		if(a[i] == -1) {
    			s.insert(a[i-1]);
    			s.insert(a[i+1]);
    		}
    	}
    	s.erase(-1);
    	int k;
    	if(s.empty()) k = 0;
    	else {
	    	int l = *s.begin(), r = *s.rbegin();
	    	k = (l+r)/2;
    	}
    	FOR(i, 1, n) if(a[i] == -1) a[i] = k;
    	int m = 0;
    	FOR(i, 1, n-1) m = max(m, abs(a[i]-a[i+1]));
    	cout << m << ' ' << k << endl;
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
