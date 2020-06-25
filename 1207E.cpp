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
#include <ctime>
#include <cstdlib>
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

const int N = 1 << 14;
set<int> s;
unordered_set<int> banned, pxs;
vector<int> xs;

int get_rand() {return rand() % N;}

void query() {
	cout << "? ";
    for(int x : s) cout << x << ' ';
    cout << endl;
}

void answer(int x) {
	cout << "! " << x << endl;
	exit(0);
}

void print() {
	for(int x : s) cout << x << ' ';
	cout << endl;
}

signed main() {
	srand(time(NULL));
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    while(s.size() < 100) {
	    int x = get_rand();
	    while(s.find(x) != s.end()) x = get_rand();
	    s.insert(x);
    }
    query();
    
	int f;
	cin >> f;
	for(int x : s) {
		xs.push_back(x ^ f);
		pxs.insert(x ^ f);
	}
	s.clear();

	REP(i, 100) FOR(j, i+1, 99) banned.insert(xs[i]^xs[j]);

	while(s.size() < 100) {
		int x = get_rand();
		if(s.find(x) != s.end()) continue;
		bool good = true;
		for(int y : s) {
			if(banned.find(x ^ y) != banned.end()) {
				good = false;
				break;
			}
		}
		if(good) {
			DEBUG(x);
			s.insert(x);
			print();
		}
	}

	query();

	cin >> f;
	for(int x : s) {
		if(pxs.find(x ^ f) != pxs.end()) {
			answer(x ^ f);
		}
	}
	cout << "! 0" << endl; // Should not execute

	

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

