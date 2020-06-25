#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
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

// [l, r]
int randrange(int l, int r) { return (rand() % (r-l+1)) + l; }

bool test(ll l, ll r) {
	cout << l << ' ' << r << endl;
	string s;
	cin >> s;
	if(s == "Bad") exit(0);
	if(l == r && s == "Yes") exit(0);
	return (s == "Yes");
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    srand(time(NULL));
    ll n, k;
    cin >> n >> k;
    ll l = 1, r = n;
    ll TOL = 4*k;
    while(1) {
	    while(r-l > TOL) {
	    	ll m = l+(r-l)/2;
	    	bool check = test(l, m);
	    	if(check) {
		    	l = max(1LL, l-k);
		    	r = min(n, m+k);
	    	} else {
	    		l = max(1LL, m+1-k);
		    	r = min(n, r+k);
	    	}
	    }
	    int len = r-l+1;
	    int id = randrange(0, len-1);
	    bool check = test(l+id, l+id);
	    if(check) break;
	    r = min(n, r+k);
	    l = max(1LL, l-k);
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
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
