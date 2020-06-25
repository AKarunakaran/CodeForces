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

const int N = 1.5e5+10;
int n, sieve[N];
pii a[N];
vector<int> primes;

void answer(int k) {
	cout << k << endl;
	exit(0);
}

void check(int p) {
	REP(i, n) {
		if(a[i].first % p != 0 && a[i].second % p != 0) return;
	}
	answer(p);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(sieve, -1, sizeof(sieve));
    for(int i = 2; i < N; ++i) {
    	if(sieve[i] == -1) {
    		primes.push_back(i);
    		for(int j = i; j < N; j += i) {
    			sieve[j] = i;
    		}
    	}
    }
    cin >> n;
    REP(i, n) cin >> a[i].first >> a[i].second;
    int l = a[0].first, r = a[0].second;
    set<int> pcheck;
    for(int p : primes) {
    	if(l % p == 0 || r % p == 0) {
    		pcheck.insert(p);
    		while(l % p == 0) {
    			l /= p;
    		}
    		while(r % p == 0) {
    			r /= p;
    		}
    	}
    }
    if(l != 1) pcheck.insert(l);
    if(r != 1) pcheck.insert(r);
    for(int p : pcheck) check(p);
    answer(-1);

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - .size()-k underflow (WA, RTE, TLE)
// - const int N is correct (WA, RTE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
