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

ll dig(ll n) {
	ll res = 0;
	while(n) {
		++res;
		n /= 10;
	}
	return res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll n;
    cin >> n;
    if(n == 1) {
    	cout << 0 << endl;
    	return 0;
    }
    ll high = 2*n-1;
    if(dig(high+1) > dig(high)) {
    	cout << 1 << endl;
    	exit(0);
    }
    ll d = dig(high);
    ll count = d-1;
    if(count == 0) {
    	cout << (n*(n-1))/2 << endl;
    	return 0;
    }
    ll ten = pow(10, count);
    ll cur = ten - 1, ans = 0;
    REP(i, 10) {
    	if(cur-n >= n) break;
    	// DEBUG(cur);
    	ans += ((n < cur-1) ? (2*n-cur+1)/2 : (cur-1)/2);
    	cur += ten;
    }
    cout << ans << endl;

    return 0;
}