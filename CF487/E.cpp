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
#include <array>
#include <functional>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i, a, b) for(int i = a; i <(b); ++i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int MAXN = 201;
int n, q;
pii p[MAXN];

template <class T, int N> struct Matrix {
	typedef Matrix M;
	array<array<T, N>, N> d{};
	M operator*(const M& m) const {
		M a;
		rep(i,0,N) rep(j,0,N)
			rep(k,0,N) a.d[i][j] += d[i][k]*m.d[k][j];
		return a;
	}
	vector<T> operator*(const vector<T>& vec) const {
		vector<T> ret(N);
		rep(i,0,N) rep(j,0,N) ret[i] += d[i][j] * vec[j];
		return ret;
	}
	M operator^(ll p) const {
		assert(p >= 0);
		M a, b(*this);
		rep(i,0,N) a.d[i][i] = 1;
		while (p) {
			if (p&1) a = a*b;
			b = b*b;
			p >>= 1;
		}
		return a;
	}
};

struct slope {
	double s;
	bool inf;
	slope(int a, int b) {
		if(b == 0) inf = true;
		else {
			s = a/(double)b;
		}
	}
	bool operator==(const slope& other) const {
		if(inf && other.inf) return true;
		if(!inf && !other.inf && EQ(s, other.s)) return true;
		return false;
	}
	bool operator<(const slope& other) const {
		if(inf && other.inf) return false;
		if(inf && !other.inf) return false;
		if(!inf && other.inf) return true;
		return s < other.s;
	}
	bool operator<=(const slope& other) const {
		return *this < other || *this == other;
	}
	bool operator>(const slope& other) const {
		return !(*this <= other);
	}
	bool operator>=(const slope& other) const {
		return *this > other || *this == other;
	}
};

Matrix<double, MAXN> mat;

void fillprob(int k) {
	map<slope, int> m;
	FOR(i, 1, n) {
		if(i == k) continue;
		int a = p[i].first-p[k].first;
		int b = p[i].second-p[k].second;
		slope sl(b, a);
		m[sl]++;
	}
	FOR(i, 1, n) {
		if(i == k) continue;
		int a = p[i].first-p[k].first;
		int b = p[i].second-p[k].second;
		slope sl(b, a);
		mat.d[k][i] = 1/(double)(m[sl]+1);
		// DEBUG(1/(double)(m[sl]+1));
	}
}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(7);
    cin >> n;
    FOR(i, 1, n) cin >> p[i].first >> p[i].second;
    FOR(i ,1, n) {
    	fillprob(i);
    }
    cin >> q;
    while(q--) {
    	int t, m;
    	cin >> t >> m;
    	Matrix<double, MAXN> cur = mat^m;
    	double res = 0;
    	FOR(i, 1, n) {
    		FOR(j, 1, n) {
    			res = max(res, cur.d[i][j]);
    		}
    	}
    	cout << res << endl;
    }

    return 0;
}