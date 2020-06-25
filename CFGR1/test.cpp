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
#include <cstdlib>
#include <ctime>
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

const static int n = 7;

vector<int> op;
set<vector<int>> seen[n];

void bad() {
	for(int x : op) cout << x << ' ';
	cout << endl;
	exit(0);
}

struct v {
	v() {num.resize(n);}
	vector<int> num;
	v operator+(const v& other) {
		v res;
		REP(i, n) res.num[i] = num[i]+other.num[i];
		return res;
	}
	v operator-(const v& other) {
		v res;
		REP(i, n) res.num[i] = num[i]-other.num[i];
		return res;
	}
	void check() {
		REP(i, n) if(abs(num[i]) > 1) bad();
	}
	void print() {
		REP(i, n) cout << num[i] << ' ';
		cout << endl;
	}
};

v cur[n];

void print() {
	FOR(i, 1, n-2) {
    	DEBUG(i);
    	for(auto& v : seen[i]) {
    		for(int x : v) cout << x << ' ';
    		cout << endl;
    	}
    }
    exit(0);
}

void dfs() {
	FOR(i, 1, n-2) {
		v poss = cur[i-1]+cur[i+1]-cur[i];
		if(seen[i].count(poss.num)) continue;
		seen[i].insert(poss.num);
		v old = cur[i];
		cur[i] = poss;
		dfs();
		cur[i] = old;
	}
}

signed main() {
	srand(time(NULL));
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    REP(i, n) {
    	cur[i].num[i] = 1;
    	seen[i].insert(cur[i].num);
    }
    int rep = 0;
    dfs();
    // REP(i, 1e6) {
    // 	int idx = (rand() % (n-2)) +1;
    // 	v poss = cur[idx-1]+cur[idx+1]-cur[idx];
    // 	if(seen[idx].count(poss.num)) {
    // 		--i;
    // 		++rep;
    // 		if(rep == 1e7) print();
    // 		continue;
    // 	}
    // 	rep = 0;
    // 	cur[idx] = poss;
    // 	seen[idx].insert(poss.num);
    // 	// DEBUG(idx);
    // 	// cur[idx].print();
    // }
    print();

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

