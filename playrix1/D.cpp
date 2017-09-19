#include <iostream>
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
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }

/////////////////////////////////////////////////////////////////////

int main() {
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    vector<int> m(n);
    REP(i, n) cin >> m[i];
    sort(m.begin(), m.end());
    int o1, o2, ht = h, wt = w;
    int x = n-1;
    while(x >= 0) {
    	//DEBUG(h);
    	//DEBUG(w);
    	if(h >= a && w >= b) break;
    	if((double)a/h > (double)b/w) h *= m[x--];
    	else w *= m[x--];
    }
    //DEBUG(h);
    //DEBUG(w);
    o1 = ((h >= a && w >= b) || (h >= b && w >= a)) ? n-1-x : -1;
    h = ht;
    w = wt;
    x = n-1;
    //cout << endl;
    while(x >= 0) {
    	//DEBUG(h);
    	//DEBUG(w);
    	if(h >= b && w >= a) break;
    	if((double)b/h > (double)a/w) h *= m[x--];
		else w *= m[x--];
    }
    //DEBUG(h);
    //DEBUG(w);
    o2 = ((h >= a && w >= b) || (h >= b && w >= a)) ? n-1-x : -1;
    //cout << endl;
    //DEBUG(o1);
    //DEBUG(o2);
    if(o1 && o2 == -1) {
    	cout << -1 << endl;
    } else if ((o1 == -1 && o2 != -1) || (o1 != -1 && o2 == -1)) {
    	cout << max(o1, o2) << endl;
    } else {
    	cout << min(o1, o2) << endl;
    }

    return 0;
}