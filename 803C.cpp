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
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
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
    ull n, k;
    cin >> n >> k;
    ull kh = k*(k+1)/2;
    if(k > 141420 || n < kh) {
    	cout << -1 << endl;
    } else {
    	vector<ull> s;
    	ull g = 1;
    	for(int i = 1; i*i <= n; ++i) {
    		if(n % i == 0) {
    			if(i >= kh) {
    				g = n/i;
    				break;
    			}
    			if(n/i >= kh) g = i;
    		}
    	}
    	n /= g;
		while(n != 0) {
    		ull m = k*(k-1)/2;
    		s.push_back(n-m);
    		n = m;
    		--k;
    	}
    	FORD(i, s.size()-1, 0) cout << g*s[i] << " ";
    	cout << endl;
    }

    return 0;
}