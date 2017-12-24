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

ll maxCont(vector<ll>& v) {
	ll max_so_far = nINF, max_ending_here = 0;
 
    for (int i = 0; i < v.size(); i++)
    {
        max_ending_here = max_ending_here + v[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    vector<ll> d(n-1);
    REP(i, n-1) d[i] = abs(a[i]-a[i+1]);

    // REP(i, n-1) cout << d[i] << " ";
    // cout << endl;

    vector<ll> e = d, o = d;
    REP(i, n-1) {
    	if(i & 1) o[i] *= -1;
    	else e[i] *= -1;
    }

    ll ans = 0;
    ans = max(ans, maxCont(e));
    ans = max(ans, maxCont(o));
    cout << ans << endl;

    return 0;
}