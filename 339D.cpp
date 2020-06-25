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

const int N = (1 << 18)-1;
int n, m, a[N], t;

int build(int k, int iter) {
	if(k >= t-1) return a[k];
	if(iter & 1) return a[k] = build((k << 1)+1, iter-1) | build((k << 1)+2, iter-1);
	else return a[k] = build((k << 1)+1, iter-1) ^ build((k << 1)+2, iter-1);
}

int sib(int k) {
	return ((k+1)^1)-1;
}

void update(int idx, int val, bool bor = true) {
	idx = t-1+idx;
	a[idx] = val;
	int par = (idx-1) >> 1;
	while(idx) {
		if(bor) a[par] = a[idx] | a[sib(idx)];
		else a[par] = a[idx] ^ a[sib(idx)];
		idx = par;
		par = (par-1) >> 1;
		bor = !bor;
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    t = 1 << n;
    REP(i, t) cin >> a[t-1+i];
    build(0, n);
    while(m--) {
    	int p, b;
    	cin >> p >> b;
    	--p;
    	update(p, b);
    	cout << a[0] << endl;
    }

    return 0;
}