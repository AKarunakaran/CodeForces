#include <bits/stdc++.h>
using namespace std;
#define int long long
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

int t, n;
map<int, int> m;

pii find_power(int block) {
	if(block == 0) return {0, 0};
	int cur = 1, p = 0, x = 1;
	while(cur <= block) {
		++p;
		x *= 4;
		cur += x;
	}
	cur -= x;
	return {p, block-cur};
}

int find_four_num(int x, int p) {
	if(p == 0) return m[x];
	int layer_size = (1LL << (2*p));
	int block = x/layer_size;
	return m[block]*layer_size + find_four_num(x % layer_size, p-1);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    m[0] = 0;
    m[1] = 2;
    m[2] = 3;
    m[3] = 1;
    cin >> t;
    while(t--) {
    	cin >> n;
    	--n;
    	int block = n/3;
    	int p, num;
    	tie(p, num) = find_power(block);
    	int tp = 2*p;
    	vector<int> cur(3, 0);
    	cur[0] = (1LL << tp)+num;
    	// DEBUG(tp);
    	// DEBUG(num);
    	// DEBUG(cur[0]);
    	cur[1] = (1LL << (tp+1)) + find_four_num(num, p);
    	cur[2] = cur[0] ^ cur[1];
    	cout << cur[n % 3] << endl;
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
