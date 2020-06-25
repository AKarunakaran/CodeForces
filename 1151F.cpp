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

template <typename T>
struct Matrix {
	int r, c;
	vector<vector<T>> data;
	Matrix(int _r, int _c, T** arr) : r(_r), c(_c) {
		data.resize(_r, vector<T>(_c));
		REP(i, _r) REP(j, _c) data[i][j] = a[i][j];
	}

	Matrix(vector<vector<T>>& _data) : data(_data) {
		r = _data.size(), c = _data[0].size();
	}

	Matrix(int _r, int _c) : r(_r), c(_c) {
		data.resize(_r, vector<T>(_c));
	}

	vector<T>& operator[](int id) {
		return data[id];
	}

	Matrix operator*(Matrix& oth) {
		assert(oth.r == c);
		Matrix res(r, oth.c);
		REP(i, r) REP(j, oth.c) REP(k, c) res[i][j] += data[i][k]*oth[k][j];
		return res;
	}

	Matrix operator*(const T& scale) {
		Matrix res = *this;
		REP(i, r) REP(j, c) res[i][j] *= scale;
		return res;
	}

	Matrix operator+(Matrix& oth) {
		assert(oth.r == r && oth.c == c);
		Matrix res(r, c);
		REP(i, r) REP(j, c) res[i][j] = data[i][j]+oth[i][j];
		return res;
	}

	Matrix operator^(ll power) const {
		assert(r == c);
		Matrix base = *this, res(r, c);
		REP(i, r) res[i][i] = 1;
		while(power) {
			if(power & 1) res = res*base;
			base = base*base;
			power >>= 1;
		}
		return res;
	}
};

int fastPowMod(int base, int power) {
    int res = 1;
    while(power) {
        if(power & 1) res = (res*base) % M;
        base = (base*base) % M;
        power >>= 1;
    }
    return res;
}

struct modNum {
	int x, M;
	modNum(int _M) : M(_M), x(0) {}
	modNum(int _x, int _M) : M(_M), x(_x) {}

	modNum operator+(modNum& oth) {return modNum((x+oth.x)%M, M);}
	void operator+=(modNum& oth) {x = (x+oth.x)%M;}
	modNum operator-(modNum& oth) {return modNum((x+M-oth.x)%M, M);}
	void operator-=(modNum& oth) {x = (x+M-oth.x)%M;}
	modNum operator*(modNum& oth) {return modNum(((ll)x*(ll)oth.x)%M, M);}
	void operator*=(modNum& oth) {x = ((ll)x*(ll)oth.x)%M;}

	modNum operator^(int power) {
		modNum res(1, M);
		while(power) {
			if(power & 1) res *= base;
			base *= base;
			power >>= 1;
		}
		return res;
	}

	modNum(int n, int d, int _M) : M(_M), x(_x) {
		modNum mn(n, _M), md(d, _M);
		return mn*(md^(_M-2));
	}

};

const int N = 110, M = 1e9+7;
int n, k, a[N];

void transform() {
	REP(i, n) a[i] = 1-a[i];
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    int z = 0;
    REP(i, n) z += (a[i] == 0);
    if(z > n/2) {
    	transform();
    	z = n-z;
    }
    vector<vector<modNum>> g(z+1, vector<modNum>(z+1, modNum(M)));
    FOR(i, 0, z) {
    	if(i) {
    		// ones/z + ones/(n-z)
    		int ones = z-i;
    		g[i][i-1] = modNum(ones, z, M)+modNum(ones, n-z, M);
    	}
    	// 
    	g[i][i] = 
    	if(i != z) {
    		//
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

