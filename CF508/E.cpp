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
// const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 100;
int n, c[5];
unordered_map<vector<int>, int> m;
vector<int> vals[6];
vector<int> cnt(6, 0);

int getidx(int l, int r) {
	if(l == 1) {
		return r-2;
	} else if(l == 2) {
		return r;
	} else return 5;
}

int rec(int mask, int color) {
	if(m.find(cnt) != m.end()) return score+m[cnt];
	int best = 0;
	if(color == 0) {
		if(cnt[0]) {
			cnt[0]--;
			best = max(best, vals[0][cnt[0]-1]+rec(mask | (1 << 1), 1));
			cnt[0]++;
		}
		if(cnt[1]) {
			cnt[1]--;
			best = max(best, vals[1][cnt[1]-1]+rec(mask | (1 << 2), 2));
			cnt[1]++;
		}
		if(cnt[2]) {
			cnt[2]--;
			best = max(best, vals[2][cnt[2]-1]+rec(mask | (1 << 3), 3));
			cnt[2]++;
		}
	} else if(color == 1) {
		//
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) {
    	int l, r, v;
    	cin >> l >> v >> r;
    	int nl = min(l, r), nr = max(l, r);
    	l = nl, r = nr;
    	if(l == r) c[l] += v;
    	else {
    		vals[getidx(l, r)].push_back(v);
    		cnt[getidx(l, r)]++;
    	}
    }
    REP(i, 6) sort(vals[i].begin(), vals[i].end());
    int ans = 0;
    ans = max(ans, rec(1 << 0, 0));
    ans = max(ans, rec(1 << 1, 1));
    ans = max(ans, rec(1 << 2, 2));
    ans = max(ans, rec(1 << 3, 3));
    cout << ans << endl;

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
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
