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
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    if(k == 1) {
        cout << (n-1)*a << endl;
        exit(0);
    }
    ll ans = 0;
    while(n != 1) {
    	while(n % k == 0) {
    		n /= k;
    		ans += min(n*(k-1)*a, b);
    	}
        if(n > k) {
            ans += (n % k)*a;
            n -= n % k;
        } else {
            ans += (n-1)*a;
            n = 1;
        }
    }
    cout << ans << endl;

    return 0;
}