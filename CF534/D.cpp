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
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// #define int long long
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
bool findrange = true;
ll lo = 1, hi;

void input() {
	string s;
	cin >> s;
	if(s != "start") exit(0);
}

bool response() {
	char c;
	cin >> c;
	if(c == 'e') exit(0);
	return c != 'x'; // 0 for x, 1 for y
}

void guess(ll x, ll y) {
	cout << "? " << x << ' ' << y << endl;
}

void answer(ll x) {
	cout << "! " << max(1LL, x) << endl;
}

bool check(ll x) {
	x = max(1LL, x);
	cout << "? " << 0 << ' ' << x << endl;
	return !response();
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    input();
    while(1) {
    	if(findrange) {
    		guess(lo, 2*lo);
    		int res = response();
    		if(res) lo *= 2;
    		else {
    			findrange = false;
    			hi = lo;
    			lo = lo/2+1;
    		}
    	} else {
    		while(lo < hi) {
    			ll mid = (lo+hi)/2;
    			guess(mid, 2*mid);
    			int res = response();
    			if(res) lo = mid+1;
    			else hi = mid;
    		}
    		FOR(i, 2*lo-1, 2*lo) {
    			if(check(i)) {
    				answer(i);
	    			input();
	    			findrange = true;
					lo = 1;
					break;
				}
    		}
    	}
    }

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
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
