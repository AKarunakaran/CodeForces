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
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int t[6];
    REP(i, 6) cin >> t[i];
    int l = t[0]+t[1]+t[2], r = t[3]+t[4]+t[5];
    sort(t, t+3);
    sort(t+3, t+6);
    if(l == r) {
    	cout << 0 << endl;
    } else if(l > r) {
    	int d = l-r;
    	int ans = 0;
    	int i = 3;
    	while(d) {
    		int c = 9-t[3+ans];
    		d -= min(d, c);
    		++ans;
    	}
    	cout << ans << endl;
    } else {
    	int d = r-l;
    	int ans = 0;
    	int i = 3;
    	while(d) {
    		int c = 9-t[ans];
    		d -= min(d, c);
    		++ans;
    	}
    	cout << ans << endl;
    }

    return 0;
}