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
    const int N = 20;
    int n, k, a[N];
    cin >> n >> k;
    assert(k == 4);
    // assert(k == 20);
    REP(i, n) cin >> a[i];
    ll s[4], ans = 0;
    REP(i, 4) s[i] = 0;
    FOR(i, 0, n-4) {
    	s[0] += a[i];
    	s[1] = 0;
    	FOR(j, i+1, n-3) {
    		s[1] += a[j];
    		s[2] = 0;
    		FOR(k, j+1, n-2) {
    			s[2] += a[k];
    			s[3] = 0;
    			FOR(l, k+1, n-1) {
    				s[3] += a[l];
    			}
				cout << "{0, " << i << "}, {" << i+1 << ", " << j << "}, {" << j+1 << ", " << k << "}, {" << k+1 << ", " << n-1 << "}" << endl;
				cout << s[0] << ' ' << s[1] << ' ' << s[2] << ' ' << s[3] << endl;
				cout << (s[0] & s[1] & s[2] & s[3]) << endl << endl;
    			ans = max(ans, s[0] & s[1] & s[2] & s[3]);
    		}
    	}
    }
    cout << ans << endl;

    return 0;
}