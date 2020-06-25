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
typedef long long ll;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll l, r, x, y;
    cin >> l >> r >> x >> y;
    if(y % x != 0) {
    	cout << 0 << endl;
    	exit(0);
    }
    ll p = y/x, ans = 0;
    ll i = 1;
    while(i*i <= p) {
    	if(p % i == 0) {
    		if(i*x >= l && p/i * x <= r && gcd(i, p/i) == 1) {
    			++ans;
    			if(i != p/i) ++ans;
    		}
    	}
    	++i;
    }
    cout << ans << endl;

    return 0;
}