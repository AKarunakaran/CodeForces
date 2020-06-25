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

const int N = 4e5+10;
int t, n, p[N];
map<int, int> m;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	m.clear();
    	cin >> n;
    	REP(i, n) {
    		cin >> p[i];
    		++m[p[i]];
    	}
    	int g = m.rbegin()->second;
    	m.erase(m.rbegin()->first);

    	int s = 0;
    	bool flag = false;
    	while(s <= g) {
    		if(m.empty()) {
    			flag = true;
    			break;
    		}
    		s += m.rbegin()->second;
    		m.erase(m.rbegin()->first);
    	}
    	if(flag) {
    		cout << "0 0 0" << endl;
    		continue;
    	}
    	
    	int b = 0;
    	flag = false;
    	while(1) {
    		if(m.empty()) {
    			flag = true;
    			break;
    		}
    		if(2*(b + s + g + m.rbegin()->second) > n)
    			break;
    		b += m.rbegin()->second;
    		m.erase(m.rbegin()->first);
    	}
    	if(flag || b <= g) {
    		cout << "0 0 0" << endl;
    		continue;
    	}

    	if(2*(g + s + b) > n) {
    		cout << "0 0 0" << endl;
    		continue;
    	} else {
    		cout << g << ' ' << s << ' ' << b << endl;
    		continue;
    	}
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
