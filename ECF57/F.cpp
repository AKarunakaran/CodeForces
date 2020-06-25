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

// Finds constants {u, v} s.t. a*u+b*v = g for g = gcd(a, b)
// Call with egcd(a, b)
pll egcd(ll a, ll b, pll x = {1, 0}, pll y = {0, 1}) {
	return (b == 0) ? x : egcd(b, a % b, y, {x.first - a/b * y.first, x.second - a/b * y.second});
}

// Finds x s.t. (a*x) % n == 1
// Assumes a is not zero divisor (i.e. gcd(a, n) == 1)
ll modInv(ll a, ll n) {
	return ((egcd(a, n).first % n) + n) % n;
}

const ll M = 998244353;

ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
ll mult(ll a, ll b) {return (a*b) % M;}
ll add(ll a, ll b) {return (a+b) % M;}

struct frac {
	ll n, d;

	void simp() {
		ll g = gcd(n, d);
		n /= g;
		d /= g;
	}

	frac(ll in_n, ll in_d) {
		n = in_n, d = in_d;
		simp();
	}

	frac operator+(frac& oth) {
		frac ret(n*oth.d+d*oth.n, d*oth.d);
		ret.simp();
		return ret;
	}
};

const int N = 2e5+10;
int n, p[N], m = 0, l[N], have[N];
ll bit[N];

ll getSum(int i) {
    ll sum = 0;
    ++i;
    while(i > 0) {
        sum += bit[i];
        i -= i & (-i);
    }
    return sum;
}
 

//assumes global n, ADDS val to i
void updateBIT(int i, ll val) {
    ++i;
    while(i <= n+5) {
       bit[i] += val;
       i += i & (-i);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) {
    	cin >> p[i];
    	if(p[i] != -1) have[p[i]] = 1;
    	else ++m;
    }
    FOR(i, 1, n) {
    	l[i] = l[i-1];
    	if(!have[i]) ++l[i];
    }
    ll k = 0; //-1 up to id
    frac einv(0, 1);
    frac lm(0, 1);
    ll lmi = 0;
    ll inv = 0;
    ll ans = 0;
    REP(i, n) {
    	int x = p[i];
    	if(x != -1) {
    		// # of created inversions
    		int above = getSum(n)-getSum(x);
    		// cout << n << ' ' << x << endl;
    		// cout << getSum(n) << ' ' << getSum(x) << endl;
    		// DEBUG(above);
    		inv += above;
            ans = add(ans, above);
    		updateBIT(x, 1);
    		// FOR(j, 0, n+1) cout << bit[j] << ' ';
    		// cout << endl;	

	    	// # of expected inversions created
    		if(m) {
	    		frac ex((m-l[x])*k, m);
	    		frac cex(l[x], m);
	    		einv = einv + ex;
	    		lm = lm + cex;
                lmi = add(lmi, mult(cex.n, modInv(cex.d, M)));
                ans = add(ans, mult(ex.n, modInv(ex.d, M)));
    		}
    	} else {
    		// # of expected inversions from positive elements
    		einv = einv+lm;
            ans = add(ans, lmi);

    		// # of expected inversions from -1's
    		frac ex(k, 2);
    		einv = einv+ex;
            ans = add(ans, mult(ex.n, modInv(ex.d, M)));

    		++k;
    	}
    }
    frac kinv(inv, 1);
    // frac ans = kinv+einv;
    // ans.n %= M;
    // ans.d %= M;
    // cout << mult(ans.n, modInv(ans.d, M)) << endl;
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
