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

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    string s;
    cin >> s;
    int lb = -1, rb = -1, lc, rc;
    REP(i, s.size()) {
    	if(s[i] == '[' && lb == -1) lb = i;
    	if(s[i] == ':' && lb != -1) {
    		lc = i;
    		break;
    	}
    }
    FORD(i, s.size()-1, 0) {
    	if(s[i] == ']' && rb == -1) rb = i;
    	if(s[i] == ':' && rb != -1) {
    		rc = i;
    		break;
    	}
    }
    if(lc == rc || lc > rc || lb > rb || lb == -1 || rb == -1) cout << -1 << endl;
    else {
    	int num = 0;
    	FOR(i, lc, rc) num += (s[i] == '|');
    	cout << 4+num << endl;
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
