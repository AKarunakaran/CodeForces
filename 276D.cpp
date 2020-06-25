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

ll full(ll x) {
	FOR(i, 0, 5) x |= x >> (1 << i);
	return x;
}

ll solve(ll l, ll r) {
	if(l == r) return 0;
	ll mask = 1LL << 62;
	while(!(mask & r)) mask >>= 1;
	if(mask & l) return solve(l-mask, r-mask);
	else return full(mask);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll l, r;
    cin >> l >> r;
    cout << solve(l, r) << endl;

    return 0;
}