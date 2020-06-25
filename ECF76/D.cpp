#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int nINF = 1<<31;

/////////////////////////////////////////////////////////////////////

const int N = 2e5+10;
int t[2 * N];
int n, m, a[N];
pii vh[N];
set<pii> h; // stores monotonic (p, s) pairs
set<pii> hyb; // stores monotonic (s, -p) pairs

void build() {  // build the tree
    REP(i, n) t[i+n] = a[i];
    FORD(i, n-1, 0) t[i] = max(t[i<<1], t[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
    for(t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l&1) res = max(res, t[l++]);
        if(r&1) res = max(res, t[--r]);
    }
    return res;
}

void print(set<pii>& s) {
	for(auto& pr : s) cout << "{" << pr.first << ", " << pr.second << "}, ";
	cout << endl;
}

void filter_heroes() {
	sort(vh, vh+m);
	REP(i, m) {
		if(i && vh[i].first == vh[i-1].first) continue;
		int x = vh[i].first, y = -vh[i].second;
		// print(hyb);
		auto itr = hyb.lower_bound({-y, 0});
		while(itr != hyb.end()) {
			auto to_erase = itr++;
			int ex = to_erase->second, ey = -to_erase->first;
			hyb.erase(to_erase);
			h.erase({ex, ey});
		}
		hyb.insert({-y, x});
		h.insert({x, y});
	}
}

bool poss(int l, int r) {
	int ms = query(l, r+1);
	auto best = h.lower_bound({ms, 0});
	if(best == h.end()) return false;
	int longest = best->second;
	// cout << l << ' ' << r << ' ' << ms << ' ' << longest << endl;
	return longest >= r-l+1;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int t;
    cin >> t;
    while(t--) {
    	h.clear();
    	hyb.clear();
    	cin >> n;
    	REP(i, n) cin >> a[i];
    	cin >> m;
    	REP(i, m) {
    		cin >> vh[i].first >> vh[i].second;
    		vh[i].second *= -1;
    	}
    	filter_heroes();
    	// for(auto pr : h) cout << pr.first << ' ' << pr.second << endl;
    	build();
    	int id = 0, ans = 0;
    	while(id < n) {
    		// DEBUG(id);
    		int l = id-1, r = n-1;
    		while(l < r) {
	    		int mid = (l+r+1)/2;
	    		if(poss(id, mid)) l = mid;
	    		else r = mid-1;
    		}
    		if(l == id-1) {
    			ans = -1;
    			break;
    		}
    		++ans;
    		id = l+1;
    	}
    	cout << ans << endl;
    }

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
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
