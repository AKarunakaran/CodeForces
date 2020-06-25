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
#define int long long
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

const int N = 1000;
int n;
pii a[N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) {
    	string s;
    	cin >> a[i].first >> s;
    	sort(s.begin(), s.end());
    	if(s == "A") a[i].second = 1;
    	if(s == "B") a[i].second = 2;
    	if(s == "C") a[i].second = 4;
    	if(s == "AB") a[i].second = 3;
    	if(s == "BC") a[i].second = 6;
    	if(s == "AC") a[i].second = 5;
    	if(s == "ABC") a[i].second = 7;
    	// cout << a[i].first << ' ' << a[i].second << endl;
    }
    int ans = INF;
    int one = INF, two = INF, three = INF;
    REP(i, n) {
    	if((a[i].second & 1) == 1) one = min(one, a[i].first);
    	if((a[i].second & 2) == 2) two = min(two, a[i].first);
    	if((a[i].second & 4) == 4) three = min(three, a[i].first);
    }
    ans = min(ans, one+two+three);
    // cout << one << ' ' << two << ' ' << three << endl;
    // DEBUG(ans);

    one = INF, two = INF;
    REP(i, n) {
    	if((a[i].second & 3) == 3) one = min(one, a[i].first);
    	if((a[i].second & 4) == 4) two = min(two, a[i].first);
    }
    ans = min(ans, one+two);
    // cout << one << ' ' << two << endl;
    // DEBUG(ans);
    
    one = INF, two = INF;
    REP(i, n) {
    	if((a[i].second & 5) == 5) one = min(one, a[i].first);
    	if((a[i].second & 2) == 2) two = min(two, a[i].first);
    }
    ans = min(ans, one+two);
    // cout << one << ' ' << two << endl;
    // DEBUG(ans);
    
    one = INF, two = INF;
    REP(i, n) {
    	if((a[i].second & 6) == 6) one = min(one, a[i].first);
    	if((a[i].second & 1) == 1) two = min(two, a[i].first);
    }
    ans = min(ans, one+two);
    // cout << one << ' ' << two << endl;
    // DEBUG(ans);
    
    one = INF;
    REP(i, n) {
    	if((a[i].second & 7) == 7) one = min(one, a[i].first);
    }
    ans = min(ans, one);
    // cout << one << endl;
    // DEBUG(ans);

    cout << (ans == INF ? -1 : ans) << endl;

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
