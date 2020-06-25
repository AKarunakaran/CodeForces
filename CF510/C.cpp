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
int n, a[N];

void finish(vector<int>& rem) {
	int k = rem.size();
	if(k == 1) {
		cout << "2 " << rem[0] << endl;
	} else if(k == n) {
		rem.clear();
		k = 0;
	} else if(k > 0) {
		int zidx = 0;
		REP(i, k) if(a[rem[i]] == 0) zidx = i;
		REP(i, k) if(i != zidx) cout << "1 " << rem[i] << ' ' << rem[zidx] << endl;
		cout << "2 " << rem[zidx] << endl;
	}
	vector<int> keep;
	int idx = 0;
	FOR(i, 1, n) {
		if(idx < k && rem[idx] == i) ++idx;
		else keep.push_back(i);
	}
	k = keep.size();
	FOR(i, 1, k-1) cout << "1 " << keep[i] << ' ' << keep[0] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    bool badneg = false;
    int badnegid = 0;
    vector<int> rem;
    cin >> n;
    FOR(i, 1, n) {
    	cin >> a[i];
    	if(a[i] == 0) rem.push_back(i);
    	if(a[i] < 0) {
    		badneg = !badneg;
    		if(badnegid == 0) badnegid = i;
    		else if(a[i] > a[badnegid]) badnegid = i;
    	}
    }
    if(badneg) rem.push_back(badnegid);
	sort(rem.begin(), rem.end());
	finish(rem);

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
