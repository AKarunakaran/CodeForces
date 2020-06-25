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
const ll M = 1e9+7, N = 1e6+2;
ll n, h[N], ans = 0;

ll add(ll a, ll b) {
	return (a+b) % M;
}

ll mult(ll a, ll b) {
	return (a*b) % M;
}

void solve(int l, int r) {
	ll cur = 0;
	FORD(i, r, l) {
		cur = add(cur, 1);
		cur = mult(cur, h[i]-1);
		ans = add(ans, cur);
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    FOR(i, 1, n) cin >> h[i];
    h[0] = 1, h[n+1] = 1;
    int last = 0;
    FOR(i, 1, n+1) {
    	if(h[i] == 1) {
    		solve(last+1, i-1);
    		last = i;
    	}
    }
    cout << ans << endl;

    return 0;
}