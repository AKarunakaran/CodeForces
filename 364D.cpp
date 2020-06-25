#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int nINF = 1<<31;

/////////////////////////////////////////////////////////////////////

ll randll() {
	ll res = rand();
	res <<= 32;
	return res | rand();
}

// [l, r]
ll randrangell(ll l, ll r) { return (randll() % (r-l+1)) + l; }

// [l, r]
int randrange(int l, int r) { return (rand() % (r-l+1)) + l; }

// [l, r)
double frandrange(double l, double r) { return (rand() / ((double)(RAND_MAX)+1))*(r-l) + l;}

const int N = 1e6+10;
int n;
ll a[N];

int main() {
	srand(time(NULL));
    ios::sync_with_stdio(false);
    //
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> a[i];
    set<ll> poss;
    REP(_, 5) {
    	int id = rand() % n;
    	ll cur = a[id];
    	for(ll i = 1; i*i <= cur; ++i) {
    		if(cur % i == 0) {
    			poss.insert(i);
    			poss.insert(cur/i);
    		}
    	}
    }
    ll ans = 1;
    for(ll x : poss) {
    	int cnt = 0;
    	REP(i, n) if(a[i] % x == 0) ++cnt;
    	if(cnt >= (n+1)/2) ans = x;
    }
    cout << ans << endl;

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
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
