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
// #define DEBUG(x) cout << '>' << #x << ':' << x << endl;
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
const int N = 1e5+10;
int n, k, A, B, a[N];

struct trie {
	int sum;
	trie* bit[2];
} head;

void insert(int num) {
	// DEBUG(num);
	++head.sum;
	auto itr = &head;
	FORD(i, n-1, 0) {
		int b = ((1 << i) & num) ? 1 : 0;
		// cout << i << ' ' << b << ' ' << itr << endl;
		if(!itr->bit[b]) itr->bit[b] = new trie{0, {0, 0}};
		itr = itr->bit[b];
		++itr->sum;
	}
}

ll rec(trie* itr, ll l) {
	// DEBUG(l);
	if(itr->sum == 0) return A;
	if(l == 1) return l*B*itr->sum;
	REP(i, 2) if(!itr->bit[i]) itr->bit[i] = new trie{0, {0, 0}};
	return min(l*B*itr->sum, rec(itr->bit[0], l >> 1)+rec(itr->bit[1], l >> 1));
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k >> A >> B;
    REP(i, k) cin >> a[i];
    REP(i, k) insert(a[i]-1);
    cout << rec(&head, 1 << n) << endl;

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

