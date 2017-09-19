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
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

struct ticket {
	ll cost;
	int l;
	int r;
};

int duration(ticket& t) {
	return t.r-t.l+1;
}

bool intersect(ticket& t1, ticket& t2) {
	if(t1.l < t2.l) {
		return t2.l < t1.r;
	} else {
		return t1.l < t2.r;
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, x;
    ll ans = INF;
    cin >> n >> x;
    vector<ticket> ticks(n);
    REP(i, n) cin >> ticks[i].l >> ticks[i].r >> ticks[i].cost;
    
    //

    cout << ((ans == INF) ? -1 : ans) << endl;

    return 0;
}