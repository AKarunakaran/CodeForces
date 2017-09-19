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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m;
    cin >> n >> m;
    int minE = 1, maxE = n;
    REP(i, m) {
    	//DEBUG(minE);
    	//DEBUG(maxE);
    	int k, f;
    	cin >> k >> f;
    	if(minE*f < k) {
    		minE = ceil((double)k/(double)f);
    	}
    	if(maxE*(f-1)+1 > k) {
    		maxE = (k-1)/(f-1);
    	}
    }
    //DEBUG(minE);
    //DEBUG(maxE);
    if(ceil((double)n/(double)minE) != ceil((double)n/(double)maxE)) {
    	cout << -1 << endl;
    	exit(0);
    } else {
    	cout << ceil((double)n/(double)minE) << endl;
    }

    return 0;
}