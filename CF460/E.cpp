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

const ll P = 100004;

ll ps[P], ex[P], order = INF;

ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}

ll lcm(ll a, ll b) {
	a /= gcd(a, b);
	return a*b;
}

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

ll find(ll a, ll n, ll b, ll p, ll x) {
	// DEBUG(b);
	ll pw = ex[b];
	if(pw == INF || (gcd(order, p) != 1 && pw != n)) return 0;
	ll l = ((n-pw)+p)%p;
	l = (l*(modInv(order, p)))%p;
	ll lc = lcm(p, order);
	ll fi = pw+order*l;
	// DEBUG(pw);
	// DEBUG(lc);
	// DEBUG(fi);
	return ((x-fi)+1 + (lc-1))/lc;
}

ll solve(ll a, ll b, ll p, ll x) {
	ll ans = 0;
	ps[0] = 1;
    FOR(i, 1, p-1) {
    	ex[i] = INF;
    }
    FOR(i, 1, p-1) {
    	ps[i] = (ps[i-1]*a) % p;
    	ex[ps[i]] = min(ex[ps[i]], (ll)i);
    	if(ps[i] == 1) order = min(order, (ll)i);
    	// DEBUG(ps[i]);
    }
    FOR(i, 1, p-1) {
    	ll inv = modInv(i, p);
    	ll rhs = (b*inv) % p;
    	// DEBUG(i);
    	ll cur = find(a, i, rhs, p, x);
    	// DEBUG(cur);
    	ans += cur;
    }
    return ans;
}

ll brute(ll a, ll b, ll p, ll x) {
	ll ans = 0, pw = 1;
	b %= p;
	FOR(n, 1, x) {
		pw = (pw*a) % p;
		if((pw*n) % p == b) {
			++ans;
		}
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll c, d, p, x;
    cin >> c >> d >> p >> x;
    FOR(a, 1, p-1) {
    	FOR(b, 1, p-1) {
    		ll ans = brute(a, b, p, x), myAns = solve(a, b, p, x);
    		if(ans != myAns) cout << a << ' ' << b << ' ' << ans << ' ' << myAns << endl;
    	}
    }

    return 0;
}