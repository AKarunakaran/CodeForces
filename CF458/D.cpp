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

int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

const int N = 5e5;  // limit for array size
int n;  // array size
int t[2 * N];
int a[N];

void build() {  // build the tree
	FORD(i, n-1, 0) t[i] = gcd(t[i<<1], t[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = gcd(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = gcd(res, t[l++]);
		if (r&1) res = gcd(res, t[--r]);
	}
	return res;
}

bool isClose(int l, int r, int x) {
	if(r-l == 3) {
		int numDiv = 0;
		numDiv += (a[l] % x == 0);
		numDiv += (a[l+1] % x == 0);
		numDiv += (a[l+2] % x == 0);
		return numDiv >= 2;
	}
	if(r-l == 2) {
		int numDiv = 0;
		numDiv += (a[l] % x == 0);
		numDiv += (a[l+1] % x == 0);
		return numDiv >= 1;
	}
	if(r-l == 1) {
		return true;
	}
	int m = (l+r)/2;
	int g1 = query(l, m), g2 = query(m, r);
	if(g1 % x == 0 && g2 % x == 0) {
		return true;
	}
	if(g1 % x == 0) {
		return isClose(m, r, x);
	}
	if(g2 % x == 0) {
		return isClose(l, m, x);
	}
	return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    //cout << fixed << setprecision(7);
    int q;
    scanf("%d", &n);
    REP(i, n) scanf("%d", t+i+n);
    REP(i, n) a[i] = t[i+n];
    scanf("%d", &q);
    build();
    REP(i, q) {
    	int type;
    	scanf("%d", &type);
    	if(type == 1) {
    		int l, r, x;
    		scanf("%d %d %d", &l, &r, &x);
    		--l;
    		if(isClose(l, r, x)) printf("YES\n");
    		else printf("NO\n");
    	} else {
    		int idx, y;
    		scanf("%d %d", &idx, &y);
    		--idx;
    		a[idx] = y;
    		modify(idx, y);
    	}
    }
    fflush(stdout);

    return 0;
}