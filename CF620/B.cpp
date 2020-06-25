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

const int N = 110;

int n, m;
string s[N];
set<string> strs;

bool is_palindrome(string& str) {
	string rev = str;
	reverse(rev.begin(), rev.end());
	return rev == str;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    REP(i, n) {
    	cin >> s[i];
    	strs.insert(s[i]);
    }
    string ans, mid;
    REP(i, n) {
    	if(is_palindrome(s[i])) {
    		if(s[i].size() > mid.size()) mid = s[i];
    	} else {
    		string rev = s[i];
    		reverse(rev.begin(), rev.end());
    		if(strs.count(rev)) {
    			ans += s[i];
    			strs.erase(rev);
    			strs.erase(s[i]);
    		}
    	}
    }
    string rev = ans;
    reverse(rev.begin(), rev.end());
    cout << ans.size()*2+mid.size() << endl;
    cout << ans << mid << rev << endl;

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
