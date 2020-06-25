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
#include <cstdlib>
#include <ctime>
#include <unordered_set>
using namespace std;
// #define int long long
// #define DEBUG(x) cout << '>' << #x << ':' << x << endl;
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

const int N = 5e5+10;
ll n, s = 0, a[N], b[N], tlo, thi, par, ds[N], ps[N];
ll sup[N], nup[N]; //sum of degrees for degrees up to i, and number of vertices for degrees up to i (inclusive)

bool check(int d) {
	// DEBUG(d);
	ll ds = d;
	bool added = 0;
	FOR(i, 1, n) {
		ds += a[i];
		if(!added && d > a[i]) {
			added = 1;
			b[i] = d;
		}
		b[i+added] = a[i];
	}
	if(!added) b[n+1] = d;
	// FOR(i, 1, n+1) cout << b[i] << ' ';
	// cout << endl;
	DEBUG(ds);

	ps[n+2] = 0;
	FORD(i, n+1, 0) ps[i] = ps[i+1]+b[i];

	reverse(b+1, b+n+1+1);


	b[n+2] = -1;
	int last = 1, lastd = -1;
	FOR(i, 1, n+1) {
		if(b[i] != b[i+1]) {
			int val = b[i], num = i-last+1;
			FOR(j, lastd+1, val-1) {
				if(lastd != -1) nup[j] = nup[lastd];
				else nup[j] = 0;
			}
			nup[val] = (lastd != -1 ? nup[lastd] : 0) + num;
			lastd = val;
			last = i+1;
		}
	}
	FOR(j, lastd+1, n+1) nup[j] = nup[j-1];
	FOR(i, 1, n+1) sup[i] = sup[i-1]+i*(nup[i]-nup[i-1]);

	// FOR(i, 0, n+1) cout << nup[i] << ' ';
	// cout << endl;

	// FOR(i, 0, n+1) cout << sup[i] << ' ';
	// cout << endl;

	reverse(b+1, b+n+1+1);

	ll ub = 0, dps = 0;
	FOR(i, 1, n) {
		ll k = i;
		ll ts = n+1-k; // Tail size
		ll numgk, sumlk; // Number of degrees on tail end greater than k, and sum of degrees on tail end that are less than or equal to k

		if(b[k+1] > k) {
			// If highest member of tail is greater than k, take sum up to k and numgk is tail size minus number up to k
			numgk = ts-nup[k];
			sumlk = sup[k];
		} else {
			// If highest member of tail is <= k, then numgk is 0 but sumlk is just the suffix sum up to k+1
			numgk = 0;
			sumlk = ps[k+1];
		}

		dps += b[k];
		ub = k*(k-1) + sumlk + k*numgk; // k(k-1) + sum of degrees less than or equal to k + k(number of degrees greater than k)
		// cout << k << ' ' << dps << ' ' << ub << endl;
		if(dps > ub) return false;
	}
	dps += b[n+1];
	return dps <= n*(n+1);
}

signed main() {
	srand(time(NULL));
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    FOR(i, 1, n) {
    	cin >> a[i];
    	s += a[i];
    }
    sort(a+1, a+1+n, greater<int>());
    par = s & 1;


    int work = -1;

    REP(r, 100) {
    	int t = rand() % (n/2+1);
    	if(check(2*t+par)) {
    		work = t;
    		break;
    	}
    }
    if(work == -1) {
    	cout << -1 << endl;
    	exit(0);
    }

    // Find lowest valid
    int lo = 0, hi = work;
    while(lo <= hi) {
    	int mid = (lo+hi)/2;
    	int deg = 2*mid+par;
    	if(check(deg)) {
    		if(lo == hi) break;
    		hi = mid;
    	} else lo = mid+1;
    }
    tlo = 2*lo+par;

    // Find highest valid
    lo = work, hi = n/2;
    while(lo <= hi) {
    	int mid = (lo+hi+1)/2;
    	int deg = 2*mid+par;
    	if(check(deg)) {
    		if(lo == hi) break;
    		lo = mid;
    	} else hi = mid-1;
    }
    thi = 2*lo+par;

    // DEBUG(tlo);
    // DEBUG(thi);

    // if(tlo > thi) {
    // 	cout << -1 << endl;
    // 	exit(0);
    // }

    // All in between are valid
    for(int i = tlo; i <= thi; i += 2) cout << i << ' ';
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
