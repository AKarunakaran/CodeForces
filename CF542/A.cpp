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
// const int INF = 0x3f3f3f3f3f3f3f3fLL;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 5010;
int n, m, ans[N], len[N], c[N];
vector<int> c[N];

int dist(int a, int b) {
	return (b >= a) ? b-a : (n-a)+b;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(len, len+N, N);
    cin >> n >> m;
    FOR(i, 1, m) {
    	int a, b;
    	cin >> a >> b;
    	c[a].push_back(b);
    	len[a] = min(len[a], dist(i, b));
    }

    FOR(i, 1, n) {
    	FOR(j, 1, n) {
    		if(c[j].size()) ans[i] = max(ans[i], ((int)c[j].size()-1)*n + dist(i, j) + len[j]);
    	}
    }

    FOR(i, 1, n) cout << ans[i] << ' ';
    cout << endl;

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

