#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline int msbp(int x) {return 31-__builtin_clz(x);}
inline int msb(int x) {return 1 << msbp(x);}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 2e3+10, M = 1e9+7;

ll add(ll a, ll b) {return (a+b)%M;}
ll sub(ll a, ll b) {return (a+M-b)%M;}
ll mult(ll a, ll b) {return (a*b)%M;}
ll fastPowMod(ll base, ll power) {
    if(power == 0) return 1;
    if(power & 1) return mult(base, fastPowMod(base, power-1));
    return fastPowMod(mult(base, base), power/2);
}
ll divd(ll a, ll b) {return mult(a, fastPowMod(b, M-2));}

int n, m, q, vis[N], MAGIC;
ll ans;
pair<pii, int> e[N];
pll lines[N];
vector<ll> dist, old;

void answer() {
	cout << ans << endl;
	exit(0);
}

ll sgn(ll x) {return x > 0 ? 1 : x < 0 ? -1 : 0;}

ll ceil(ll x, ll y) {
    if(sgn(x) != sgn(y)) return -1;
    else {
        x = abs(x), y = abs(y);
    }
    return (x+y-1)/y;
}

ll get_intersection_time(int i, int j) {
	// same or parallel is null
	if(lines[i].second == lines[j].second) return -1;
	ll a_0 = lines[i].first, b_0 = lines[i].second, a_1 = lines[j].first, b_1 = lines[j].second;
	return ceil(a_1-a_0, b_0-b_1);
}

// add all line[id] values from [t1, t2)
void add_line(int id, int t1, int t2) {
	t1 -= MAGIC, t2 -= MAGIC;
	ll a = lines[id].first, b = lines[id].second;
	// ((t2-t1)*(2*a+b*(t1+t2-1)))/2
	ans = add(ans, divd(mult(sub(t2, t1), add(mult(2, a), mult(b, sub(add(t1, t2), 1)))), 2));
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> q;
    MAGIC = 2*m;
    REP(i, m) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	e[i] = {{u, v}, w};
    }
    dist.resize(n+1, -1);
    old.resize(n+1, -1);
    dist[1] = 0;
    REP(i, MAGIC) {
    	old.swap(dist);
    	fill(dist.begin(), dist.end(), -1);
    	REP(j, m) {
    		int u = e[j].first.first, v = e[j].first.second, w = e[j].second;
    		if(old[u] != -1) dist[v] = max(dist[v], old[u] + w);
    		if(old[v] != -1) dist[u] = max(dist[u], old[v] + w);
    	}
    	ll hi = 0;
    	FOR(i, 1, n) hi = max(hi, dist[i]);
    	ans = add(ans, hi);
    	if(i+1 == q) answer();
    }
    //dist[i] now contains lengths of longest paths from 1 to i that have exactly MAGIC edges
   	int id = 0;
    REP(i, m) {
    	// for each edge ((u, v), w), we define a line d = max(dist[u], dist[v]) + w*t
    	int u = e[i].first.first, v = e[i].first.second, w = e[i].second;
    	lines[i] = {max(dist[u], dist[v]), w};
    	if(lines[i].first > lines[id].first || (lines[i].first == lines[id].first && lines[i].second > lines[id].second)) id = i;
    }

    // FOR(i, 1, n) cout << dist[i] << ' ';
    // cout << endl;
    // REP(i, m) cout << lines[i].first << ' ' << lines[i].second << "  ";
    // cout << endl;

    int t = MAGIC+1; // keep going until t = q+1
    REP(i, m) {
    	// we start at line[id], and we iterate over all unvisited lines to find next one to visit
    	// if next one happens before q, add all in between and update t
    	// otherwise, add up to q and break
    	// DEBUG(t);
    	if(t == q+1) break;
    	int nxt = q+1, nxt_id = -1;
    	// cout << id << ' ' << t << endl;
    	REP(j, m) {
			ll it = get_intersection_time(id, j)+MAGIC;
			// DEBUG(it);
			if(it <= t) continue;
			if(it < nxt || (it == nxt && (nxt_id == -1 || lines[j].second > lines[nxt_id].second))) {
				nxt = it;
				nxt_id = j;
			}
    	}

    	add_line(id, t, nxt);

    	t = nxt;
    	id = nxt_id;
    }
    // DEBUG(t);
    answer();

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE) CHECK IF IT SHOULD BE 2*N!!!!
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
// - not clearing DS between test cases EVEN FOR INPUT (WA, RTE, TLE, MLE)
