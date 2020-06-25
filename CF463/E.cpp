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

// Finds constants {u, v} s.t. a*u+b*v = g for g = gcd(a, b)
// Call with egcd(a, b)
pll egcd(ll a, ll b, pll x = {1, 0}, pll y = {0, 1}) {
    return (b == 0) ? x : egcd(b, a % b, y, {x.first - a/b * y.first, x.second - a/b * y.second});
}

// Finds x s.t. (a*x) % n == 1
// Assumes a is not zero divisor (i.e. gcd(a, n) == 1)
ll modInv(ll a, ll n) {
    return ((egcd(a, n).first % n) + n) % n;
}

ll add(ll a, ll b) {return (a+b)%M;}
ll sub(ll a, ll b) {return (a+M-b)%M;}
ll mult(ll a, ll b) {return (a*b)%M;}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll n, k;
    cin >> n >> k;

    ll dd[5001];
    fill(dd, dd+5001, 0);
    dd[1] = 1;

    ll inv[5001];
    FOR(i, 1, 5000) inv[i] = modInv(i, M);

    ll choose[5001];
    fill(choose, choose+5001, 0);
    choose[0] = 1;
    FOR(i, 1, 5000) choose[i] = mult(choose[i-1], mult(n+1-i, inv[i]));


    FOR(i, 2, 5000) {
        if(i > k) break;
        ll s = 0;
        ll chooseG = 1;
        FOR(j, 1, i-1) {
            chooseG = mult(chooseG, mult(i+1-j, inv[j]));
            s = add(s, mult(chooseG, dd[j]));
        }
        dd[i] = sub(fastPowMod(i, k), s);
    }

    ll ans2 = 0;
    FOR(i, 1, min((ll)n, k)) {
        ll toAdd = choose[i];
        toAdd = mult(toAdd, fastPowMod(2, n-i));
        toAdd = mult(toAdd, dd[i]);
        ans2 = add(ans2, toAdd);
    }
    cout << ans2 << endl;

    return 0;
}