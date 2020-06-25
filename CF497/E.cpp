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

ll n;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    ll xlo = 1, xhi = n, ylo = 1, yhi = n;
    int ans;
    while(xlo < xhi || ylo < yhi) {
    	ll xmid = (xlo+xhi)/2, ymid = (ylo+yhi)/2;
    	cout << xmid << ' ' << ymid;
    	cin >> ans;
    	if(ans == 0) exit(0);
    	if(ans == 1) {
    		xlo = xmid+1;
    		continue;
    	}
    	if(ans == 2) {
    		ylo = ymid+1;
    		continue;
    	}
    	if(ans == 3) {
    		ll tempxhi = xmid-1;
    		ll tempyhi = ymid-1;
    		ll l = xlo, r = xhi;
    		while(l < r) {
    			ll m = (l+r)/2;
    			cout << m << ' ' << tempyhi+1 << endl;
    			cin >> ans;
    			if(ans == 0) exit(0);
    			else if(ans == 1) l = m+1;
    			else if(ans == 2) {
    				ylo = tempyhi;
    				break;
    			} else if(ans == 3) {
    				ylo = tempyhi;
    				l = m-1;
    				break;
    			}
    		}
    		xlo = l, xhi = r;
    	}
    }
    if(xlo == xhi) {
    	//
    } else {
    	//
    }

    return 0;
}