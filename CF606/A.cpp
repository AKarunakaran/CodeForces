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

int t;
string s;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> s;
    	int n = s.size();
    	vector<int> ans;
    	REP(i, n-2) {
    		// DEBUG(i);
    		// DEBUG(s.substr(i, 3));
    		if(s.substr(i, 5) == "twone") {
    			ans.push_back(i+2);
    			i += 4;
    		} else if(s.substr(i, 3) == "one") {
    			ans.push_back(i+1);
    			i += 2;
    		} else if(s.substr(i, 3) == "two") {
    			ans.push_back(i+1);
    			i += 2;
    		}
    	}
    	cout << ans.size() << endl;
    	for(int x : ans) cout << x+1 << ' ';
    	cout << endl;
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
