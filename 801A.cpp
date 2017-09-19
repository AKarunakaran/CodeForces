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
    string s;
    cin >> s;
    if(s.size() == 1) {
    	cout << 0 << endl;
    	return 0;
    }
    if(s.size() == 2) {
    	if(s[0] == 'K' && s[1] == 'V') cout << 0 << endl;
    	else cout << 1 << endl;
    	return 0;
    }
    int c = (s[0] == 'V' && s[1] == 'K') ? 1 : 0;
    bool trip = (s[0] == 'K' && s[1] == 'K') || (s.back() == 'V' && s[s.size()-2] == 'V');
    FOR(i, 1, s.size()-2) {
    	trip = trip || (s[i] == s[i-1] && s[i] == s[i+1]);
    	if(s[i] == 'V' && s[i+1] == 'K') ++c;
    }
    cout << c + trip << endl;

    return 0;
}