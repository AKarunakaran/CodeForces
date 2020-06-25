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

// int best = 0, bestl = 0;

int digsum(ll n) {return n ? (n%10)+digsum(n/10) : 0;}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll n;
    string s;
    cin >> n;
    s = to_string(n);
    if(s.size() == 1) {
    	cout << n << endl;
    	exit(0);
    }
    // best = digsum(n);
    // FOR(i, 0, n) {
    // 	int cur = digsum(i)+digsum(n-i);
    // 	if(cur > best) {
    // 		best = cur;
    // 		bestl = min((ll)i, n-i);
    // 	}
    // }
    // if(digsum(n/2)+digsum((n+1)/2) == best) cout << "YES" << endl;
    // cout << bestl << ' ' << n-bestl << endl;
    string ans;
    if(s[0] != '1')
    	ans.push_back('1');
    ans.resize(ans.size()+s.size()-1, '9');
    ll a = stoll(ans);
    cout << digsum(a) +digsum(n-a) << endl;

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
