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

int q, n, a[N], c[N];
bool rotated;

void all_same() {
	cout << 1 << endl;
	REP(i, n) cout << 1 << ' ';
	cout << endl;
}

void alternate() {
	cout << 2 << endl;
	REP(i, n) cout << 1+(i & 1) << ' ';
	cout << endl;
}

void alternate_end() {
	cout << 3 << endl;
	REP(i, n-1) cout << 1+(i & 1) << ' ';
	cout << 3 << endl;
}

void consecutive(bool rotated) {
	cout << 2 << endl;
	vector<int> output;
	bool alt = false;
	REP(i, n) {
		if(i && a[i] == a[i-1] && !alt) alt = true;
		output.push_back(alt ? 3 - (1 + (i & 1)) : (1 + (i & 1)));
	}
	if(rotated) {
		rotate(output.begin(), output.begin()+n-1, output.end());
	}
	for(int x : output) cout << x << ' ';
	cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> q;
    while(q--) {
    	cin >> n;
    	bool same = true;
    	bool consec = false;
    	rotated = false;
    	REP(i, n) {
    		cin >> a[i];
    		if(a[i] != a[0]) same = false;
    		if(i && a[i] == a[i-1]) consec = true;
    	}
    	if((n & 1) && !consec && a[n-1] == a[0]) {
    		rotate(a, a+1, a+n);
    		consec = true;
    		rotated = true;
    	}
    	if(same == 1) {
    		all_same();
    		continue;
    	} else if(n % 2 == 0) {
    		alternate();
    		continue;
    	} else if(consec) {
    		consecutive(rotated);
    		continue;
    	} else {
    		alternate_end();
    		continue;
    	}
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
