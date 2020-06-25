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
int n, g[3][3];

void answer(string s) {
	cout << s << endl;
	exit(0);
}

void cycle1() {
	if(!g[0][1] && !g[1][2] && !g[2][0]) {
		string s;
		REP(i, n) s += "abc";
		answer(s);
	}
}

void cycle2() {
	if(!g[0][2] && !g[2][1] && !g[1][0]) {
		string s;
		REP(i, n) s += "acb";
		answer(s);
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    string s[2];
    cin >> n >> s[0] >> s[1];
    REP(i, 2) {
    	g[s[i][0]-'a'][s[i][1]-'a'] = 1;
    }
    cout << "YES" << endl;
    cycle1();
    cycle2();
    if(!g[0][1] && !g[1][2]) answer(string(n, 'a') + string(n, 'b') + string(n, 'c'));
    if(!g[1][2] && !g[2][0]) answer(string(n, 'b') + string(n, 'c') + string(n, 'a'));
    if(!g[2][0] && !g[0][1]) answer(string(n, 'c') + string(n, 'a') + string(n, 'b'));
    if(!g[0][2] && !g[2][1]) answer(string(n, 'a') + string(n, 'c') + string(n, 'b'));
    if(!g[2][1] && !g[1][0]) answer(string(n, 'c') + string(n, 'b') + string(n, 'a'));
    if(!g[1][0] && !g[0][2]) answer(string(n, 'b') + string(n, 'a') + string(n, 'c'));

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

