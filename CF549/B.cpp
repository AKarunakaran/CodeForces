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

const int N = 2e5+10;

int ts[N], te[N], lcat = 0;
vector<int> g[N], ba[N];

void lcadfs(int s, int p = 0, int d = 0) {
	ts[s] = lcat++;
	ba[s].push_back(p);
	for(int i = 1; d - (1 << i) >= 0; ++i)
		ba[s].push_back(ba[ba[s][i-1]][i-1]);

	for(int v : g[s])
		if(v != p)
			lcadfs(v, s, d+1);
	te[s] = lcat++;
}

int n, m, q, p[N], a[N], ear[N], leaf[N], b[N];
set<pii> segs;
stack<int> lastids[N];

int jump_forward(int k) {
	int num = n-1;
	FOR(i, 0, 20) {
		if((1 << i) & num) {
			if(i < ba[k].size()) k = ba[k][i];
			else return 0;
		}
	}
	return k;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> q;
    FOR(i, 1, n) cin >> p[i];
    b[p[1]] = p[n];
    FOR(i, 2, n) b[p[i]] = p[i-1];
    FOR(i, 1, m) cin >> a[i];

    FOR(i, 1, m) {
    	int bef = b[a[i]];
    	stack<int>& s = lastids[bef];
    	while(!s.empty()) {
    		g[i].push_back(s.top());
    		leaf[s.top()] = 1;
    		s.pop();
    	}
    	lastids[a[i]].push(i);
    }
    FOR(i, 1, m) if(!leaf[i]) lcadfs(i);
    FOR(i, 1, m) ear[i] = jump_forward(i);
    
    FOR(i, 1, m) {
    	if(ear[i]) {
	    	while(segs.size() && segs.rbegin()->second >= ear[i]) segs.erase(*segs.rbegin());
	    	segs.insert({i, ear[i]});
    	}
    }

    while(q--) {
    	int l, r;
    	cin >> l >> r;
    	auto itr = segs.lower_bound({l, 0});
    	cout << !(itr == segs.end() || itr->second > r);
    }
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

