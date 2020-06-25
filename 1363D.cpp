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

const int N = 1e3+10;

int t, n, k, id[N], hi;
vector<int> s[N];

int query(vector<int> v) {
	cout << "? " << v.size() << ' ';
	for(int x : v) cout << x << ' ';
	cout << endl;
	int res;
	cin >> res;
	return res;
}

vector<int> get_vec(int l, int r) {
	vector<int> res;
	FOR(i, l, r) res.push_back(i);
	return res;
}

int find_max_id() {
	int l = 1, r = n;
	while(l < r) {
		int m = (l+r)/2;
		if(query(get_vec(l, m)) != hi) l = m+1;
		else r = m;
	}
	return l;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> n >> k;
    	set<int> all;
    	FOR(i, 1, n) all.insert(i);
    	REP(i, k) {
    		int c;
    		cin >> c;
    		s[i].clear();
    		s[i].resize(c);
			REP(j, c) {
				cin >> s[i][j];
				id[s[i][j]] = i;
			}
    	}
		hi = query(get_vec(1, n));
		int max_id = find_max_id();
		for(int x : s[id[max_id]]) all.erase(x);
		int oth_hi = query(vector<int>(all.begin(), all.end()));
		cout << "! ";
		REP(i, k) cout << (i == id[max_id] ? oth_hi : hi) << ' ';
		cout << endl;
		string response;
		cin >> response;
		if(response == "Incorrect") exit(0);
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
