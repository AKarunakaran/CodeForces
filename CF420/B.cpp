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
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll m, b;
    cin >> m >> b;
    ll l = m*b;
    ll ans = b*(b+1)/2;
    //DEBUG(ans);
    ll cur = ans - b;
    ll j = 0;
    FORD(i, b-1, 0) {
    	ll s = i*(i+1)/2;
    	while(j < (b-i)*m) {
    		++j;
    		cur += (((i+1)*j)+s);
    	}
    	//DEBUG(i);
    	//DEBUG(j);
    	//DEBUG(cur);
    	ans = max(ans, cur);
    	cur -= (i*(j+1)+(j*(j+1))/2);
    }
    cout << ans << endl;

    return 0;
}