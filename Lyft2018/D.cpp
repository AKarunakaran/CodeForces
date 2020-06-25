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
#define int long long
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

// Finds constants {u, v} s.t. a*u+b*v = g for g = gcd(a, b)
// Call with egcd(a, b)
pii egcd(int a, int b, pii x = {1, 0}, pii y = {0, 1}) {
	return (b == 0) ? x : egcd(b, a % b, y, {x.first - a/b * y.first, x.second - a/b * y.second});
}

// Finds x s.t. (a*x) % n == 1
// Assumes a is not zero divisor (i.e. gcd(a, n) == 1)
int modInv(int a, int n) {
	return ((egcd(a, n).first % n) + n) % n;
}

const int N = 510, M = 998244353;
const double eps = 1e-7;
int n, a[N], ans = 1;
unordered_map<int, int> m;

int gcd(int x, int y) {return y ? gcd(y, x%y) : x;}
int add(int x, int y) {return (x+y)%M;}
int sub(int x, int y) {return (x-y+M)%M;}
int mult(int x, int y) {return (x*y)%M;}
int divd(int x, int y) {return (x*modInv(y, M))%M;}

void addprime(int p, int idx, int numhave) {
	DEBUG(p);
	DEBUG(numhave);
    DEBUG(a[idx]);
	int numappear = 0;
	if(m.find(p) != m.end()) numappear = m[p];
	else {
		REP(i, idx) {
			int temp = a[i];
			while(temp % p == 0) {
				++numappear;
				temp /= p;
			}
		}
	}
	ans = divd(ans, numappear+1);
	ans = mult(ans, numappear+numhave+1);
	m[p] = numappear+numhave;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> a[i];

    FOR(i, 0, n-1) {
    	// DEBUG(ans);
    	bool primepower = false;
    	int p = 0;
    	FORD(j, 4, 2) {
    		p = pow(a[i], 1/(double)j)+eps;
	    	int prod = 1;
	    	REP(j, i) prod *= p;
	    	if(prod == a[i]) {
	    		primepower = true;
	    		break;
	    	}
    	}
    	if(primepower) {
    		int numhave = 0;
    		int temp = a[i];
    		while(temp % p == 0) {
    			++numhave;
    			temp /= p;
    		}
    		addprime(p, i, numhave);
    	} else {
    		int numappear = 0, p1, p2;
    		bool good = false;
    		FORD(j, i-1, 0) {
    			int g = gcd(a[j], a[i]);
    			if(g == a[i]) {
    				++numappear;
    			}
    			if(g < a[i] && g > 1) {
    				p1 = g;
    				p2 = a[i]/g;
    				good = true;
    				break;
    			}
    		}
    		if(good) {
    			addprime(p1, i, 1);
    			addprime(p2, i, 1);
    		} else {
	    		ans = divd(ans, numappear+1);
	    		ans = divd(ans, numappear+1);
	    		ans = mult(ans, numappear+2);
	    		ans = mult(ans, numappear+2);
    		}
    	}
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
