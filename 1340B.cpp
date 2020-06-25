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

const int N = 2e3+10;

vector<string> digits = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int n, k, m = 7, dp[N][N], num[N];
vector<pii> have[N];
string s[N], opt[N];

void get_have(int id) {
	string& cur = s[id];
	auto& res = have[id];
	REP(j, 10) {
		int cost = 0;
		auto& d = digits[j];
		bool good = true;
		REP(i, m) {
			if(d[i] == '0' && cur[i] == '1') {
				good = false;
				break;
			}
			if(d[i] == '1' && cur[i] == '0') {
				++cost;
			}
		}
		if(good) res.push_back({j, cost});
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    FOR(i, 1, n) {
    	cin >> s[i];
    	get_have(i);
    }
    dp[0][0] = 1;
    FOR(i, 1, n) {
    	FORD(j, k, 0) {
    		string add = " ";
    		bool hadz = false;
    		for(auto [num, cost] : have[i]) {
    			if(cost > j) continue;
    			if(cost == 0) {
    				hadz = true;
    			} else if(hadz) {
    				//
    			}
    			if(dp[i-1][j-cost] && opt[j-cost] >= opt[j]) {
    				dp[i][j] = 1;
    				opt[j] = opt[j-cost];
    				add[0] = '0'+num;
    			}
    		}
    		if(dp[i][j])opt[j] += add;
    		else opt[j] = "";
    	}
    }
    FOR(i, 1, n) {
    	FOR(j, 0, k) cout << dp[i][j] << ' ';
    	cout << endl;
    }
    cout << (opt[k] == "" ? to_string(-1) : opt[k]) << endl;

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
