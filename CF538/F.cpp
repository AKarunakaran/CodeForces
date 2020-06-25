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

int np = 62;
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163 ,167,
  173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271,
   277, 281, 283, 293};

map<int, int> pid;

const int N = 4e5+10;
int n, q, a[N], bit[np][N];

map<int, int> factorize(int x) {
	map<int, int> res;
	int nx = x;
	for(int i = 2; i*i <= nx; ++i) {
		while(x % i == 0) {
			x /= i;
			++res[i];
		}
	}
	return res;
}

void mult(int l, int r, int x) {
	map<int, int> pf = factorize(x);
	for(auto& pr : pf) {
		int p = pr.first, num = pr.second;
		update(pid[p], i, num);
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    REP(i, np) pid[primes[i]] = i;
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) {
    	map<int, int> pf = factorize(a[i]);
    	for(auto& pr : pf) {
    		int p = pr.first, num = pr.second;
    		update(pid[p], i, num);
    	}
    }

    while(q--) {
    	string op;
    	int l, r, x;
    	cin >> op >> l >> r;
    	if(op == "MULTIPLY") {
    		cin >> x;
    		mult(l, r, x);
    	} else {
    		cout << totient(l, r) << endl;
    	}
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
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)

