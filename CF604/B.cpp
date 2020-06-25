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

void bad() {
	cout << "NO" << endl;
	exit(0);
}

void answer(vector<int>& v) {
	cout << "YES" << endl;
	for(int x : v) cout << x << ' ';
	cout << endl;
	exit(0);
}

int n;

// zero first
void try0(int a, int b, int c, int d) {
	if(a == 0) return;
	vector<int> v;
	v.push_back(0);
	--a;
	REP(i, n-1) {
		int pre = v.back();
		if(pre == 0) {
			if(b == 0) return;
			v.push_back(1);
			--b;
		} else if(pre == 1) {
			if(a == 0 && c == 0) {
				return;
			} else if(a == 0) {
				v.push_back(2);
				--c;
			} else {
				v.push_back(0);
				--a;
			}
		} else if(pre == 2) {
			if(b == 0 && d == 0) {
				return;
			} else if(b == 0) {
				v.push_back(3);
				--d;
			} else {
				v.push_back(1);
				--b;
			}
		} else {
			if(c == 0) return;
			v.push_back(2);
			--c;
		}
	}
	answer(v);
}

// one first
void try1(int a, int b, int c, int d) {
	if(b == 0) return;
	vector<int> v;
	v.push_back(1);
	--b;
	REP(i, n-1) {
		int pre = v.back();
		if(pre == 0) {
			if(b == 0) return;
			v.push_back(1);
			--b;
		} else if(pre == 1) {
			if(a == 0 && c == 0) {
				return;
			} else if(a == 0) {
				v.push_back(2);
				--c;
			} else {
				v.push_back(0);
				--a;
			}
		} else if(pre == 2) {
			if(b == 0 && d == 0) {
				return;
			} else if(b == 0) {
				v.push_back(3);
				--d;
			} else {
				v.push_back(1);
				--b;
			}
		} else {
			if(c == 0) return;
			v.push_back(2);
			--c;
		}
	}
	answer(v);
}

// two first
void try2(int a, int b, int c, int d) {
	if(c == 0) return;
	vector<int> v;
	v.push_back(2);
	--c;
	REP(i, n-1) {
		int pre = v.back();
		if(pre == 0) {
			if(b == 0) return;
			v.push_back(1);
			--b;
		} else if(pre == 1) {
			if(a == 0 && c == 0) {
				return;
			} else if(c == 0) {
				v.push_back(0);
				--a;
			} else {
				v.push_back(2);
				--c;
			}
		} else if(pre == 2) {
			if(b == 0 && d == 0) {
				return;
			} else if(d == 0) {
				v.push_back(1);
				--b;
			} else {
				v.push_back(3);
				--d;
			}
		} else {
			if(c == 0) return;
			v.push_back(2);
			--c;
		}
	}
	answer(v);
}

// three first
void try3(int a, int b, int c, int d) {
	if(d == 0) return;
	vector<int> v;
	v.push_back(3);
	--d;
	REP(i, n-1) {
		int pre = v.back();
		if(pre == 0) {
			if(b == 0) return;
			v.push_back(1);
			--b;
		} else if(pre == 1) {
			if(a == 0 && c == 0) {
				return;
			} else if(c == 0) {
				v.push_back(0);
				--a;
			} else {
				v.push_back(2);
				--c;
			}
		} else if(pre == 2) {
			if(b == 0 && d == 0) {
				return;
			} else if(d == 0) {
				v.push_back(1);
				--b;
			} else {
				v.push_back(3);
				--d;
			}
		} else {
			if(c == 0) return;
			v.push_back(2);
			--c;
		}
	}
	answer(v);
}

int a, b, c, d;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> a >> b >> c >> d;
    n = a+b+c+d;
    try0(a, b, c, d);
    try1(a, b, c, d);
    try2(a, b, c, d);
    try3(a, b, c, d);
    bad();
    // if(a+c <= b-1 || b+d <= c-1 || a > b || d > c) bad();
    // cout << "YES" << endl;
    // if(a+c == b-1) {
    // 	//
    // } else if(b+d == c-1) {
    // 	//
    // } else {
    // 	REP(i, a) cout << "0 1 ";
    // 	REP(i, b-a) cout << "2 1 ";
    // }

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
