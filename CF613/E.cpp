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

int t, n, inc[N];
pii seg[N];
pair<int, pii> ev[2*N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> n;
    	REP(i, n) {
    		cin >> seg[i].first >> seg[i].second;
    		ev[2*i] = {seg[i].first, {0, i}};
    		ev[2*i+1] = {seg[i].second, {1, i}};
    	}
    	int en = 2*n;
    	sort(ev, ev+en);
    	ev[en] = {5*n, {-1, -1}};
    	set<int> s;

    	REP(i, en) {
    		// Do adds first, check if going 1+
    		// Do erases, check if going down to 1
    		if(ev[i].second.first == 0) {
                if(s.size() == 1) inc[*s.begin()]++;
                s.insert(ev[i].second.second);
            } else s.erase(ev[i].second.second);
    	}

        sort(seg, seg+n);
        int md = 0;
        pii cur = seg[0];
        int ans = 0;

        REP(i, n) {
            md = max(md, inc[i]);
            if(seg[i].first > cur.second) {
                ++ans;
                cur = seg[i];
            } else {
                cur.second = max(cur.second, seg[i].second);
            }
        }
        if(seg[n-1].first > cur.second) ++ans;

        cout << ans-md << endl;
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
