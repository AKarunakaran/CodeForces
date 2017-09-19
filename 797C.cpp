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
    string s, t, u;
    cin >> s;
	int im = 0, c = 0, isrt = 0, ss = s.size();
	vector< pair<char, int> > srt(ss);
    REP(i, ss) srt[i] = {s[i], i};
    sort(srt.begin(), srt.end());
    while(u.size() != ss && isrt < ss) {
    	while(isrt < ss && srt[isrt].second < c) ++isrt;
    	if(isrt == ss) break;
    	im = srt[isrt].second;
    	while(!t.empty() && t.back() < s[im]) {
    		u.push_back(t.back());
    		t.pop_back();
    	}
    	FOR(i, c, im-1) t.push_back(s[i]);
    	u.push_back(s[im]);
    	c = ++im;
    }
    while(!t.empty()) {
    	u.push_back(t.back());
    	t.pop_back();
    }
    cout << u << endl;

    return 0;
}
/*
int main() {
    string s, t, u;
    cin >> s;
    int im = 0, c = 0, ss = s.size();
    while(u.size() != ss && c < ss) {
    	FOR(i, c, ss-1) if(s[i] < s[im]) im = i;
    	while(!t.empty() && t.back() < s[im]) {
    		u.push_back(t.back());
    		t.pop_back();
    	}
    	FOR(i, c, im-1) t.push_back(s[i]);
    	u.push_back(s[im]);
    	c = ++im;
    }
    while(!t.empty()) {
    	u.push_back(t.back());
    	t.pop_back();
    }
    cout << u << endl;

    return 0;
}
*/