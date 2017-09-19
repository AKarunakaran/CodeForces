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
const int INF = 1<<29;
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
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> d(n, 0);
    vector<int> z;
    REP(i, n) cin >> a[i];
    REP(i, n) if(!a[i]) z.push_back(i);
    int c = 0;
    REP(i, n) {
    	if(!a[i]) ++c;
    	else {
    		if(c == 0) {
    			d[i] = z[0] - i;
    		} else if (c == z.size()) {
    			d[i] = i - z.back();
    		} else {
    			d[i] = min(z[c] - i, i - z[c-1]);
    		}
    	}
    }
    REP(i, n) cout << d[i] << " ";
    cout << endl;

    return 0;
}