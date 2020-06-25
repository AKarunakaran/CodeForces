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

const int N = 667;
int x, y, q, nq[5];
pii rooks[N], center = {500, 500};

void move(int nx, int ny) {
	bool good = true;
	FOR(i, 1, N-1) if(rooks[i] == (pii){nx, ny}) good = false;
	if(!good) nx = x;
	cout << nx << ' ' << ny << endl;
	x = nx, y = ny;
}

void read() {
	int k, nx, ny;
	cin >> k >> nx >> ny;
	if(k <= 0) exit(0);
	rooks[k] = {nx, ny};
}

int sign(int num) {return num > 0 ? 1 : (num < 0 ? -1 : 0);}

void findq() {
	FOR(i, 1, 4) nq[i] = 666;
	FOR(i, 1, N-1) {
		pii cur = rooks[i];
		if(cur.first < center.first && cur.second < center.second) --nq[1];
		if(cur.first > center.first && cur.second < center.second) --nq[2];
		if(cur.first > center.first && cur.second > center.second) --nq[3];
		if(cur.first < center.first && cur.second > center.second) --nq[4];
	}
	q = 1;
	FOR(i, 1, 4) if(nq[i] > nq[q]) q = i;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> x >> y;
    FOR(i, 1, N-1) cin >> rooks[i].first >> rooks[i].second;
    bool march = true;
    while(1) {
		if(march && (pii){x, y} == center) {
			march = false;
			findq();
		}
    	if(march) {
    		int dx = sign(center.first - x), dy = sign(center.second - y);
    		move(x+dx, y+dy);
    		read();
    	} else {
    		if(q == 1) move(x+1, y+1);
    		else if(q == 2) move(x-1, y+1);
    		else if(q == 3) move(x-1, y-1);
    		else move(x+1, y-1);
    		read();
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
