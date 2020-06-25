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

pii s1[4], s2[4];
int hl, hh, vl, vh;
pair<double, double> cent;
int r;

void good() {
	cout << "YES" << endl;
	exit(0);
}

bool insq(pii p) {
	return p.first <= vh && p.first >= vl && p.second >= hl && p.second <= hh;
}

bool indi(pii p) {
	return abs(p.first-cent.first)+abs(p.second-cent.second) <= r;
}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(7);
    REP(i, 4) cin >> s1[i].first >> s1[i].second;
    REP(i, 4) cin >> s2[i].first >> s2[i].second;
    hl = min(s1[0].second, s1[2].second);
    hh = max(s1[0].second, s1[2].second);
    vl = min(s1[0].first, s1[2].first);
    vh = max(s1[0].first, s1[2].first);
    int tc = 0, bc = INF, lc = INF, rc = 0;
    REP(i, 4) {
    	tc = max(s2[i].second, tc);
    	bc = min(s2[i].second, bc);
    	lc = min(s2[i].first, lc);
    	rc = max(s2[i].first, rc);
    }
    REP(i, 4) {
    	REP(j, 4) {
    		if(s1[i] == s2[j]) good();
    	}
    }
	cent = {(lc+rc)/(double)2, (tc+bc)/(double)2};
	r = cent.first-lc;
	for(int x = vl; x <= vh; ++x) {
		if(indi({x, hl}) || indi({x, hh})) good();
	}
	for(int y = hl; y <= hh; ++y) {
		if(indi({vl, y}) || indi({vh, y})) good();
	}
	for(int i = 0; i <= r; ++i) {
		if(insq({lc+i, tc-r+i})) good();
		if(insq({lc+i, bc+r-i})) good();
		if(insq({rc-i, tc-r+i})) good();
		if(insq({rc-i, bc+r-i})) good();
	}

	cout << "NO" << endl;

    return 0;
}