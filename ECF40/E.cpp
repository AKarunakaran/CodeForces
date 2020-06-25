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

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(7);
    ll n;
    double t;
    cin >> n >> t;
    vector<pll> a(n);
    REP(i, n) cin >> a[i].first;
    REP(i, n) cin >> a[i].second;
    sort(a.begin(), a.end(), [](pii left, pii right){return left.second < right.second;});
    if(a.front().second > t || a.back().second < t) {
    	cout << 0 << endl;
    	exit(0);
    }
    double cur = 0;
    double q = 0;
    REP(i, n) {
    	cur += a[i].first*a[i].second;
    	q += a[i].first;
    }
    ll f = 0, b = n-1;
    while(!EQ(cur/q, t)) {
    	// DEBUG(cur/q);
    	if(cur/q > t) {
    		if(f < b && (cur-(a[b].first*a[b].second))/(q - a[b].first) > t) {
    			cur -= a[b].first*a[b].second;
    			q -= a[b].first;
    			--b;
    		} else {
    			double l = 0, r = a[b].first;
    			// DEBUG(l);
    			// DEBUG(r);
    			while(abs(r-l) >= 1e-8) {
    				double m = (l+r)/2;
    				// DEBUG(m);
    				// DEBUG((cur-(a[b].second*m))/(q - m));
    				if((cur-(a[b].second*m))/(q - m) > t) l = m;
    				else r = m;
    			}
    			cur -= a[b].second*l;
    			q -= l;
    			break;
    		}
    	} else {
    		if(f < b && (cur-(a[f].first*a[f].second))/(q - a[f].first) < t) {
    			cur -= a[f].first*a[f].second;
    			q -= a[f].first;
    			++f;
    		} else {
    			double l = 0, r = a[f].first;
    			while(abs(r-l) >= 1e-8) {
    				double m = (l+r)/2;
    				if((cur-(a[f].second*m))/(q - m) < t) l = m;
    				else r = m;
    			}
    			cur -= a[f].second*l;
    			q -= l;
    			break;
    		}
    	}
    }
    cout << q << endl;

    return 0;
}