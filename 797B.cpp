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
const int INF = (((1<<30) - 1)<<1)+1;
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
    int n, s = 0, mo = nINF;
    cin >> n;
    vector<int> a(n);
    vector<int> o;
    REP(i, n) cin >> a[i];
    REP(i, n) {
    	if(a[i] > 0) {
    		if(a[i] % 2 == 0) s += a[i];
    		else o.push_back(a[i]);
    	} else {
    		if(a[i] % 2 && a[i] > mo) mo = a[i];
    	}
    }
    sort(o.begin(), o.end());
    int i = 0;
    if(o.size() > 0) {
    	if(o.size() % 2 == 0) {
	    	i = 1;
	    	if(o[0] + mo > 0) {
	    		s += o[0] + mo;
	    	}
	    }
	    while(i < o.size()) s += o[i++];
    } else {
    	s += mo;
    }
    cout << s << endl;

    return 0;
}