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
inline bool EQ(long double a, long double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;
const long double eps = 1e-9;

/////////////////////////////////////////////////////////////////////

const int N = 2e5+10;
int n, k;
pll a[N];
ll l = 1, r = 1;

void checkbad() {
	int run_out_at[N];
	REP(i, n) ++run_out_at[a[i].first/a[i].second + 1]; //might change.. 0 is allowed
	int s = 0;
	FOR(i, 1, k) {
		s += run_out_at[i];
		if(s > i) {
			cout << -1 << endl;
			exit(0);
		}
	}
}

void print(set<pair<long double, int>>& ms) {
	for(auto& p : ms) {
		cout << p.first*a[p.second].second << ' ' << p.second << "  ";
	}
	cout << endl;
}

bool check(ll x) {
	// DEBUG(x);
	ull have[N], c[N];
	REP(i, n) {
		have[i] = a[i].first;
		c[i] = a[i].second;
	}
	set<pair<long double, int>> ms;
	REP(i, n) {
		ms.insert({have[i]/(long double)c[i], i});
	}
	REP(i, k) {
		int cur = ms.begin()->second;
		// print(ms);
		// cout << "havecur " << have[cur]-c[cur]*i << ' ' << i << endl;
		if(have[cur] < c[cur]*i) return false;
		have[cur] += x;
		ms.erase(ms.begin());
		ms.insert({have[cur]/((long double)c[cur]), cur});
	}
	return true;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    REP(i, n) cin >> a[i].first;
    REP(i, n) cin >> a[i].second;
    REP(i, n) r = max(r, a[i].second);
    r *= n;
    r = 1e12;
    checkbad();
    while(l < r) {
    	// cout << l << ' ' << r << endl;
    	ll m = (l+r)/2;
    	if(check(m)) r = m;
    	else l = m+1;
    }
    cout << l << endl;

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

