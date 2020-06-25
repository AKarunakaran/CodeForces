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

int t, n, a[N], b[N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> n;
    	REP(i, n) cin >> a[i];
    	REP(i, n) cin >> b[i];
    	vector<pii> va, vb;
    	REP(i, n/2) {
    		va.push_back({min(a[i], a[n-1-i]), max(a[i], a[n-1-i])});
    		vb.push_back({min(b[i], b[n-1-i]), max(b[i], b[n-1-i])});

    	}
    	if((n & 1) && a[n/2] != b[n/2]) {
    		cout << "No" << endl;
    		continue;
    	}
    	sort(va.begin(), va.end());
    	sort(vb.begin(), vb.end());
    	int k = va.size();
    	assert(vb.size() == k);
    	bool good = true;
    	REP(i, k) {
    		if(va[i] != vb[i]) {
    			good = false;
    			break;
    		}
    	}
    	cout << (good ? "Yes" : "No") << endl;
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
