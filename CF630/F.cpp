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
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 3e5+10, M = 998244353;

int add(int a, int b) {return (a+b)%M;}
int sub(int a, int b) {return (a+M-b)%M;}
int mult(ll a, ll b) {return (a*b)%M;}

int n, dp[N][3];
vector<int> g[N];

void dfs(int s, int p = 0) {
	dp[s][0] = dp[s][1] = dp[s][2] = 1;
	for(int v : g[s]) {
		if(v != p) {
			dfs(v, s);
			dp[s][0] = mult(dp[s][0], sub(mult(2, add(dp[v][0], dp[v][1])), dp[v][2]));
			dp[s][1] = mult(dp[s][1], sub(add(mult(2, dp[v][0]), dp[v][1]), dp[v][2]));
			dp[s][2] = mult(dp[s][2], sub(add(dp[v][0], dp[v][1]), dp[v][2]));
		}
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n-1) {
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(1);
    cout << sub(add(dp[1][0], dp[1][1]), add(dp[1][2], 1)) << endl;

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
