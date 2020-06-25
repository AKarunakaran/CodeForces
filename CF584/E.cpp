#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 12, M = 2000;
int t, n, m, a[N][M], iid, ans;
pair<int, int> id[N*M];
set<int> s;

void update(vector<int>& v) {
	vector<int> cols;
	for(int c : s) cols.push_back(c);
	int cur = 0;
	REP(r, n) {
		int curm = 0;
		REP(i, cols.size()) curm = max(curm, a[(r+v[i]) % n][cols[i]]);
		cur += curm;
	}
	ans = max(ans, cur);
}

void rec(int k, vector<int>& offsets) {
	if(k == offsets.size()) {
		update(offsets);
		return;
	}
	REP(i, n) {
		offsets[k] = i;
		rec(k+1, offsets);
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	iid = 0;
    	cin >> n >> m;
    	REP(i, n) {
    		REP(j, m) {
    			cin >> a[i][j];
    			id[iid++] = {-a[i][j], j};
    		}
    	}
    	sort(id, id+n*m);
    	ans = 0;
    	
		// DEBUG("here1");
		s.clear();
		// DEBUG("here2");
		REP(i, n) s.insert(id[i].second);
		// DEBUG("here3");
		// DEBUG("here5");
		REP(i, min(2*n, n*m)) s.insert(id[i].second);
		if(s.size() >= 6) {
			REP(i, n) ans -= id[i].first;
		} else {
			vector<int> v(s.size(), 0);
			rec(0, v);
		}
    	cout << ans << endl;
    }
    // DEBUG("here");

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

