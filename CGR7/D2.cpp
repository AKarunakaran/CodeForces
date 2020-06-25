#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 1e5+10;

/**
 * Author: User adamant on CodeForces
 * Source: http://codeforces.com/blog/entry/12143
 * Description: For each position in a string, computes p[0][i] = half length of
 *  longest even palindrome around pos i, p[1][i] = longest odd (half rounded down).
 * Time: O(N)
 * Status: Stress-tested
 */
 // even center is left of index
array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}

string s;
int n, t, k;

int len(pii p) {
	int mid = p.second;
	if(p.first) {
		int l1 = mid, l2 = k-1-mid;
		return 2*min(l1, l2)+1;
	} else {
		int l1 = mid, l2 = k-mid;
		return 2*min(l1, l2);
	}
}

string extract_string(int offset, pii p) {
	int mid = p.second;
	if(p.first) {
		int l1 = mid, l2 = k-1-mid;
		int hl = min(l1, l2);
		return s.substr(offset+mid-hl, 2*hl+1);
	} else {
		int l1 = mid, l2 = k-mid;
		int hl = min(l1, l2);
		return s.substr(offset+mid-hl, 2*hl);
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> s;
    	n = s.size();
    	int freeid = 0;
    	while(freeid < n/2 && s[freeid] == s[n-1-freeid]) ++freeid;
    	string half = s.substr(0, freeid);
    	string rhalf = half;
    	reverse(rhalf.begin(), rhalf.end());
    	string ans;
    	int l = freeid, r = n-1-freeid;
    	k = r-l+1;
    	if(2*freeid < n) {
    		pii bestid = {1, 0};
    		auto p = manacher(s.substr(l, r-l+1));
    		// FOR(i, l, r) {
    		// 	int pid = i-l;
    		// 	cout << p[0][pid] << ' ';
    		// }
    		// cout << endl;
    		// FOR(i, l, r) {
    		// 	int pid = i-l;
    		// 	cout << p[1][pid] << ' ';
    		// }
    		// cout << endl;
    		FOR(i, l, r) {
    			int pid = i-l;

    			// check for prefix
    			if(p[0][pid] == pid && len({0, pid}) > len(bestid)) bestid = {0, pid};
    			if(p[1][pid] == pid && len({1, pid}) > len(bestid)) bestid = {1, pid};

    			// check for suffix
    			if(pid+p[0][pid] == k && len({0, pid}) > len(bestid)) bestid = {0, pid};
    			if(pid+p[1][pid] == k-1 && len({1, pid}) > len(bestid)) bestid = {1, pid};
    		}
    		ans = extract_string(l, bestid);
    	}
    	cout << half + ans + rhalf << endl;
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
