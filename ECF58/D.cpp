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

bool notone = false;

struct hi2 {
	int hi, lo;
	hi2() : hi(0), lo(0) {}
	void add(int x) {
		if(x > hi) {
			lo = hi;
			hi = x;
		} else if(x > lo) lo = x;
	}
	int count() {return lo+hi;}
};

const int N = 2e5+10;
int n, a[N], sieve[N], ans;
vector<int> g[N];

vector<pii> dfs(int s, int p = 0) {
	unordered_map<int, int> resmap;
	unordered_map<int, hi2> ppc;
	for(int v : g[s]) {
		if(v != p) {
			vector<pii> cur = dfs(v, s);
			for(pii& pr : cur) {
				if(a[s] % pr.first != 0) continue;
				hi2& curh2 = ppc[pr.first];
				curh2.add(pr.second);
				ans = max(ans, 1+curh2.count());
				resmap[pr.first] = curh2.hi+1;
			}
		}
	}
	set<int> primes;
	int curn = a[s];
	while(curn != 1) {
		primes.insert(sieve[curn]);
		curn /= sieve[curn];
	}
	for(int x : primes) {
		if(resmap.find(x) == resmap.end()) {
			resmap[x] = 1;
			ans = max(ans, 1);
		}
	}
	vector<pii> res;
	for(auto& pr : resmap) res.push_back(pr);
	return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    for(int i = 2; i <= 2e5; ++i) {
    	if(sieve[i]) continue;
    	for(int j = i; j <= 2e5; j += i) sieve[j] = i;
    }
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		// if(a[i] != 1) notone = true;
	}
	REP(i, n-1) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	// if(!notone) {
	// 	cout << 0 << endl;
	// 	exit(0);
	// }
	dfs(1);
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
