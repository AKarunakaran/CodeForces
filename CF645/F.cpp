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

void bad() {
	cout << "IMPOSSIBLE" << endl;
	exit(0);
}

const int N = 2e5+10;

int n;
ll a[N], b[N], ob[N];

void answer(string& ops) {
	int num_ops = 0;
	for(char c : ops) if(c == 'P') ++num_ops;
	if(num_ops > 200000) {
		cout << "BIG" << endl << num_ops << endl;
	} else {
		cout << "SMALL" << endl;
		cout << ops.size() << endl << ops << endl;
	}
}

bool increasing() {
	REP(i, n-1) if(b[i] >= b[i+1]) return false;
	return true;
}


bool decreasing() {
	REP(i, n-1) if(b[i] <= b[i+1]) return false;
	return true;
}

bool straight_equal() {
	REP(i, n) if(a[i] != b[i]) return false;
	return true;
}

int equal() {
	if(straight_equal()) return 1;
	reverse(b, b+n);
	bool res = straight_equal();
	reverse(b, b+n);
	if(res) return 2;
	else return 0;
}

void solve() {
	string ops;
	while(!equal()) {
		if(increasing()) {
			FORD(i, n-1, 1) b[i] -= b[i-1];
			ops.push_back('P');
		} else if(decreasing()) {
			reverse(b, b+n);
			ops.push_back('R');
		} else {
			bad();
		}
	}
	if(equal() == 2) {
		ops.push_back('R');
	}
	reverse(ops.begin(), ops.end());
	answer(ops);
}

bool not_good() {
	return (b[0] < a[0] || b[1] < a[1]);
}

bool almost_equal() {
	return (a[0] == b[0] || a[1] == b[1]);
}

bool solve2() {
	ll ops = 0;
	while(!almost_equal()) {
		if(not_good()) {
			return false;
		} else if(increasing()) {
			ops += b[1]/b[0];
			b[1] %= b[0];
		} else if(decreasing()) {
			ops += b[0]/b[1];
			b[0] %= b[1];
		}
	}
	if(not_good()) return false;
	if(a[0] == b[0] && a[1] != b[1]) {
		if((b[1]-a[1]) % a[0] == 0) {
			ops += (b[1]-a[1]) / a[0];
		} else {
			return false;
		}
	} else if(a[1] == b[1] && a[0] != b[0]) {
		if((b[0]-a[0]) % a[1] == 0) {
			ops += (b[0]-a[0]) / a[1];
		} else {
			return false;
		}
	}
	if(ops > 200000) {
		cout << "BIG\n" << ops << endl;
	} else {
		REP(i, n) b[i] = ob[i];
		solve();
	}
	return true;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) {
    	cin >> b[i];
    	ob[i] = b[i];
    }
    if(n == 1) {
    	if(a[0] == b[0]) {
    		cout << "SMALL\n0\n";
    	} else {
    		bad();
    	}
    } else if(n == 2) {
    	if(!solve2()) {
	    	b[0] = ob[1], b[1] = ob[0];
	    	if(!solve2()) bad();
    	}
    } else {
    	solve();
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
