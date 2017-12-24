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
    //cout << fixed << setprecision(7);
    ll n, x, k;
    cin >> n >> x >> k;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    sort(a.begin(), a.end());
	ll ans = 0;
	REP(i, n) {
		ll bot = ceil(a[i]/(double)x)*x;
		ll top1 = max(a[i], bot + (k-1)*x), top2 = bot + k*x;
		ans += (lower_bound(a.begin(), a.end(), top2)-lower_bound(a.begin(), a.end(), top1));
	}
    cout << ans << endl;

    return 0;
}