#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int nINF = 1<<31;

/////////////////////////////////////////////////////////////////////

int sign(int x) {return x > 0 ? 1 : -1;}

const int N = 1e5;
int n, a[N], can[N];

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> a[i];
    int extra = 0;
    REP(i, n) {
    	if(abs(a[i] % 2) == 1) can[i] = 1;
    	a[i] /= 2;
    	extra += a[i];
    }
    REP(i, n) {
    	if(extra == 0) break;
    	if(!can[i]) continue;
    	if(a[i] > 0 && extra < 0) {
    		++a[i];
    		++extra;
    	} else if(a[i] < 0 && extra > 0) {
    		--a[i];
    		--extra;
    	}
    }
    REP(i, n) cout << a[i] << endl;

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
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
