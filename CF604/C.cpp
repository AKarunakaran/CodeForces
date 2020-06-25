#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;

/////////////////////////////////////////////////////////////////////

const int hinv = 828542813;
const int M = 998244353;

// Finds constants {u, v} s.t. a*u+b*v = g for g = gcd(a, b)
// Call with egcd(a, b)
pii egcd(int a, int b, pii x = {1, 0}, pii y = {0, 1}) {
	return (b == 0) ? x : egcd(b, a % b, y, {x.first - a/b * y.first, x.second - a/b * y.second});
}

// Finds x s.t. (a*x) % n == 1
// Assumes a is not zero divdisor (i.e. gcd(a, n) == 1)
int modInv(int a, int n) {
	return ((egcd(a, n).first % n) + n) % n;
}

ll add(ll a, ll b) {return (a+b)%M;}
ll sub(ll a, ll b) {return (a+M-b)%M;}
ll mult(ll a, ll b) {return (a*b)%M;}
ll divd(ll a, ll b) {return mult(a, modInv(b, M));}

const int N = 2e5+10;
int n, q, p[N], prod[N], sp[N], door[N], num[N], den[N], ans; // prod[i] is product from 1..i, sp[i] is the weird sum of products from 1..i
set<int> s; // checkpoints

// [l, r] product
int seg_prod(int l, int r) {return divd(prod[r], prod[l-1]);}
int answer(int l, int r) {return divd(divd(sub(sp[r-1], l == 1 ? 0 : sp[l-2]), prod[l-1]), seg_prod(l, r));}

void remove_door(int l, int r, int u) {
	// cout << "rem " << l << ' ' << u << ' ' << r << endl;
	door[u] = 0;
	s.erase(u);
	ans = sub(ans, answer(l, u-1));
	ans = sub(ans, answer(u, r-1));
	ans = add(ans, answer(l, r-1));
}

void add_door(int l, int r, int u) {
	// cout << "add " << l << ' ' << u << ' ' << r << endl;
	door[u] = 1;
	s.insert(u);
	ans = sub(ans, answer(l, r-1));
	ans = add(ans, answer(l, u-1));
	ans = add(ans, answer(u, r-1));
}


signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> q;
    FOR(i, 1, n) {
    	cin >> p[i];
    	p[i] = mult(p[i], hinv);
    }
    s.insert(1);
    s.insert(n+1);
    prod[0] = 1, sp[0] = 1;
    FOR(i, 1, n) {
    	prod[i] = mult(p[i], prod[i-1]);
    	sp[i] = add(prod[i], sp[i-1]);
    }
    ans = answer(1, n);
    // DEBUG(ans);
    while(q--) {
    	int u, l, r;
    	cin >> u;
    	if(door[u]) {
    		auto itr = s.lower_bound(u);
    		++itr;
    		r = *itr;
    		--itr, --itr;
    		l = *itr;
    		remove_door(l, r, u);
    	} else {
    		auto itr = s.lower_bound(u);
    		r = *itr;
    		--itr;
    		l = *itr;
    		add_door(l, r, u);
    	}
    	cout << ans << endl;
    }

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - divdision by 0 (WA)
// - integer divdision (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
