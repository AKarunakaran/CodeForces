#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 2e5+10, M = 998244353;

int n, m, two[N];

int add(int a, int b) {return (a+b)%M;} 
int mult(int a, int b) {return (a*b)%M;} 

int fastPowMod(int base, int power) {
    int res = 1;
    while(power) {
        if(power & 1) res = mult(res, base);
        base = mult(base, base);
        power >>= 1;
    }
    return res;
}
int modInv(int x) {return fastPowMod(x, M-2);}

int choose(int a, int b) {
	int res = 1;
	FOR(i, 1, b) {
		res = mult(res, a+1-i);
		res = mult(res, modInv(i));
	}
	return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    two[0] = 1;
    FOR(i, 1, N-1) two[i] = mult(two[i-1], 2);
    cin >> n >> m;
    // (m choose n-2) * 2^{n-3}
    if(n == 2) {
    	cout << 0 << endl;
    	exit(0);
    }

    cout << mult(mult(two[n-3], choose(m, n-1)), n-2) << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE) CHECK IF IT SHOULD BE 2*N!!!!
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
