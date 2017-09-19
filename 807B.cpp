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
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }

/////////////////////////////////////////////////////////////////////

bool shirt(int s, int p) {
    int i = (s/50) % 475;
    REP(j, 25) {
        i = (i * 96 + 42) % 475;
        if(i + 26 == p) return true;
    }
    return false;
}

int main() {
    int p, x, y;
    cin >> p >> x >> y;
    for(int i = x; i >= y; i -= 50) {
        if(shirt(i, p)) {
            cout << 0 << endl;
            return 0;
        }
    }
    int sh = 0;
    while(!shirt(x, p)) {
        x += 50;
        ++sh;
    }
    cout << (sh+1)/2 << endl;

    return 0;
}