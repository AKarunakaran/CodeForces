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
    int n, m;
    cin >> n >> m;
    vector<int> w1, w2, w3;
    int w, c;
    REP(i, n) {
    	cin >> w >> c;
    	switch(w) {
    		case 1:
    			w1.push_back(c);
    			break;
    		case 2:
    			w2.push_back(c);
    			break;
    		case 3:
    			w3.push_back(c);
    			break;
    	}
    }
    sort(w1.begin(), w1.end(), [](auto &left, auto &right){return left > right;});
    sort(w2.begin(), w2.end(), [](auto &left, auto &right){return left > right;});
    sort(w3.begin(), w3.end(), [](auto &left, auto &right){return left > right;});
    /*
    REP(i, w1.size()) cout << w1[i] << " ";
    cout << endl;
    REP(i, w2.size()) cout << w2[i] << " ";
    cout << endl;
    REP(i, w3.size()) cout << w3[i] << " ";
    cout << endl;
    */
    vector<int> p1(w1.size()+1, 0), p2(w2.size()+1, 0), p3(w3.size()+1, 0);
    FOR(i, 1, p1.size()-1) p1[i] = p1[i-1] + w1[i-1];
    FOR(i, 1, p2.size()-1) p2[i] = p2[i-1] + w2[i-1];
    FOR(i, 1, p3.size()-1) p3[i] = p3[i-1] + w3[i-1];
    int ans = 0;
    REP(i, p3.size()) {
    	int r = m-3*i;
    	if(r < 0) break;
    	int j = min<int>(w2.size(), r/2);
    	int k = 0;
    	while(j >= 0) {
    		while(k + 2*j + 3*i <= m && k < p1.size()) {
    			//DEBUG(i);
    			//DEBUG(j);
    			//DEBUG(k);
    			ans = max(ans, p3[i] + p2[j] + p1[k]);
    			++k;
    		}
    		--j;
    	}
    }
    cout << ans << endl;

    return 0;
}