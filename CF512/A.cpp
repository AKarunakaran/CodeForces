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
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define int long long
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
int n, m, k;

void good(pii a, pii b, pii c = {0, 0}) {
	cout << "YES" <<< endl;
	cout << a.first << ' ' << a.second << endl;
	cout << b.first << ' ' << b.second << endl;
	cout << c.first << ' ' << c.second << endl;
	exit(0);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> k;
    if(2*n*m % k != 0) {
    	cout << "NO" << endl;
    	exit(0);
    }

    int num = 2*n*m/k;

    for(int i = 1; i*i <= num; ++i) {
    	if(k % i == 0) {
    		if(n*2 % i == 0 && m % (k/i) == 0) good();
    		if(m % i == 0 && n*2 % (k/i) == 0) good();
    		if(m*2 % i == 0 && n % (k/i) == 0) good();
    		if(n % i == 0 && m*2 % (k/i) == 0) good();
    	}
    }

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
