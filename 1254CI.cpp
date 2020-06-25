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

int sign(int x) {
	return x > 0 ? 1 : -1;
}

int cross(pii x, pii y, pii z, pii w) {
	pii p = {y.first-x.first, y.second-x.second};
	pii q = {w.first-z.first, w.second-z.second};
	return p.first*q.second-p.second*q.first;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    vector<pii> v = {{-2, 1},
    				 {3, -1},
    				 {-2, -1},
    				 {1, -2},
    				 {0, 3},
    				 {2, 2}};
    int t, x, y, z;
   	while(cin >> t >> x >> y >> z) {
   		--x, --y, --z;
   		int c = cross(v[x], v[y], v[x], v[z]);
   		if(t == 1) {
   			cout << abs(c) << endl;
   		} else {
   			cout << sign(c) << endl;
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
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
