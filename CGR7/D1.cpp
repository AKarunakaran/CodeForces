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

const int N = 1e5+10;

int n, t;
string s, best;

bool split_two(string a, string b, string c) {
	// DEBUG(a);
	// DEBUG(b);
	// DEBUG(c);
	int id = 0;
	while(id < a.size() && a[id] == b[id]) ++id;
	while(id < a.size() && a[id] == c[id]) ++id;
	return id == a.size();
}

void try_center_odd(int mid) {
	int len = mid;
	if(len*2+1 > n) return;	
	string half = s.substr(0, len);
	string rhalf = half;
	reverse(rhalf.begin(), rhalf.end());
	// cout << s << ' ' << half << ' ' << len << endl;
	if(split_two(rhalf, s.substr(mid+1, len), s.substr(n-len, len)) && 2*len+1 > best.size()) {
		best = half;
		best.push_back(s[mid]);
		best += rhalf;
	}
}

// center is after index mid
void try_center_even(int mid) {
	int len = mid+1;
	if(len*2 > n) return;
	string half = s.substr(0, len);
	string rhalf = half;
	reverse(rhalf.begin(), rhalf.end());
	// cout << s << ' ' << half << ' ' << len << endl;
	if(split_two(rhalf, s.substr(mid+1, len), s.substr(n-(len), len)) && 2*len > best.size()) {
		best = half;
		best += rhalf;
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> s;
    	best = "";
    	n = s.size();
    	FOR(i, 0, n/2) try_center_odd(i);
    	if(n > 1) FOR(i, 0, n/2) try_center_even(i);
    	reverse(s.begin(), s.end());
    	FOR(i, 0, n/2) try_center_odd(i);
    	if(n > 1) FOR(i, 0, n/2) try_center_even(i);
    	cout << best << endl;
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
