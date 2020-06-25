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

const int N = 2e5+10;
int n, a[N], last[N], ans[N], spec[N];

void bad() {
	cout << "NO" << endl;
	exit(0);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    set<pii> tails;
    tails.insert({-1, 0});
    bool have_spec = false;
    FOR(i, 1, n) {
    	auto itr = tails.lower_bound({a[i], 0});
    	if(itr != tails.end()) {
    		if(itr->first == a[i] && itr->first == tails.rbegin()->first) {
    			if(have_spec) bad();
    			have_spec = true;
    			spec[i] = itr->second;
    			spec[itr->second] = i;
    		}
    		tails.erase(itr);
    	}
    	auto itr2 = tails.insert({a[i], i}).first;
    	--itr2;
    	last[i] = itr2->second;
    }
    int id = tails.rbegin()->second;
    while(id) {
    	ans[id] = 1;
    	id = last[id];
    }
    bool good = true;
    int bef = -1;
    FOR(i, 1, n) {
    	if(ans[i] == 0) {
    		if(bef == -1) bef = a[i];
    		else {
    			if(a[i] >= bef) {
    				good = false;
    				break;
    			} else {
    				bef = a[i];
    			}
    		}
    	}
    }
    if(!good) {
	    if(have_spec) {
	    	FOR(i, 1, n) {
	    		if(spec[i]) {
	    			DEBUG(i);
	    			DEBUG(spec[i]);
	    			cout << ans[i] << ' ' << ans[spec[i]] << endl;
	    			swap(ans[i], ans[spec[i]]);
	    			break;
	    		}
	    	}
	    	bef = -1;
	    	FOR(i, 1, n) {
		    	if(ans[i] == 0) {
		    		if(bef == -1) bef = a[i];
		    		else {
		    			if(a[i] >= bef) {
		    				good = false;
		    				break;
		    			} else {
		    				bef = a[i];
		    			}
		    		}
		    	}
		    }
	    } else bad();
    }
    cout << "YES" << endl;
    FOR(i, 1, n) cout << 1-ans[i] << ' ';
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
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)

