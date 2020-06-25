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

const ll N = 101, M = 1e8, K = 11;
ll w, r, k1, k2, dpw[N][N][K], dpr[N][N][K];

ll add(ll a, ll b) {return (a+b) % M;}

ll rec(int wh, int re, int con, bool pwh) {
	ll* memo;
	if(pwh) memo = &dpw[wh][re][con];
	else memo = &dpr[wh][re][con];
	if(pwh && con > wh) return *memo = 0;
	if(!pwh && con > re) return *memo = 0;
	if(wh == 1 && re == 0) {
		if(con == 1) return *memo = 1;
		else return *memo = 0;
	}
	if(wh == 0 && re == 1) {
		if(con == 1) return *memo = 1;
		else return *memo = 0;
	}
	if(*memo != -1) return *memo;
	ll res = 0;
	if(con > 1) {
		if(pwh) res = add(res, rec(wh-1, re, con-1, pwh));
		else res = add(res, rec(wh, re-1, con-1, pwh));
	} else {
		if(pwh) FOR(i, 1, k2) res = add(res, rec(wh-1, re, i, !pwh));
		else FOR(i, 1, k1) res = add(res, rec(wh, re-1, i, !pwh));
	}
	return *memo = res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    REP(i, N) REP(j, N) REP(k, K) dpw[i][j][k] = dpr[i][j][k] = -1;
    cin >> w >> r >> k1 >> k2;
    ll s = 0;
    FOR(i, 1, k1) s = add(s, rec(w, r, i, 1));
    FOR(i, 1, k2) s = add(s, rec(w, r, i, 0));
    cout << s << endl;

    return 0;
}