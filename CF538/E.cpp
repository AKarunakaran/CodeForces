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
#include <ctime>
#include <cstdlib>
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

int real_rand() {
	int b = rand() % 2;
	int x = rand();
	int y = rand();
	return ((b << 30) + (x << 15) + (y)) & INF;
}

// [l, r]
int randrange(int l, int r) { return (real_rand() % (r-l+1)) + l; }

int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

const int N = 1e6+10;
int n, have[N], lo, d;
vector<int> a;

void answer() {
	cout << "! " << lo << ' ' << d << endl;
	exit(0);
}

int query(int i) {
	int res;
	have[i] = 1;
	cout << "? " << i << endl;
	cin >> res;
	if(res == -1) exit(0);
	return res;
}

bool grtr(int x) {
	int res;
	cout << "> " << x << endl;
	cin >> res;
	if(res == -1) exit(0);
	return res;
}

void bf() {
	FOR(i, 1, n) a.push_back(query(i));
	sort(a.begin(), a.end());
	lo = a[0], d = a[1]-a[0];
	answer();
}

signed main() {
	srand(time(NULL));
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    if(n < 50) bf();
    REP(i, 30) {
    	int to_ask = randrange(1, n);
    	while(have[to_ask]) to_ask = randrange(1, n);
    	a.push_back(query(to_ask));
    }
    sort(a.begin(), a.end());
    REP(i, 30) FOR(j, i+1, 29) d = gcd(d, a[j]-a[i]);
    int l = a.back(), r = 1e9;
    while(l < r) {
    	int m = (l+r)/2;
    	if(grtr(m)) l = m+1;
    	else r = m;
    }
    lo = l-(n-1)*d;
    answer();

    return 0;
}

// Try 2
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

