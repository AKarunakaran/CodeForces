#include <bits/stdc++.h>
using namespace std;
#define int long long
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
int n, a[N], f[N], s[N], vp[N], hi;
map<int, int> m;
vector<int> vnums[N];
vector<vector<int>> ans;

void place(int num, int id, int h, int w) {
	int r = id % h, c = id/h;
	c += r;
	c %= w;
	ans[r][c] = num;
}

void answer() {
	int h = ans.size(), w = ans[0].size();
	REP(i, h) {
		REP(j, w) cout << ans[i][j] << ' ';
		cout << endl;
	}
	exit(0);
}

void solve(int h, int w) {
	cout << h*w << endl;
	cout << h << ' ' << w << endl;
	vector<pii> v;
	FORD(i, hi, 1) {
		for(int x : vnums[i])
			v.push_back({x, min(i, h)});
		vnums[i].clear();
	}
	ans.resize(h, vector<int>(w));
	int id = 0;
	for(auto& [num, freq] : v) {
		REP(i, freq) {
			place(num, id, h, w);
			++id;
			if(id == h*w) answer();
		}
	}
	answer();
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) {
    	cin >> a[i];
    	++m[a[i]];
    }

    vector<pii> v;
    for(auto& p : m) v.push_back({p.second, p.first});
    sort(v.begin(), v.end());

	for(auto& [freq, num] : v) {
		vnums[freq].push_back(num);
		++f[freq];
		hi = max(hi, freq);
	}
	int c = 1;
	while(c*c <= n) ++c;
	--c;

	FORD(i, max(hi, c), 1) s[i] = s[i+1] + f[i];
	FOR(i, 1, max(hi, c)) vp[i] = vp[i-1] + i * f[i];

	int besth = 0, bestw = 0;
	for(int i = 1; i*i <= n; ++i) {
		int tot = vp[i-1] + i * s[i];

		int h = i, w = tot/i;
		if(tot / i < i) continue;
		if(h * w > besth * bestw) {
			besth = h;
			bestw = w;
		}
	}

	solve(besth, bestw);

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
