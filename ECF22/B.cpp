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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll x, y, l, r;
    cin >> x >> y >> l >> r;
    vector<ll> unlucky;
    ll a = 0, b = 0;
    while(pow(x,a)+1 <= r) {
    	b = 0;
    	while(pow(x,a) + pow(y, b) <= r) {
    		if(pow(x,a) + pow(y, b) >= l) unlucky.push_back(pow(x,a) + pow(y, b));
    		++b;
    	}
    	++a;
    }
    sort(unlucky.begin(), unlucky.end());
    //REP(i, unlucky.size()) cout << unlucky[i] << " ";
    //cout << endl;
    ll ans = 0;
    ll prev = l-1;
    REP(i, unlucky.size()) {
    	ans = max(ans, unlucky[i]-prev-1);
    	prev = unlucky[i];
    }
    ans = max(ans, r-prev);
    cout << ans << endl;

    return 0;
}