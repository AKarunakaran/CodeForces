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
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

ll n, s;

bool reallyBig(ll k) {
	ll k2 = k, d = 0;
	while(k2) {
		d += (k2%10);
		k2 /= 10;
	}
	return (k - d) >= s;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> s;
    ll begin = 0, end = n, half;
    while(begin < end) {
    	half = (end-begin)/2;
    	if(!reallyBig(begin+half) && reallyBig(begin+half+1)) {
    		cout << n-(begin+half) << endl;
    		return 0;
    	}
    	if(reallyBig(begin+half)) end = begin + half - 1;
    	else begin = begin + half + 1;
    }
    if(!reallyBig(begin) && reallyBig(begin+1)) {
		cout << n-(begin) << endl;
		return 0;
	}
    cout << 0 << endl;

    return 0;
}