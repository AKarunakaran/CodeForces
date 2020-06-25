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
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <limits>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;
#define REP(i,n) for(ll i=0;i<(n);i++)

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ld n;
    cin >> n;
    vector<ld> a(n);
    REP(i, n) cin >> a[i];
    ld s = 0, ans = 0;
    unordered_map<ld, ld> m;
    REP(i, n) {
    	ans += i*a[i]-s;
    	ans += (m[a[i]+1]-m[a[i]-1]);
    	++m[a[i]];
    	s += a[i];
    }
    cout << (ans > numeric_limits<ll>::max() ? ans - numeric_limits<ll>::min() : ans) << endl;

    return 0;
}