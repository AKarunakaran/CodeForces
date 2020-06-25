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

const int N = 1e6;
int n, a[N], f[N], hi = 0;
pii ans1, ans2, c = {0, 0};

void bad() {
	cout << -1 << endl;
	exit(0);
}

void good() {
	cout << ans1.first << ' ' << ans1.second << endl;
	cout << ans2.first << ' ' << ans2.second << endl;
	exit(0);
}

int expec(int k) {
	return k ? 4*k : 1;
}

void trycap1(int k) {
	//
}


int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(f, f+N, 0);
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) {
    	++f[a[i]];
    	hi = max(hi, a[i]);
    }
    FOR(i, 0, hi) {
    	int e = expec(i);
    	if(f[i] != e) {
    		if(i == 0) bad();
    		if(e-f[i] < 0 || e-f[i] > 4) bad();
    		if(e-f[i] == 1) {
    			trycap1(i);
    		} else if(e-f[i] == 2) {
    			trycap2_1(i);
    			trycap2_2(i);
    		} else if(e-f[i] == 3) {
    			trycap3(i);
    		} else {
    			trycap4(i);
    		}
    	}
    }
    bad();

    return 0;
}