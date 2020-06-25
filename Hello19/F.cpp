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
const int N = 1e5+10, K = 7010;
const int S = 110;

void setbit(ll& x, int b) {x |= (1LL << b);}
int getbit(ll& x, int b) {return (x & (1LL << b)) ? 1 : 0;}

struct ms {
	ll mask[S];

	void clear() {memset(mask, 0, sizeof(mask));}

	ms() {clear();}

	void set(int x) {setbit(mask[x/64], x % 64);}

	ms operator+(ms& other) const {
		ms res;
		REP(i, S) res.mask[i] = mask[i] ^ other.mask[i];
		return res;
	}

	ms operator&(ms& other) const {
		ms res;
		REP(i, S) res.mask[i] = mask[i] & other.mask[i];
		return res;
	}

	int count() {
		int s = 0;
		REP(i, S) s += __builtin_popcountll(mask[i]);
		return s;
	}

	int get(int x) {return getbit(mask[x/64], x%64);}

	void print() {
		REP(i, 10) cout << getbit(mask[0], i);
		cout << endl;
	}
};

ms dmask[K], subd[K], a[N];
int n, q;

ms gcd(ms& l, ms& r) {
	ms res;
	FOR(i, 1, 7000) {
		int num = ((l & subd[i]).count() * (r & subd[i]).count()) & 1;
		if(num) res = res + dmask[i];
	}
	return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);

    FOR(i, 1, 7000) for(int j = i; j <= 7000; j += i) subd[i].set(j);
    FOR(i, 1, 7000) {
    	for(int j = 1; j*j <= i; ++j) {
    		if(i % j == 0) {
    			dmask[i].set(j);
    			dmask[i].set(i/j);
    		}
    	}
    }

    cin >> n >> q;
    while(q--) {
    	int k, x, y, z, v;
    	cin >> k;
    	if(k == 1) {
    		cin >> x >> v;
    		a[x].clear();
    		a[x].set(v);

    	} else if(k == 2) {
    		cin >> x >> y >> z;
    		a[x] = a[y]+a[z];
    		// a[x].print();
    	} else if(k == 3) {
    		cin >> x >> y >> z;
    		a[x] = gcd(a[y], a[z]);
    		// a[x].print();
    	} else {
    		cin >> x >> v;
    		// cout << a[x].get(v);
    		// a[x].print();
    	}
    	FOR(i, 1, 4) a[i].print();
		cout << endl;
    }
    cout << endl;

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
