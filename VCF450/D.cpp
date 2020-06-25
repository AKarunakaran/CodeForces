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

const ll M = 1000000007;

ll fastPowMod(ll base, ll power) {
    ll res = 1;
    while(power) {
        if(power & 1) res = (res*base) % M;
        base = (base*base) % M;
        power >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll x, y;
    cin >> x >> y;
    if(y % x != 0) {
    	cout << 0 << endl;
    	exit(0);
    }
    y /= x;
    x = 1;
    vector<ll> d;
    map<ll, ll> dp;
    for(ll i = 1; i*i <= y; ++i) {
    	if(y % i == 0) {
    		d.push_back(i);
    		if(i*i != y) d.push_back(y/i);
    	}
    }
    sort(d.begin(), d.end());
    REP(i, d.size()) {
        dp[d[i]] = (dp[d[i]]+fastPowMod(2, d[i]-1)) % M;
        FOR(j, i+1, d.size()-1) {
            if(d[j] % d[i] == 0) {
                dp[d[j]] = (dp[d[j]]-dp[d[i]] + M) % M;
            }
        }
    }
    cout << dp[y] << endl;

    return 0;
}