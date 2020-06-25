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
#define int long long
const int K = 20, N = 5010*20, M = 1 << 20;
int k, n, bs[K], ts, rsum, colors[N], have[K], vis[N], dp[M], opt[M], c[K], p[K], curm;
vector<int> g[N], vals, path;
map<int, int> bm, idm; // maps VALUES to boxes and ids
map<int, vector<int>> cycles;

void get_answer(int mask) {
	if(!mask) return;
	int cur = opt[mask];
	auto& v = cycles[cur];
	REP(j, v.size()) {
		int i = v[j];
		c[colors[i]] = vals[i];
		p[colors[i]] = colors[v[(j+1)%v.size()]]+1;
	}
	get_answer(mask ^ cur);
}

void dfs(int s) {
	if(vis[s]) {
		vector<int> vec;
		REP(i, path.size()) {
			if(path[i] == s) {
				FOR(j, i, path.size()-1) vec.push_back(path[j]);
				break;
			}
		}
		cycles[curm] = vec;
		return;
	}
	if(have[colors[s]]) return;
	have[colors[s]] = true;
	curm ^= (1 << colors[s]);
	vis[s] = 1;
	path.push_back(s);
	
	for(int v : g[s]) {
		dfs(v);
	}

	path.pop_back();
	curm ^= (1 << colors[s]);
	vis[s] = 0;
	have[colors[s]] = false;
}

bool rec(int mask) {
	int& memo = dp[mask];
	if(memo != -1) return memo;
	if(mask == 0) return memo = true;
	for(auto& pr : cycles) {
		if((pr.first & mask) == pr.first) {
			if(rec(mask ^ pr.first)) {
				opt[mask] = pr.first;
				return memo = true;
			}
		}
	}
	return memo = false;
}

void bad() {
	cout << "No" << endl;
	exit(0);
}

string binary(int x) {
	string s;
	while(x) {
		if(x & 1) s.push_back('1');
		else s.push_back('0');
		x >>= 1;
	}
	reverse(s.begin(), s.end());
	return s;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(dp, -1, sizeof(dp));
    cin >> k;
    REP(i, k) {
    	int ni;
    	cin >> ni;
    	REP(j, ni) {
    		int x;
    		cin >> x;
    		bm[x] = i;
    		idm[x] = n;
    		vals.push_back(x);
    		colors[n] = i;
    		bs[i] += x;
    		ts += x;
    		++n;
    	}
    }
    if(ts % k != 0) bad();
    rsum = ts/k;
    REP(i, n) {
    	int cur = vals[i];
    	int box = bm[cur];
    	int delta = rsum-bs[box];
    	if(delta == 0 || (idm.count(cur+delta) && bm[cur+delta] != box)) {
    		int need = cur+delta;
    		int need_box = colors[need];
    		int need_id = idm[need];
    		g[need_id].push_back(i);
    	}
    }
    REP(i, n) dfs(i);
    int mask = (1 << k)-1;
    if(rec(mask)) {
    	get_answer(mask);
    	cout << "Yes" << endl;
    	REP(i, k) cout << c[i] << ' ' << p[i] << endl;
    } else bad();

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
