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

const int N = 2e5+10;

vector<int> g[N];
int n, m, k, d1[N], dn[N], a[N], ans;
pii ds[N];

void bfs(int src, int* d) {
	vector<int> vis(n+1, 0);
	queue<int> nxt;
	d[src] = 0;
	vis[src] = 1;
	nxt.push(src);
	while(!nxt.empty()) {
		int cur = nxt.front();
		nxt.pop();
		for(int v : g[cur]) {
			if(!vis[v]) {
				nxt.push(v);
				vis[v] = 1;
				d[v] = d[cur]+1;
			}
		}
	}
}

void maxmize_point_coordinates() {
	int cur = 0;
	sort(ds, ds+k, [](pii left, pii right){return left.first > right.first;});
	cur = max(cur, min(ds[0].first+ds[1].second, ds[0].second+ds[1].first)+1);
	sort(ds, ds+k, [](pii left, pii right){return left.second > right.second;});
	cur = max(cur, min(ds[0].first+ds[1].second, ds[0].second+ds[1].first)+1);
	ans = min(ans, cur);
}

signed main() {x
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> k;
    REP(i, k) cin >> a[i];
    REP(_, m) {
    	int x, y;
    	cin >> x >> y;
    	g[x].push_back(y);
    	g[y].push_back(x);
    }
    bfs(1, d1);
    bfs(n, dn);
    // FOR(i, 1, n) cout << d1[i] << ' ';
    // cout<< endl;
    // FOR(i, 1, n) cout << dn[i] << ' ';
    // cout<< endl;
    ans = d1[n];
    REP(i, k) ds[i] = {d1[a[i]], dn[a[i]]};
    maxmize_point_coordinates();
    cout << ans << endl;

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
