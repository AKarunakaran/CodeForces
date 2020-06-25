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

int n, k;
string s;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int t;
    cin >> t;
    while(t--) {
    	cin >> n >> k >> s;
    	s = " " + s;
    	int big = (n - (k-1)*2)/2;
    	// DEBUG(big);
    	bool open = false;
    	vector<pii> ans;
    	FOR(i, 1, n) {
    		char look;
    		if(k > 1) {
    			if(open) {
    				look = ')';
					open = false;
					--k;
				}
				else {
					look = '(';
					open = true;
				}
    		} else {
    			if(i+big > n) look = ')';
				else look = '(';
    		}
    		FOR(j, i, n) {
    			if(s[j] == look) {
    				if(i != j) {
    					ans.push_back({i ,j});
	    				reverse(s.begin()+i, s.begin()+j+1);
    				}
    				break;
    			}
    		}
    	}
    	cout << ans.size() << endl;
    	for(auto[i, j] : ans) cout << i << ' ' << j << endl;
    	// cout << s.substr(1) << endl;
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
