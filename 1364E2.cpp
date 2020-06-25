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

int n, all[N][N], na, nb;

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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void rec(vector<int>& v) {
	int sz = v.size();
	if(sz == 2) {
		na = v[0], nb = v[1];
		return;
	}
	int a = 0, b = 1, sp = msbp(sz+1)/2;
	while(__builtin_popcount(get(v[a], v[b])) > sp) {
		a = rng() % sz;
		do b = rng() % sz;
		while(a == b);
	}
	int ans = 1 << 12;
	REP(i, sz) {
		if(a == i) continue;
		ans = min(ans, get(v[a], v[i]));
	}
	vector<int> nxt(1, v[a]);
	REP(i, sz) {
		if(a == i) continue;
		if(get(v[a], v[i]) == ans) nxt.push_back(v[i]);
	}
	rec(nxt);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    // extra attempt
    memset(all, -1, sizeof(all));
    cin >> n;
    vector<int> v(n+1);
    iota(v.begin()+1, v.end(), 1);
    v.erase(v.begin());
    rec(v);
    shuffle(v.begin(), v.end(), rng);
    int zid = -1;
    int a = na, b = nb;
    REP(i, n) {
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
