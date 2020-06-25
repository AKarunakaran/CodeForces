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
// #define int long long
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

const int N = 1 << 20, K = 30;
int n, k, a[N], b[N], q, m, side[K];
ll l[K], ml[K];

void merge(int left, int right, int level, int* a,ll* inv) {
	if(!level) return;
	int mid = (left+right)/2;

	merge(left, mid, level-1, a, inv);
	merge(mid+1, right, level-1, a, inv);

	vector<int> vec(right-left+1);
	int id1 = left, id2 = mid+1, id = 0;
	while(id1 <= mid || id2 <= right) {
		if(id1 > mid) {
			vec[id++] = a[id2++];
		} else if(id2 > right) {
			vec[id++] = a[id1++];
		} else if(a[id1] <= a[id2]) {
			vec[id++] = a[id1++];
		} else {
			inv[level] += mid+1-id1;
			vec[id++] = a[id2++];
		}
	}
	FOR(i, left, right) {
		id = i-left;
		a[i] = vec[id];
	}
}

void preprocess(int *a, ll *inv) {
	merge(0, n-1, k, a, inv);
	// FOR(i, 1, k) inv[i] += inv[i-1];
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    scanf("%d", &k);
    n = 1 << k;
    REP(i, n) scanf("%d", a+i);
    REP(i, n) b[i] = a[i];
    preprocess(a, l);
    reverse(b, b+n);
    preprocess(b, ml);
    // FOR(i, 0, k) printf("%lld ", l[i]);
    // printf("\n");
    // FOR(i, 0, k) printf("%lld ", ml[i]);
    // printf("\n");
    scanf("%d", &q);
    while(q--) {
    	scanf("%d", &m);
    	FORD(i, m, 0) side[i] ^= 1;
    	ll ans = 0;
    	FOR(i, 0, k) ans += (side[i] ? ml[i] : l[i]);
    	printf("%I64d\n", ans);
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
