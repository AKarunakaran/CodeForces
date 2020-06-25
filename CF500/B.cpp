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
#include <numeric>
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

const int N = 1e5+1;
int n, x, a[N], f[N];

void good(int k) {
	cout << k << endl;
	exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(f, 0, sizeof(f));
    cin >> n >> x;
    REP(i, n) cin >> a[i];
    REP(i, n) ++f[a[i]];
    REP(i, N) if(f[i] > 1) good(0);
    REP(i, n) {
    	int newa = a[i] & x;
    	if(newa != a[i]) {
    		if(f[newa] == 1) good(1);
    	}
    }
    memset(f, 0, sizeof(f));
    REP(i, n) a[i] &= x;
    REP(i, n) ++f[a[i]];
    REP(i, N) if(f[i] > 1) good(2);
    cout << -1 << endl;

    return 0;
}