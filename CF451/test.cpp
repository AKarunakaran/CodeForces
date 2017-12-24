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
#include <ctime>
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n = 10000000;
    for(int a = 1; a <= n; ++a) {
    	for(int b = 1; b <= n; ++b) {
    		clock_t begin = clock();
		    bool ok = false;
		    int ansa, ansb;
		    for(int i = 0; !ok && i < n/a; ++i) {
		    	for(int j = 0; j < n/b; ++j) {
		    		if(a*i+b*j == n) {
		    			ok = true;
		    			ansa = i;
		    			ansb = j;
		    			break;
		    		}
		    	}
		    }
		    clock_t end = clock();
		    double el = (end-begin)/CLOCKS_PER_SEC;
		    if(el > 1.5) {
		    	cout << a << " " << b << " " << el << endl;
		    }
    	}
    }

    return 0;
}