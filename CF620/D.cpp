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

int t, n, a[N];
string s;

void print() {
	REP(i, n) cout << a[i] << ' ';
	cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> n >> s;
    	// Min length LIS
    	fill(a, a+n, 0);
    	int l = 1, r = n;
    	FORD(i, n-2, 0) {
    		if(s[i] == '<' && (i == 0 || s[i-1] != '<')) {
    			int j = i;
	    		for(; s[j] == '<'; ++j) {
	    			a[j] = l++;
	    		}
	    		if(j == n-1) a[j] = l++;
	    	}
    	}
    	REP(i, n) if(a[i] == 0) a[i] = r--;
    	print();

    	// Max length LIS
    	fill(a, a+n, 0);
    	l = 1, r = n;
    	REP(i, n-1) if(s[i] == '<') a[i] = l++;
    	REP(i, n) if(a[i] == 0) a[i] = r--;
    	print();
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
