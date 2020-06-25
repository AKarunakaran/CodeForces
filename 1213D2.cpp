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
int n, k, a[N];
unordered_map<int, pair<int, multiset<int>>> m;

void print(multiset<int>& s) {
	cout << "{";
	for(int x : s) cout << x << ' ';
	cout << "}" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    REP(i, n) {
    	int times = 0;
    	while(a[i]) {
    		auto& val = m[a[i]];
    		int& sum = val.first;
    		auto& s = val.second;
    		// DEBUG(a[i]);
    		// DEBUG(sum);
    		// print(s);
    		if(s.size() < k) {
    			sum += times;
    			s.insert(times++);
    		} else if(s.size() == k && *s.rbegin() > times) {
    			sum += times-*s.rbegin();
    			s.erase(s.find(*s.rbegin()));
    			s.insert(times++);
    		}
    		a[i] >>= 1;
    	}
    }
    int ans = INF;
    for(auto& p : m) {
    	auto& pr = p.second;
    	if(pr.second.size() == k) ans = min(ans, pr.first);
    }
    cout << ans << endl;

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

