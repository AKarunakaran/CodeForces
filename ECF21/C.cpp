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
    int n, w;
    cin >> n >> w;
    vector<pair<int, pair<int, int> > > a(n);
    REP(i, n) {
    	cin >> a[i].first;
    	a[i].second.first = i;
    }
    sort(a.begin(), a.end());
    REP(i, n) {
    	if(w < 0) {
    		break;
    	}
    	a[i].second.second = a[i].first/2 + (a[i].first%2);
    	w -= a[i].first/2 + (a[i].first%2);
    }
    if(w < 0) {
    	cout << -1 << endl;
    } else {
    	FORD(i, n-1, 0) {
    		if(w == 0) break;
    		int p = min(a[i].first - a[i].second.second, w);
    		a[i].second.second += p;
    		w -= p;
    	}
    	if(w > 0) {
    		cout << -1 << endl;
    	} else {
    		sort(a.begin(), a.end(), [](auto &left, auto &right) {return left.second.first < right.second.first;});
	    	REP(i, n) {
	    		cout << a[i].second.second << " ";
	    	}
	    	cout << endl;
    	}
    }

    return 0;
}