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
    int n, k, s = 0;
    cin >> n >> k;
    int one = 0, two = 2*n, four = n;
    vector<int> a(k);
    REP(i, k) {
    	cin >> a[i];
    }
    REP(i, k) {
    	if(!four) break;
    	while(a[i] >= 4  && four) {
    		a[i] -= 4;
    		--four;
    	}
    }
    if(four) {
    	REP(i, k) {
    		if(!four) break;
    		if(a[i] % 2 == 1) {
    			a[i] -= 1;
    			--four;
    			++two;
    		}
    	}
    }
    if(four) {
    	REP(i, k) {
    		if(!four) break;
    		if(a[i]) {
    			a[i] -= 2;
    			--four;
    			++one;
    		}
    	}
    }
    REP(i, k) {
    	if(!two) break;
    	while(a[i] >= 2 && two) {
    		a[i] -= 2;
    		--two;
    	}
    }
    REP(i, k) {
    	if(!one) break;
    	while(a[i] >= 1 && one) {
    		a[i] -= 1;
    		--one;
    	}
    }
    REP(i, k) {
    	if(!two) break;
    	while(a[i] >= 1 && two) {
    		a[i] -= 1;
    		--two;
    	}
    }
    //DEBUG(one);
    //DEBUG(two);
    //DEBUG(four);
    bool good = true;
    REP(i, k) {
    	//DEBUG(a[i]);
    	if(a[i]) {
    		good = false;
    		break;
    	}
    }
    cout << (good ? "YES" : "NO") << endl;

    return 0;
}