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
const ll N = 50, m = 5;
ll n, p[N], c[m];

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> p[i];
    REP(i, m) cin >> c[i];
    ll s = 0, ans[m];
    fill(ans, ans+m, 0);
    REP(i, n) {
    	s += p[i];
    	FORD(j, m-1, 0) {
    		if(s >= c[j]) {
    			ll k = s/c[j];
    			s -= k*c[j];
    			ans[j] += k;
    		}
    	}
    }
    REP(i, m) cout << ans[i] << ' ';
    cout << endl << s << endl;

    return 0;
}