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
typedef long double ld;

/////////////////////////////////////////////////////////////////////

ll n, h;
const ld eps = 1e-9;

ld gettest(ld m) {
	if(h >= m) return (m*(m+1))/2;
	return ((h*(h+1))/2) + h*(m-h);
}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(0);
    cin >> n >> h;
    ld lo = 1, hi = n;
    while(abs(lo - hi) >= 0.5) {
    	// DEBUG(lo);
    	// DEBUG(hi);
    	ld mid = lo+(hi-lo)/2;
    	mid = floor(mid+eps);
    	// DEBUG(mid);
    	ld test = round(gettest(mid));
    	// DEBUG(test);
    	// if(test < 0) {
    	// 	DEBUG(mid);
    	// 	cout << "BADtest" << endl;
    	// }
    	if(test+eps < n) lo = mid+1;
    	else hi = mid;
    }
    cout << round(lo) << endl;

    return 0;
}