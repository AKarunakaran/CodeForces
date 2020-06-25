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

const int N = 1e5+10;

int t, m, a[N];
string s;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> s >> m;
    	REP(i, m) cin >> a[i];
    	vector<int> b(m, 0);
    	string ans(m, ' ');
    	queue<int> nxt;
    	vector<int> vis(m, 0), d(m, m+1);
    	map<char, int> cnt, dcnt;
    	REP(i, s.size()) cnt[s[i]]++;
    	REP(i, m) {
    		if(b[i] == a[i]) {
    			nxt.push(i);
    			vis[i] = 1;
    			d[i] = 0;
    			++dcnt[d[i]];
    		}
    	}
    	map<int, char> chars;
    	while(!nxt.empty()) {
    		int cur = nxt.front();
    		nxt.pop();
    		if(chars.count(d[cur]) == 0) {
    			// assign new char to this distance
    			while(cnt.rbegin()->second < dcnt[d[cur]]) cnt.erase(cnt.rbegin()->first);
    			chars[d[cur]] = cnt.rbegin()->first;
    			cnt.erase(cnt.rbegin()->first);
    		}
    		ans[cur] = chars[d[cur]];
    		bool good = nxt.empty();
    		REP(i, m) {
    			if(!vis[i]) {
    				b[i] += abs(i-cur);
    				if(good && b[i] == a[i]) {
    					nxt.push(i);
    					vis[i] = 1;
    					d[i] = d[cur]+1;
    					++dcnt[d[i]];
    				}
    			}
    		}
    	}
    	cout << ans << endl;
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
// - negative arithmetic, ceiling division, modulo (WA)
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
