#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int nINF = 1<<31;

/////////////////////////////////////////////////////////////////////

struct pt {
	int d[3];
};

const int N = 50010;
int n;
pair<pt, int> p[N];
vector<pii> ans;

int solve(int cd, int l, int r) {
	int len = r-l+1;
	if(cd == 2) {
		REP(i, len/2)
			ans.push_back({p[l+2*i].second, p[l+2*i+1].second});
		return len & 1 ? p[r].second : -1;
	} else {
		int last = l, lastpr = -1;
		FOR(i, l, r) {
			if(p[i].first.d[cd] != p[last].first.d[cd]) {
				int curid = solve(cd+1, last, i-1);
				if(curid != -1) {
					if(lastpr == -1) lastpr = curid;
					else {
						ans.push_back({lastpr, curid});
						lastpr = -1;
					}
				}
				last = i;
			}
		}
		int curid = solve(cd+1, last, r);
		if(curid == -1 && lastpr == -1) return -1;
		else if(curid == -1 && lastpr != -1) return lastpr;
		else if(curid != -1 && lastpr == -1) return curid;
		else {
			ans.push_back({curid, lastpr});
			return -1;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) {
    	cin >> p[i].first.d[0] >> p[i].first.d[1] >> p[i].first.d[2];
    	p[i].second = i+1;
    }
    sort(p, p+n, [&](auto& left, auto& right){
    	return left.first.d[0] < right.first.d[0] || (left.first.d[0] == right.first.d[0] && (left.first.d[1] < right.first.d[1] || (left.first.d[1] == right.first.d[1] && left.first.d[2] < right.first.d[2])));
    });
    
    solve(0, 0, n-1);

    for(auto& pr : ans) cout << pr.first << ' ' << pr.second << endl;

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
