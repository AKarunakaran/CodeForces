#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline int msbp(int x) {return 31-__builtin_clz(x);}
inline int msb(int x) {return 1 << msbp(x);}
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 2e3+10, K = 30;

int tn, cs[N][K], ct[N][K];
string s, t;

int rec(int i, int j, vector<vector<int>>& dp) {
	int& memo = dp[i][j];
	if(memo != INF) return memo;
	if(i == 0) return memo = 0;
	char c = t[j];
	int cid = c-'a';
	int res = 2001;
	if(cs[i+1][cid] > ct[j+1][cid]) res = min(res, rec(i, j-1, dp));
	if(s[i] == t[j]) res = min(res, rec(i-1, j-1, dp));
	res = min(res, 1+rec(i-1, j, dp));
	return memo = res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> tn;
    while(tn--) {
    	int n;
    	cin >> n;
    	cin >> s >> t;
    	if(multiset<char>(s.begin(), s.end()) != multiset<char>(t.begin(), t.end())) {
    		cout << -1 << endl;
    		continue;
    	}
    	n = 0;
    	FORD(i, s.size()-1, 0) {
    		if(s[i] != t[i]) {
    			n = i+1;
    			break;
    		}
    	}
    	s.resize(n); t.resize(n);
    	s = " " + s, t = " " + t;
    	REP(i, 26) cs[n+1][i] = ct[n+1][i] = 0;
    	FORD(i, n, 1) {
    		REP(j, 26) {
    			cs[i][j] = cs[i+1][j]+(s[i] == 'a'+j);
    			ct[i][j] = ct[i+1][j]+(t[i] == 'a'+j);
    		}
    	}
    	vector<vector<int>> dp(n+1, vector<int>(n+1, INF));
    	cout << rec(n, n, dp) << endl;
    	// FOR(i, 0, n) {
    	// 	FOR(j, 0, i-1) cout << "   ";
    	// 	FOR(j, i, n) cout << (dp[i][j] == INF ? -1 : dp[i][j]) << ' ';
    	// 	cout << endl;
    	// }
    }

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
// - not clearing DS between test cases EVEN FOR INPUT (WA, RTE, TLE, MLE)
