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

int n, r[2], c[2];

void answer(pii p1, pii p2) {
	cout << "! " << p1.first << ' ' << p1.second << ' ' << p2.first << ' ' << p2.second << endl;
	exit(0);
}

int ask(pii tl, pii br) {
	int res;
	cout << "? " << tl.first << ' ' << tl.second << ' ' << br.first << ' ' << br.second << endl;
	cin >> res;
	if(res == -1) exit(0);
	return res;
}

void check_rows() {
	FOR(i, 1, n) {
		int k = ask({1, i}, {n, i});
		if(k & 1) {
			if(r[0]) r[1] = i;
			else r[0] = i;
		}
	}
}

void check_cols() {
	FOR(i, 1, n) {
		int k = ask({i, 1}, {i, n});
		if(k & 1) {
			if(c[0]) c[1] = i;
			else c[0] = i;
		}
	}
}

void check_four() {
	pii p = {c[0], r[0]};
	int k = ask(p, p);
	if(k & 1) answer(p, {c[1], r[1]});
	else answer({c[1], r[0]}, {c[0], r[1]});
}

void bin_rows() {
	int col = c[0];
	int lef = 1, rig = n;
	while(lef < rig) {
		int m = (lef+rig)/2;
		int k = ask({col, 1}, {col, m});
		if(k & 1) rig = m;
		else lef = m+1;
	}
	int row = lef;
	answer({c[0], row}, {c[1], row});
}

void bin_cols() {
	int row = r[0];
	int lef = 1, rig = n;
	while(lef < rig) {
		int m = (lef+rig)/2;
		int k = ask({1, row}, {m, row});
		if(k & 1) rig = m;
		else lef = m+1;
	}
	int col = lef;
	answer({col, r[0]}, {col, r[1]});
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    check_rows();
    check_cols();
    if(r[0] && c[0]) check_four();
    if(!r[0]) bin_rows();
    if(!c[0]) bin_cols();

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

