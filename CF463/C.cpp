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
    int n, a, b;
    cin >> n >> a >> b;
    int u = -1, v = -1;
    for(int x = 0; x <= n; x += a) {
    	if((n-x) % b == 0) {
    		u = x/a;
    		v = (n-x)/b;
    		break;
    	}
    }
    // DEBUG(u);
    // DEBUG(v);
    if(u == -1) {
    	cout << -1 << endl;
    	exit(0);
    }
    vector<int> l;
    l.resize(u, a);
    l.resize(u+v, b);
    int lidx = 0, idx = 1;
    vector<int> ans(n+1);
    iota(ans.begin(), ans.end(), 0);
    while(lidx < u+v) {
    	int curS = l[lidx++];
    	// DEBUG(curS);
    	// DEBUG(*(ans.begin()+idx))
    	// DEBUG(*(ans.begin()+idx+curS));
    	if(curS > 1) rotate(ans.begin()+idx, ans.begin()+idx+1, ans.begin()+idx+curS);
    	idx += curS;
    }
    FOR(i, 1, n) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}