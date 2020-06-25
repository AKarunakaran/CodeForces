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

const ll N = 1e5+1;
ll n, k, l, m, a[N];

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k >> l;
    m = n*k;
    REP(i, m) cin >> a[i];
    sort(a, a+m);
    ll idx = m;
    REP(i, m) {
    	if(a[i] > a[0]+l) {
    		idx = i;
    		break;
    	}
    }
    if(idx < n) {
    	cout << 0 << endl;
    	exit(0);
    }
    ll waste = idx-n, ans = 0;
    REP(i, idx) {
    	if(i % k == 0) {
    		ans += a[i];
    		--n;
    	} else --waste;
    	if(waste == 0) {
    		FOR(j, 1, n) {
    			ans += a[i+j];
    		}
    		break;
    	}
    }
    cout << ans << endl;

    return 0;
}