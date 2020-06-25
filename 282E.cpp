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

struct Trie {
	Trie *bit[2];
};
Trie head;

void insert(ll num) {
	ll mask = 1LL << 45;
	Trie* itr = &head;
	REP(_, 46) {
		int b = (num & mask) ? 1 : 0;
		if(itr->bit[b] == nullptr) itr->bit[b] = new Trie{{0, 0}};
		itr = itr->bit[b];
		mask >>= 1;
	}
}

ll findhixor(ll num) {
	ll mask = 1LL << 45, res = 0;
	Trie* itr = &head;
	REP(_, 46) {
		int b = (num & mask) ? 1 : 0, nb = (num & mask) ? 0 : 1;
		int cb = itr->bit[nb] ? nb : b;
		if(cb) res |= mask;
		itr = itr->bit[cb];
		mask >>= 1;
	}
	return res;
}

const int N = 1e5+10;
int n;
ll a[N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> a[i];
    a[n] = 0;

    ll s = 0, bs = 0, ans = 0;
    REP(i, n) bs ^= a[i];
    insert(0);
    FOR(i, 0, n) {
    	ans = max(ans, bs ^ findhixor(bs));
    	s ^= a[i];
    	bs ^= a[i];
    	insert(s);
    }
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
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
