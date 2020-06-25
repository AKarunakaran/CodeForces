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

ll c2(ll a) {
	if(a == 1) return 0;
	if(a & 1) return ((a-1)/2)*a;
	return (a/2)*(a-1);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll n, k;
    cin >> n >> k;
    ll ans = 0, ps = 0, ns = 0, m;
    vector<ll> a(n);
    REP(i, n) {
    	cin >> a[i];
    	if(a[i] > 0) ps += a[i];
    	else ns += a[i];
    }
    m = max(ps, abs(ns));
    vector<ll> p;
    p.push_back(1);
    while(abs(p.back()*k) <= m && p.back()*k != p[0]) p.push_back(p.back()*k);
    map<ll, int> prefs;
    ll pf = 0;
    prefs[0] = 1;
    REP(i, n) {
    	pf += a[i];
    	// DEBUG(i);
    	// DEBUG(pf);
    	for(auto j : p) {
    		// DEBUG(pf-j);
    		// DEBUG(prefs[pf-j]);
    		if(prefs.find(pf-j) != prefs.end()) ans += prefs[pf-j];
    	}
    	++prefs[pf];
    }
    cout << ans << endl;

    return 0;
}