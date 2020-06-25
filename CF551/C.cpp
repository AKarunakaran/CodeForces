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

string s;

void bad() {
	cout << ":(" << endl;
	exit(0);
}

void check_good(int l, int r) {
	int bal = 0;
	FOR(i, l, r) {
		if(s[i] == '(') ++bal;
		else --bal;
		if(bal < 0) bad();
	}
	if(bal) bad();
}

void make_good(int l, int r) {
	int bal = 0, q = 0;
	FOR(i, l, r) {
		if(s[i] == '(') ++bal;
		if(s[i] == ')') --bal;
		if(s[i] == '?') ++q;
	}
	// DEBUG(bal);
	// DEBUG(q);
	FOR(i, l, r) {
		if(s[i] == '?') {
			if(bal == q) {
				s[i] = ')';
				--bal, --q;
			} else {
				s[i] = '(';
				++bal, --q;
			}
		}
		// DEBUG(s);
	}
	check_good(l, r);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n >> s;
    if(s[0] == '?') s[0] = '(';
    if(s[n-1] == '?') s[n-1] = ')';
	// DEBUG(s);
	make_good(1, n-2);
	check_good(0, n-1);
	cout << s << endl;

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

