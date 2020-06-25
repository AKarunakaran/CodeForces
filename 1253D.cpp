#include <bits/stdc++.h>
using namespace std;
// #define int long long
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

const int N = 2e5+10; // Upper bound for n

int parent[N], sz[N];

// Uses path compression
int find(int x) {return parent[x] = (x == parent[x] ? x : find(parent[x]));}

bool disjoint(int x, int y) {return find(x) != find(y);}

void join(int x, int y) {
	if(!disjoint(x, y)) return;
	int newPar = find(x), newChild = find(y);
	sz[newPar] += sz[newChild];
	parent[newChild] = newPar;
}

int dsuSize(int x) {return sz[find(x)];}

int n, m, last[N], first[N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    std::iota(parent, parent+N, 0), std::fill(sz, sz+N, 1);
    cin >> n >> m;
    REP(i, m) {
    	int u, v;
    	cin >> u >> v;
    	join(u, v);
    }
    FOR(i, 1, n) {
    	if(first[find(i)] == 0) first[find(i)] = i;
    	last[find(i)] = i;
    }
    int ans = 0, open = 0, cur = 0;

    FOR(i, 1, n) {
    	if(i == first[find(i)]) {
    		++open;
    		++cur;
    	}
    	if(i == last[find(i)]) {
    		--open;
    		if(open == 0) {
    			ans += cur-1;
    			cur = 0;
    		}
    	}
    }
    cout << ans << endl;

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
