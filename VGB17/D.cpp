#include <iostream>
#include <iomanip>
#include <sstream>
#include <ostream>
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
const ll M = 1000000007;

/////////////////////////////////////////////////////////////////////

pll egcd(ll a, ll b, pll x = {1, 0}, pll y = {0, 1}) {
	return (b == 1) ? y : egcd(b, a%b, y, {x.first-a/b*y.first, x.second-a/b*y.second});
}

ll modInv(ll a, ll n) {
	return ((egcd(a, n).first % n) + n) % n;
}

ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

void simp(ll& n, ll& d) {
	ll g = gcd(n, d);
	n /= g;
	d /= g;
}


struct frac {
	ll n, d;
	frac operator+(const frac &oth) {
		frac res((n*oth.d+d*oth.n) % M, (d*oth.d) % M);
		return res;
	}
	frac operator*(const frac &oth) {
		frac res((n*oth.n) % M, (d*oth.d) % M);
		return res;
	}
	frac& operator=(const frac &oth) {
		n = oth.n;
		d = oth.d;
		return *this;
	}
	frac() {
		n = 0;
		d = 1;
	}
	frac(ll a, ll b) {
		simp(a, b);
		n = a;
		d = b;
	}
	frac(const frac &oth) {
		*this = oth;
	}
};

void print(frac f) {
	cout << f.n << '/' << f.d << endl;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll k, a, b;
    cin >> k >> a >> b;
    vector<vector<frac>> dp(k+1, vector<frac>(k+1));
    frac rat{a, b}, pa{a, a+b}, pb{b, a+b};
    FOR(i, 0, k) {
    	FOR(j, 0, k) {
    		if(i + j >= k) {
    			frac s{i+j, 1};
    			dp[i][j] = s + rat;
    		}
    	}
    }
    FORD(i, k, 0) {
    	FORD(j, k-i-1, 0) {
    		dp[i][j] = (pa*dp[i+1][j])+(pb*dp[i][i+j]);
    	}
    }
    dp[0][0] = dp[1][0];
    ll p = dp[0][0].n;
    ll q = modInv(dp[0][0].d, M);
    cout << (p*q) % M << endl;

    return 0;
}