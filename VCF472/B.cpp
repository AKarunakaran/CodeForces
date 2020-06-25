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
using namespace std; 
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
const ll N = 1e5;
ll e[N], n, u;
double ans = 0;


int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin >> n >> u;
    REP(i, n) cin >> e[i];
    // ll i = 0, k = 2;
    // while(k < n) {
    // 	while(k < n && e[k] - e[i] > u) {
    // 		if(i+2 == k) ++k;
    // 		++i;
    // 	}
    // 	if(k == n) break;
    // 	while(k+1 < n && e[k+1]-e[i] <= u) ++k;
    // 	// DEBUG(i);
    // 	// DEBUG(k);
    // 	ans = max(ans, (e[k]-e[i+1])/((double)(e[k]-e[i])));
    // 	++k;
    // }
    REP(i, n) {
    	auto itr = upper_bound(e, e+n, e[i]+u);
    	--itr;
    	ll idx = itr-e;
    	if(idx >= i+2) {
    		double cur = e[idx]-e[i+1];
    		cur /= (e[idx]-e[i]);
    		ans = max(ans, cur);
    	}
    }
    cout << (abs(ans) < 1e-9 ? -1 : ans) << endl;

    return 0;
}