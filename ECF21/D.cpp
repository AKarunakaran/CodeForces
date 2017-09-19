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
#include <unordered_map>
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
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, vector<int> > h;
    REP(i, n) cin >> a[i];
    REP(i, n) h[a[i]].push_back(i);
    ll ps = 0, ss = 0;
    REP(i, n) ss += a[i];
    bool lbig;
    int d;
    FOR(i, 0, n-2) {
    	ps += a[i];
    	ss -= a[i];
    	DEBUG(ps);
    	DEBUG(ss);
    	if(ps == ss) {
    		cout << "YES" << endl;
    		return 0;
    	} else {
    		lbig = ((ps - ss) > 0);
	    	if(lbig) {
	    		d = ps - ss;
	    		if(d % 2) continue;
	    		d /= 2;
	    		if(h.find(d) != h.end()) {
	    			REP(j, h[d].size()) {
	    				if(h[d][j] <= i) {
	    					cout << "YES" << endl;
	    					return 0;
	    				}
	    			}
	    		}
	    		/*
	    		d += a[i+1];
	    		if(h.find(d) != h.end()) {
	    			REP(j, h[d].size()) {
	    				if(h[d][j] <= i) {
	    					cout << "YES" << endl;
	    					return 0;
	    				}
	    			}
	    		}
	    		*/
	    	} else {
	    		d = ss - ps;
	    		if(d % 2) continue;
	    		d /= 2;
	    		if(h.find(d) != h.end()) {
	    			REP(j, h[d].size()) {
	    				if(h[d][j] > i) {
	    					cout << "YES" << endl;
	    					return 0;
	    				}
	    			}
	    		}
	    		/*
	    		d += a[i];
	    		if(h.find(d) != h.end()) {
	    			REP(j, h[d].size()) {
	    				if(h[d][j] > i) {
	    					cout << "YES" << endl;
	    					return 0;
	    				}
	    			}
	    		}
	    		*/
	    	}
    	}
    }
    cout << "NO" << endl;

    return 0;
}