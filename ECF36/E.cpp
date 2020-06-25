#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

set<pii> wint;
int working;

void addWork(int l, int r) {
	//find out if merge with left
	auto itr = wint.lower_bound({l, 0});
	if(itr != wint.begin()) {
		--itr;
		if(itr->second >= r) return;
		while(itr != wint.begin() && itr->second >= l-1) {
			l = min(l, itr->first);
			auto er = itr--;
			working -= (er->second-er->first+1);
			wint.erase(er);
		}
		if(itr == wint.begin() && itr->second >= l-1) {
			l = min(l, itr->first);
			working -= (itr->second-itr->first+1);
			wint.erase(itr);
		}
	}

	//find out if merge with right
	itr = wint.lower_bound({l, 0});
	while(itr != wint.end() && itr->first <= r+1) {
		r = max(r, itr->second);
		auto er = itr++;
		working -= (er->second-er->first+1);
		wint.erase(er);
	}

	working += (r-l+1);
	wint.insert({l, r});
}

void removeWork(int l, int r) {
	//remove on left
	auto itr = wint.lower_bound({l, 0});
	if(itr != wint.begin()) {
		--itr;
		if(itr->second >= r) {
			pii newInt1 = {itr->first, l-1}, newInt2 = {0, 0};
			if(itr->second > r) {
				newInt2 = {r+1, itr->second};
			}
			wint.erase(itr);
			wint.insert(newInt1);
			if(newInt2.first != 0) wint.insert(newInt2);
			working -= (r-l+1);
			return;
		}
		while(itr != wint.begin() && itr->first >= l) {
			auto er = itr--;
			working -= (er->second-er->first+1);
			wint.erase(er);
		}
		if(itr == wint.begin() && itr->first >= l) {
			working -= (itr->second - itr->first + 1);
			wint.erase(itr);
		} else if(itr->second >= l) {
			pii newInt1 = {itr->first, l-1};
			working -= (itr->second - itr->first + 1);
			working += (l-itr->first);
			wint.erase(itr);
			wint.insert(newInt1);
		}
	}

	itr = wint.lower_bound({l, 0});
	if(itr != wint.end()) {
		while(itr != wint.end() && itr->second <= r) {
			auto er = itr++;
			working -= (er->second - er->first + 1);
			wint.erase(er);
		}
		if(itr != wint.end() && itr->first <= r) {
			pii newInt = {r+1, itr->second};
			working -= (itr->second - itr->first + 1);
			working += (itr->second - r);
			wint.erase(itr);
			wint.insert(newInt);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, q;
    cin >> n >> q;
    working = n;
    wint.insert({1, n});
    REP(i, q) {
    	// for(auto p : wint) {
    	// 	cout << "{" << p.first << ", " << p.second << "}, ";
    	// }
    	// cout << endl;

    	int l, r, k;
    	cin >> l >> r >> k;
    	if(k == 1) removeWork(l, r);
    	else addWork(l, r);
    	cout << working << endl;
    }

    return 0;
}