#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
// const int INF = 0x3f3f3f3f;
// const int nINF = 1<<31;

/////////////////////////////////////////////////////////////////////


const int N = 1e3+10;
int n, a[N], p1 = 1, p2 = 2;

int query(int t, int x, int y, int z) {
	int res;
	cout << t << ' ' << x << ' ' << y << ' ' << z << endl;
	cin >> res;
	return res;
}

int signed_area(int v) {
	return query(1, p1, p2, v)*query(2, p1, p2, v);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    int mp = -1, mn = -1;
    vector<int> pos, neg;
    FOR(i, 3, n) {
    	a[i] = signed_area(i);
    	if(a[i] > 0) {
    		pos.push_back(i);
    		if(mp == -1 || a[i] > a[mp]) mp = i;
    	} else {
    		neg.push_back(i);
    		if(mn == -1 || a[i] < a[mn]) mn = i;
    	}
    }
    vector<pii> pu, pd, nu, nd;

 //    cout << "pos: ";
 //    for(int v : pos) cout << v << ' ';
 //    cout << endl;
	// for(int v : pos) cout << a[v] << ' ';
 //    cout << endl;

	// cout << "neg: ";
 //    for(int v : neg) cout << v << ' ';
 //    cout << endl;
	// for(int v : neg) cout << a[v] << ' ';
 //    cout << endl;

    for(int v : pos) {
    	if(v == mp) continue;
    	if(query(2, p2, mp, v) > 0) {
    		pd.push_back({a[v], v});
    	} else {
    		pu.push_back({a[v], v});
    	}
    }
    for(int v : neg) {
    	if(v == mn) continue;
    	if(query(2, p1, mn, v) > 0) {
    		nd.push_back({a[v], v});
    	} else {
    		nu.push_back({a[v], v});
    	}
    }

 //    cout << mp << ' ' << mn << endl;

 //    cout << "pu: ";
 //    for(auto [d, v] : pu) cout << v << ' ';
 //    cout << endl;
	// cout << "pd: ";
	// for(auto [d, v] : pd) cout << v << ' ';
 //    cout << endl;

	// cout << "nu: ";
 //    for(auto [d, v] : nu) cout << v << ' ';
 //    cout << endl;
	// cout << "nd: ";
	// for(auto [d, v] : nd) cout << v << ' ';
 //    cout << endl;

    sort(pu.begin(), pu.end());
    sort(pd.begin(), pd.end(), greater{});
    sort(nu.begin(), nu.end(), greater{});
    sort(nd.begin(), nd.end());

    vector<int> ans;
    ans.push_back(p2);
    for(auto&[d, v] : pu) ans.push_back(v);
    if(mp != -1) ans.push_back(mp);
    for(auto&[d, v] : pd) ans.push_back(v);
    ans.push_back(p1);
    for(auto&[d, v] : nu) ans.push_back(v);
    if(mn != -1) ans.push_back(mn);
    for(auto&[d, v] : nd) ans.push_back(v);
    
    int s = 0;
	REP(i, ans.size()) {
		if(ans[i] == 1) {
			s = i;
			break;
		}
	}
	rotate(ans.begin(), ans.begin()+s, ans.end());
	cout << 0 << ' ';
	for(int x : ans) cout << x << ' ';
	cout << endl;

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
