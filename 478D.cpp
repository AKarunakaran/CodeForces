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
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// #define int long long
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

//h^2+h-2n = 0 --> h = (-1+sqrt(1+8n))/2
const int N = 4e5+10, M = 1e9+7, H = 900;
int a, b, n, h, dp1[N], dp2[N], *old, *cur, full[H];

int add(int x, int y) {return (x+y)%M;}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    old = dp1, cur = dp2;
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    full[0] = 0;
    FOR(i, 1, H-1) full[i] = full[i-1]+i;
    cin >> a >> b;
    n = a+b;
    h = (-1+sqrt(1+8*n))/2;
    old[0] = 1;
    REP(i, h) {
    	FOR(j, 0, n) {
    		if(old[j]) {
    			int r = j, g = full[i]-j;
    			if(r+i+1 <= a) cur[r+i+1] = add(cur[r+i+1], old[j]);
    			if(g+i+1 <= b) cur[r] = add(cur[r], old[j]);
    		}
    	}
    	fill(old, old+n+1, 0);
    	swap(old, cur);
    }
    int ans = 0;
    FOR(i, 0, n) ans = add(ans, old[i]);
    cout << ans << endl;

    return 0;
}