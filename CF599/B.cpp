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

set<int> a[200020];
vector<int> z;
int n, m;
set<int> s;

int dfs(int i) {
	int sz = 1;
	for (set<int>::iterator it = s.begin(); it != s.end(); ) {
		if (a[i].count(*it) == 0) {
			int x = *it;
			s.erase(x);
			sz += dfs(x);
			it = s.lower_bound(x);
		} else {
			it++;
		}
	}
	return sz;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].insert(y);
		a[y].insert(x);
	}
	for (int i = 1; i <= n; i++) {
		s.insert(i);
	}
	while (s.size()) {
		int x = *s.begin();
		s.erase(x);
		z.push_back(dfs(x));
	}
	sort(z.begin(), z.end());
	printf("%d\n", z.size()-1);
	
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
