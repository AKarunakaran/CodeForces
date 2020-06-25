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
using namespace std; 
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

const int N = 1e7;
int n;
vector<int> sieve(N+1, 0), usedsieve(N+1, 0), ans, a, primes;

void useNumber(int k) {
	if(usedsieve[k]) return;
	for(int i = k; i <= N; i += k) usedsieve[i] = 1;
}

set<int> factorize(int x) {
	set<int> pf;
	int cur = x;
	while(cur != 1) {
		pf.insert(sieve[cur]);
		cur /= sieve[cur];
	}
	return pf;
}

void fillMin(int idx, int mx) {
	int pidx = 0;
	FOR(i, idx, n-1) {
		while(usedsieve[primes[pidx]]) {
			++pidx;
		}
		ans[i] = primes[pidx++];
	}
}

void answer(int idx) {
	FOR(i, a[idx], N) {
		if(!usedsieve[i]) {
			set<int> pf = factorize(i);
			for(int p : pf) useNumber(p);
			ans[idx] = i;
			fillMin(idx+1, i);
			for(int k : ans) cout << k << ' ';
			cout << endl;
			exit(0);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    for(int i = 2; i <= N; ++i) {
    	if(sieve[i] == 0) {
    		primes.push_back(i);
    		for(int j = i; j <= N; j += i) {
    			if(sieve[j] == 0) sieve[j] = i;
    		}
    	}
    }
    cin >> n;
    a.resize(n);
    REP(i, n) cin >> a[i];
    ans = a;
    REP(i, n) {
    	set<int> pf = factorize(a[i]);
    	for(int p : pf) {
    		if(usedsieve[p]) {
    			answer(i);
    		}
    	}
    	for(int p : pf) useNumber(p);
    }
	REP(i, n) cout << a[i] << ' ';
	cout << endl;

    return 0;
}