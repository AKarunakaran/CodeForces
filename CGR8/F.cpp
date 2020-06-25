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

int n, a[N], ans, on;

int get_id(int x) {
	x = ((x % n) + n) % n;
	if(x == 0) x += n;
	return x;
}

void query(vector<int>& v) {
	int k = v.size();
	cout << k << ' ';
	for(int x : v) {
		if(a[x] == 0) {
			++on;
			a[x] = 1;
		}
		cout << x << ' ';
	}
	cout << endl;
	int l;
	cin >> l;
	if(l == -1) exit(0);
	for(int i = 0; i < k; ++i, l = get_id(l+1)) {
		if(a[l] == 1) {
			--on;
			a[l] = 0;
		}
	}
}

void perform(int id, int len) {
	// [id, id+len-1] is our light window, we light up everything else and skip 1st, 3rd, and last
	vector<int> q;
	int l = id, r = get_id(id+len-1);
	// cout << "performing " << id << ' ' << len << " [" << l << ", " << r << "]" << endl;
	id = get_id(r+1);
	set<int> bad;
	bad.insert(get_id(r+1));
	bad.insert(get_id(r+3));
	bad.insert(get_id(l-1));
	while(id != l) {
		if(!bad.count(id)) q.push_back(id);
		id = get_id(id+1);
	}
	query(q);
}

void print() {
	cout << on << endl;
	FOR(i, 1, n) cout << a[i] << ' ';
	cout << endl;
}

int gap(int l, int r) {
	if(l > r) {
		return n-2-gap(r, l);
	} else {
		return r-l-1;
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    ans = (n/2)-1;
    // DEBUG(ans);
    vector<int> first;
    first.push_back(1);
    FOR(i, 3, n-1) first.push_back(i);
    query(first);
    while(on < ans) {
    	// print();
    	// int len = 2*on-1;
    	vector<int> cur;
    	FOR(i, 1, n) if(a[i]) cur.push_back(i);
    	// pick tightest window
    	int k = cur.size();
	    int best = -1, best_gap = -1;
    	if(k > 1) {
	    	REP(i, k) {
	    		// cout << cur[i] << ' ';
	    		int pre = (i+k-1)%k;
	    		if(gap(cur[pre], cur[i]) > best_gap) {
	    			best = cur[i];
	    			best_gap = gap(cur[pre], cur[i]);
	    		}
	    	}
    	} else {
    		best = cur[0], best_gap = n-1;
    	}
    	perform(best, n-best_gap);
    }
    // print();
    cout << 0 << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE) CHECK IF IT SHOULD BE 2*N!!!!
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - negative arithmetic, ceiling division, modulo (WA)
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
