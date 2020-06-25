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

const int N = 1e6+10, M = 1e9+7;

int add(int a, int b) {return (a+b)%M;}
int sub(int a, int b) {return (a+M-b)%M;}
int mult(ll a, ll b) {return (a*b)%M;}

int n, p, t, k[N];

int fastPowMod(int base, int power) {
    int res = 1;
    while(power) {
        if(power & 1) res = mult(res, base);
        base = mult(base, base);
        power >>= 1;
    }
    return res;
}

void add_to_num(map<int, int>& m, map<int, int>& oth, int e) {
	int id = e;
	++m[id];
	while(m[id] == p) {
		m.erase(id);
		++m[++id];
	}
	if(oth.count(id) && m[id] == oth[id]) {
		m.erase(id);
		oth.erase(id);
	}
}

int conv(map<int, int>& m) {
	int res = 0;
	for(auto [e, c] : m) res = add(res, mult(c, fastPowMod(p, e)));
	return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> n >> p;
    	REP(i, n) cin >> k[i];
    	if(p == 1) {
    		cout << (n & 1) << endl;
    		continue;
    	}
    	sort(k, k+n, greater<int>());
    	map<int, int> a, b;
    	REP(i, n) {
    		// DEBUG(numz);
    		// fill b if strictly smaller, a if equal
    		if(a.empty()) {
    			add_to_num(a, b, k[i]);
    		} else {
    			add_to_num(b, a, k[i]);
    		}
    	}
    	cout << sub(conv(a), conv(b)) << endl;
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
