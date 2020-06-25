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
typedef long long ll;
const ll INF = 0x7fffffffffffffffLL;
const int nINF = 1<<31;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 1e6+1;
int n, m, k, a[N], pre[N];
bool block[N];

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> k;
    REP(i, m) {
    	int x;
    	cin >> x;
    	block[x] = 1;
    }
    FOR(i, 1, k) cin >> a[i];
    int last = 0;
    REP(i, n) {
    	if(!block[i]) last = i;
    	pre[i] = last;
    }
    bool onRun = false;
    int start = 0, longrun = 0;
    REP(i, n) {
    	if(onRun && !block[i]) {
    		longrun = max(longrun, i-start);
    		onRun = false;
    	}
    	if(!onRun && block[i]) {
    		start = i;
    		onRun = true;
    	}
    }
    if(onRun) longrun = max(longrun, n-start);
    if(longrun >= k || block[0]) {
    	cout << -1 << endl;
    	exit(0);
    }
    ll ans = INF;
    FOR(test, 1, k) {
    	if(longrun >= test) continue;
    	// DEBUG(test);
    	ll cnt = 0;
    	last = 0;
    	while(last < n) {
    		// DEBUG(last);
    		int cur = pre[last];
    		last = cur+test;
    		++cnt;
    	}
    	// DEBUG(cnt);
    	ans = min(ans, cnt*a[test]);
    }
    cout << ans << endl;

    return 0;
}