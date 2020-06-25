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

const int N = 3e3+10;

int n, all[N][N];

int query(int i, int j) {
	int x;
	cout << "? " << i << ' ' << j << endl;
	cin >> x;
	return x;
}

int get(int i, int j) {
	return all[i][j] == -1 ? all[i][j] = all[j][i] = query(i, j) : all[i][j];
}

int answer(int zid) {
	vector<int> ans(n+1);
	FOR(i, 1, n) {
		if(i == zid) continue;
		ans[i] = get(i, zid);
	}
	cout << "! ";
	FOR(i, 1, n) cout << ans[i] << ' ';
	cout << endl;
	exit(0);
}

void update(int& a, int& b, int c, int& cur) {
	int nxt = get(b, c);
	if(cur > nxt) {
		// a is bad
		a = c;
		cur = nxt;
	} else if(cur < nxt) {
		// c is bad
	} else {
		// b is bad
		b = c;
		cur = get(a, b);
	}
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(all, -1, sizeof(all));
    cin >> n;
    vector<int> v(n+1);
    iota(v.begin()+1, v.end(), 1);
    shuffle(v.begin()+1, v.end(), rng);
    int a = v[1], b = v[2];
    int cur = get(a, b);
    FOR(i, 3, n) update(a, b, v[i], cur);
    shuffle(v.begin()+1, v.end(), rng);
    int zid = -1;
    FOR(i, 1, n) {
    	int id = v[i];
    	if(id == a || id == b) continue;
    	if(get(a, id) < get(b, id)) {
    		zid = a;
    		break;
    	} else if(get(a, id) > get(b, id)) {
    		zid = b;
    		break;
    	}
    }
    answer(zid);

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
