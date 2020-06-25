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

const ll M = 1e9+7;

ll fastPowMod(ll base, ll power) {
    ll res = 1;
    while(power) {
        if(power & 1) res = (res*base) % M;
        base = (base*base) % M;
        power >>= 1;
    }
    return res;
}

ll sub(ll a, ll b) {return (a+M-b) % M;}
ll add(ll a, ll b) {return (a+b) % M;}
ll mult(ll a, ll b) {return (a*b) % M;}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll x, k;
    cin >> x >> k;
    x <<= 1;
    if(x == 0) cout << 0 << endl;
    else cout << add(mult(sub(x, 1), fastPowMod(2, k)),  1) << endl;

    return 0;
}