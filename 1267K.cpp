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
ll k;
map<multiset<unsigned char>, ll> memo;

void solve() {
	// cout << "------------------------" << endl;
	// DEBUG(k);
	unordered_map<ll, vector<multiset<unsigned char>>> m, othm;
	unordered_map<ll, vector<multiset<unsigned char>>> *curp = &m, *nxtp = &othm;
	multiset<unsigned char> ms;
	FOR(i, 2, 20) {
		if(k == 0) break;
		ms.insert(k % i);
		k /= i;
	}
	if(memo.count(ms)) {
		cout << memo[ms] << endl;
		return;
	}
	int num = ms.size();
	m[0].push_back(ms);
	// for(int x : ms) cout << x << ' ';
	// cout << endl;
	FORD(r, num+1, 2) {
		auto& cur = *curp;
		auto& nxt = *nxtp;

		for(auto& [x, s] : cur) {
			// DEBUG(x);
			for(auto& curms : s) {
				unsigned char last = 100;
				for(auto y : curms) {
					// cout << (int)y << ' ';
					if(y >= r || (y == 0 && x == 0) || y == last) continue;
					multiset<unsigned char> othms = curms;
					othms.erase(othms.find(y));
					nxt[x*r + y].push_back(othms);
					last = y;
				}
				// cout << endl;
			}
		}

		cur.clear();
		swap(curp, nxtp);
	}

	memo[ms] = curp->size()-1;
	cout << curp->size()-1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> k;
    	solve();
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
