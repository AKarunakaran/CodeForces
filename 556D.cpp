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
int n, m, ans[N];
pll p[N];
pair<pll, int> a[N];
multiset<pll> ms;

void bad() {
	cout << "No" << endl;
	exit(0);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    REP(i, n) cin >> p[i].first >> p[i].second;
    REP(i, m) {
    	ll l;
    	cin >> l;
    	ms.insert({l, i+1});
    }
    REP(i, n-1) {
    	ll r = p[i+1].second-p[i].first, l = p[i+1].first-p[i].second;
    	a[i] = {{l, r}, i};
    }
    sort(a, a+n-1, [](auto& left, auto& right){
    	return left.first.second < right.first.second || (left.first.second == right.first.second && left.first.first < right.first.first);});
    REP(i, n-1) {
    	auto itr = ms.lower_bound({a[i].first.first, 0});
    	if(itr == ms.end()) bad();
    	if(itr->first <= a[i].first.second) {
    		ans[a[i].second] = itr->second;
    		ms.erase(itr);
    	} else bad();
    }
    cout << "Yes" << endl;
    REP(i, n-1) cout << ans[i] << ' ';
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

