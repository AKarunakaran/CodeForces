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
// #define DEBUG(x) cout << '>' << #x << ':' << x << endl;
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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll n;
    cin >> n;
    vector<ll> v(n);
    REP(i, n) cin >> v[i];
    vector<ll> t(n);
    REP(i, n) cin >> t[i];
    multiset<ll> p;
    ll sub = 0;
    REP(i, n) {
    	ll ans = 0;
    	p.insert(v[i]+sub);
    	ll curT = t[i];
    	auto itr = p.begin();
    	// DEBUG(sub);
    	// DEBUG(v[i]);
    	// DEBUG(t[i]);
    	// DEBUG(p.size());
    	while(itr != p.end() && *itr <= curT+sub) {
    		++itr;
    		// DEBUG(*p.begin());
    		ans += *p.begin()-sub;
    		p.erase(p.begin());
    	}
    	ans += p.size()*curT;
    	sub += curT;
    	cout << ans << ' ';
    }
    cout << endl;

    return 0;
}