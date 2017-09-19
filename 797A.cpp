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

void factor(vector<ull>& f, ull n) {
	vector<bool> nums(n, true);
	for(ull i = 2; i*i <= n; ++i) {
		if(nums[i]) {
			if(n % i == 0) {
				while(n % i == 0) {
					f.push_back(i);
					n /= i;
				}
			}
			for(ull j = i; j*j < n; j += i) {
				nums[j] = false;
			}
		}
	}
	if(n != 1) f.push_back(n);
}

int main() {
    ull n, k;
    vector<ull> f;
    cin >> n >> k;
    factor(f, n);
    if(k > f.size()) {
    	cout << -1 << endl;
    } else {
    	int s = 0;
    	while(f.size() - s > k) {
    		f[s+1] *= f[s];
    		++s;
    	}
    	REP(i, k) cout << f[s+i] << " ";
    	cout << endl;
    }

    return 0;
}