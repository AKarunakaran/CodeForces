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

int n, m, a[N], bit[N];
pii qlist[N], vid[N];
map<int, vector<int>> id;
map<pii, int> ans;
unordered_set<int> qs[N];

int getSum(int i) {
    int sum = 0;
    ++i;
    while(i > 0) {
        sum += bit[i];
        i -= i & (-i);
    }
    return sum;
}

//assumes global n, ADDS val to i
void updateBIT(int i, int val) {
    ++i;
    while(i <= n) {
       bit[i] += val;
       i += i & (-i);
    }
}

int find(int id) {
	int l = 0, r = n-1;
	while(l < r) {
		int mid = (l+r)/2;
		if(getSum(mid) >= id) r = mid;
		else l = mid+1;
	}
	// DEBUG(l);
	return l;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) {
    	cin >> a[i];
    	id[a[i]].push_back(i);
    	vid[i] = {a[i], i};
    }
    sort(vid, vid+n, [](auto& left, auto& right){return left.first > right.first || (left.first == right.first && left.second < right.second);});
    // REP(i, n) cout << vid[i].first << ' ' << vid[i].second << "  ";
    // cout << endl;
    cin >> m;
    REP(i, m) {
    	int k, pos;
    	cin >> k >> pos;
    	qs[k].insert(pos);
    	qlist[i] = {k, pos};
    }
    REP(i, n) {
    	int val = vid[i].first, id = vid[i].second;
    	updateBIT(id, 1);
    	for(int x : qs[i+1]) ans[{i+1, x}] = a[find(x)];
    }
    REP(i, m) cout << ans[qlist[i]] << endl;

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
