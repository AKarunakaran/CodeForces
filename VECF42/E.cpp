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
typedef pair<ll, char> pic;

/////////////////////////////////////////////////////////////////////
const ll N = 2e5+10;
ll n, ans = 0, np = 0;
vector<pic> r, b;

void full() {
	ll rs = r.size(),  bs = b.size();
	REP(i, rs-1) ans += r[i+1].first-r[i].first;
	REP(i, bs-1) ans += b[i+1].first-b[i].first;
	cout << ans << endl;
	exit(0);
}

void first(ll rl, ll bl) {
	FOR(i, 0, rl-1) ans += r[i+1].first-r[i].first;
	FOR(i, 0, bl-1) ans += b[i+1].first-b[i].first;
}

void last(ll rr, ll br) {
	ll rs = r.size(), bs = b.size();
	FORD(i, rs-1, rr+1) ans += r[i].first-r[i-1].first;
	FORD(i, bs-1, br+1) ans += b[i].first-b[i-1].first;
}

void next(ll& rl, ll& rr, ll& bl, ll& br) {
	rl = rr, bl = br;
	++rr, ++br;
	while(r[rr].second != 'P') ++rr;
	while(b[br].second != 'P') ++br;
}

void solveMid(ll rl, ll rr, ll bl, ll br) {
	// DEBUG(rl);
	// DEBUG(rr);
	// DEBUG(bl);
	// DEBUG(br);
	ll ans1 = 0, ans2 = 0, bm = 0, rm = 0;
	ans1 += r[rr].first-r[rl].first;
	FOR(i, rl, rr-1) {
		rm = max(rm, r[i+1].first-r[i].first);
		ans2 += r[i+1].first-r[i].first;
	}
	FOR(i, bl, br-1) {
		bm = max(bm, b[i+1].first-b[i].first);
		ans2 += b[i+1].first-b[i].first;
	}
	ans1 += ans2-bm-rm;
	if(rl == rr-1 || bl == br-1) ans += ans1;
	else ans += min(ans1, ans2);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) {
    	ll x;
    	char p;
    	cin >> x >> p;
    	np += p == 'P';
    	if(p != 'B') r.push_back({x, p});
    	if(p != 'R') b.push_back({x, p});
    }
    if(np < 2) full();
    ll rl = 0, bl = 0, rr, br;
    while(r[rl].second != 'P') ++rl;
    while(b[bl].second != 'P') ++bl;
    rr = rl, br = bl;
    first(rl, bl);
    // DEBUG(ans);
    REP(repeat, np-1) {
    	next(rl, rr, bl, br);
    	solveMid(rl, rr, bl, br);
	    // DEBUG(ans);
    }
    last(rr, br);
    // DEBUG(ans);
    cout << ans << endl;

    return 0;
}