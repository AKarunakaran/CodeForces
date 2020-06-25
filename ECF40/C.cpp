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
    // cout << fixed << setprecision(7);
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i,n) cin >> a[i];
    ll x = 1e9, y = -1;
    REP(i, n-1) {
    	ll diff = abs(a[i] - a[i+1]);
    	if(diff == 0) {
    		cout << "NO" << endl;
    		exit(0);
    	}
    	if(diff != 1) {
    		if(y != -1 && y != diff) {
    			cout << "NO" << endl;
    			exit(0);
    		}
    		y = diff;
    	}
    }
    if(y == -1) {
    	cout << "YES" << endl << x << " 1" << endl;
    	exit(0);
    }
    REP(i, n-1) {
    	ll diff = abs(a[i] - a[i+1]);
    	if(diff == 1) {
    		if((a[i] > a[i+1] && a[i] % y == 1) || (a[i] < a[i+1] && a[i] % y == 0)) {
    			cout << "NO" << endl;
    			exit(0);
    		}
    	}
    }
    cout << "YES" << endl;
    cout << x << ' ' << y << endl;

    return 0;
}