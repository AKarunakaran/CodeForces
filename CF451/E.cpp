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
typedef pair<char, ll> pci;

/////////////////////////////////////////////////////////////////////

ll nextNon(ll a) {
	return a ? 1 : 2;
}

ll isqrt(ll a) {
	return sqrt(a);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll n;
    cin >> n;
    vector<ll> nums(n);
    REP(i, n) cin >> nums[i];
    ll p = 0;
    vector<pll> pm(n);
    REP(i, n) {
    	ll a = nums[i];
    	if(isqrt(a)*isqrt(a) == a) {
    		++p;
    		pm[i].first = 1;
    		pm[i].second = nextNon(a);
    	} else {
    		pm[i].first = 0;
    		pm[i].second = min((a-(isqrt(a)*isqrt(a))), (((isqrt(a)+1)*(isqrt(a)+1))-a));
    	}
    }
    ll ans = 0;
	vector<ll> m;
    if(p > n/2) {
    	REP(i, n) if(pm[i].first == 1) m.push_back(pm[i].second);
    } else if(p < n/2) {
    	REP(i, n) if(pm[i].first == 0) m.push_back(pm[i].second);
    }
	sort(m.begin(), m.end());
	REP(i, abs(p-n/2)) ans += m[i];
	cout << ans << endl;

    return 0;
}