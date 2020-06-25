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

const int N = 5e4+10;
int n, a[N];
multiset<int, greater<int>> ms;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) {
    	cin >> a[i];
    	ms.insert(a[i]);
    }
    bool can = true;
    while(can) {
    	can = false;
    	for(int hi : ms) {
    		for(int i = 2; i*i <= hi; ++i) {
    			if(hi % i == 0) {
    				int lo = hi/i;
    				if(*ms.rbegin()*i <= lo) {
    					int rem = *ms.rbegin();
    					// DEBUG(hi);
    					// DEBUG(rem);
    					// DEBUG(i);
    					ms.erase(ms.find(hi));
    					ms.erase(ms.find(rem));
    					ms.insert(hi/i);
    					ms.insert(rem*i);
	    				can = true;
	    				break;
    				}
    			}
    		}
    		if(can) break;
    	}
    }
    int sum = 0;
    for(int x : ms) sum += x;
    cout << sum << endl;

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

