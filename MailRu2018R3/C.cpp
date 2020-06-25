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

const int N = 2010;
int n, k, p[N], t, good[N];
map<int, int> m;
set<pii> have, prs;

void makemove(int x) {
	cout << x << endl;
	have.erase({-p[x], x});
	good[x] = false;
	if(m.find(x) != m.end()) {
		prs.erase({m[x], x});
		prs.erase({x, m[x]});
	}
}

void mademove(int x) {
	have.erase({-p[x], x});
	good[x] = false;
	if(m.find(x) != m.end()) {
		prs.erase({m[x], x});
		prs.erase({x, m[x]});
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    fill(good+1, good+1+2*n, 1);
    FOR(i, 1, 2*n) cin >> p[i];
    FOR(i, 1, 2*n) have.insert({-p[i], i});
    REP(_, k) {
    	int a, b;
    	cin >> a >> b;
    	m[a] = b;
    	m[b] = a;
    	prs.insert({a, b});
    }
    cin >> t;
    int turn = 1, forcedmove;
    bool forced = false;
    while(have.size()) {
    	if(turn == t) {
    		int mine;
    		if(forced) {
    			mine = forcedmove;
    			forced = false;
    		} else if(prs.size()) {
    			int a = prs.begin()->first, b = prs.begin()->second;
    			mine = p[a] > p[b] ? a : b;
    		} else {
    			mine = have.begin()->second;
    		}
			makemove(mine);
    	} else {
    		int move;
    		cin >> move;
    		mademove(move);

    		if(m.find(move) != m.end()) {
    			if(good[m[move]]) {
    				forced = true;
    				forcedmove = m[move];
    			}
    		}
    	}
    	turn = (turn == 1) ? 2 : 1;
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
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
