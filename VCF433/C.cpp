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

const ll N = 3e5+1;
ll n, k, c[N], ans = 0, sol[N];
pii p[N];
set<ll> rem;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    REP(i, n) cin >> c[i];
    REP(i, n) p[i] = {c[i], i};
    REP(i, n) rem.insert(i+k);
    sort(p, p+n, greater<pii>());
    REP(i, n) {
    	ll idx = p[i].second;
    	ll cur = *rem.lower_bound(idx);
    	sol[idx] = cur;
    	ans += (cur-idx)*c[idx];
    	rem.erase(cur);
    }
    cout << ans << endl;
    REP(i, n) cout << sol[i]+1 << ' ';
    cout << endl;

    return 0;
}