#include <iostream>
#include <iomanip>
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
#include <cstdio>
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

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int a, b, l, r;
    cin >> a >> b >> l >> r;
    bool lA, rA;
    --l;
    --r;
    lA = (l % (a+b) < a);
    rA = (r % (a+b) < a);
    if(lA && rA) {
    	if(l/(a+b) == r/(a+b)) {
    		cout << r-l+1 << endl;
    	} else {
    		if(b >= a) {
    			cout << a+1 << endl;
    		} else {
    			cout << 2*a-b << endl;
    		}
    	}
    } else if(!lA && !rA) {
    	if(l/(a+b) == r/(a+b)) {
    		cout << 1 << endl;
    	} else {
    		cout << a+1 << endl;
    	}
    } else if(!lA && rA) {
    	if(b >= a) {
			cout << a-(r%(a+b))+1 << endl;
		} else {
			cout << 2*a-b << endl;
		}
    } else if(lA && !rA) {
    	if(l/(a+b) == r/(a+b)) {
    		cout << a-(l%(a+b)) << endl;
    	} else {
    		if(b >= a) {
    			cout << a+1 << endl;
    		} else {
    			cout << 2*a-b << endl;
    		}
    	}
    }

    return 0;
}