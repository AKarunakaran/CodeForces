#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline int msbp(int x) {return 31-__builtin_clz(x);}
inline int msb(int x) {return 1 << msbp(x);}
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 5e5+10;

int n;
pii v[N];

int partner(int id) {return ((id-1)^1)+1;}
int get_neck(int id) {return ((id-1)/2)+1;}
int get_id(pii cur) {return 2*cur.first-1+cur.second;}
pii get_pii(int id) {
	pii res{get_neck(id), 0};
	if(partner(id) < id) res.second = 1;
	return res;
}

int parent[N], sz[N];

// Uses path compression
int find(int x) {return parent[x] = (x == parent[x] ? x : find(parent[x]));}

bool disjoint(int x, int y) {return find(x) != find(y);}

void join(int x, int y) {
	if (!disjoint(x, y)) return;
	int newPar = find(x), newChild = find(y);
	sz[newPar] += sz[newChild];
	parent[newChild] = newPar;
}

int dsuSize(int x) {return sz[find(x)];}

vector<int> get_cycle(int start, vector<int>& l, vector<int>& r) {
	vector<int> res(1, start);
	res.push_back(partner(start));
	int id = start;
	if(id > partner(id)) id = l[get_neck(id)];
	else id = r[get_neck(id)];
	while(id != start) {
		res.push_back(id);
		res.push_back(partner(id));

		if(id > partner(id)) id = l[get_neck(id)];
		else id = r[get_neck(id)];
	}
	return res;
}

bool check(int beauty, bool answer) {
	int hi = 1 << (beauty);
	vector<int> a(n+1), b(n+1), l(n+1), r(n+1), all(1);
	vector<vector<pii>> rm(hi);
	FOR(i, 1, n) {
		a[i] = v[i].first % hi;
		b[i] = v[i].second % hi;
		rm[a[i]].push_back({i, 0});
		rm[b[i]].push_back({i, 1});
		all.push_back(a[i]);
		all.push_back(b[i]);
	}

	REP(i, hi) {
		auto& cm = rm[i];
		if(cm.size() & 1) return false;
		for(int j = 0; j < cm.size(); j += 2) {
			auto cur = cm[j];
			auto nxt = cm[j+1];
			if(cur.second == 0) l[cur.first] = get_id(nxt);
			else r[cur.first] = get_id(nxt);

			if(nxt.second == 0) l[nxt.first] = get_id(cur);
			else r[nxt.first] = get_id(cur);
		}
	}

	int cycles = 0;
	vector<unordered_map<int, vector<int>>> ms;
	vector<int> cycle_map(2*n+1, -1);
	FOR(i, 1, 2*n) {
		if(cycle_map[i] != -1) continue;
		unordered_map<int, vector<int>> m;
		auto v = move(get_cycle(i, l, r));
		REP(j, v.size()) {
			int id = v[j];
			cycle_map[id] = cycles;
			if(j & 1) {
				// j and j+1 % sz are same, record in map
				auto& rv = m[all[id]];
				if(rv.size() == 0) {
					rv.push_back(v[j]);
					rv.push_back(v[(j+1)%v.size()]);
				}
			}
		}
		ms.emplace_back(m);
		++cycles;
	}

	std::iota(parent, parent+N, 0), std::fill(sz, sz+N, 1);
	REP(i, hi) {
		auto& cm = rm[i];
		if(cm.size() == 0) continue;
		auto cur = cm[0];
		FOR(j, 1, cm.size()-1) {
			auto nxt = cm[j];
			int cur_id = get_id(cur), nxt_id = get_id(nxt);
			int cur_cycle = cycle_map[cur_id], nxt_cycle = cycle_map[nxt_id];
			if(disjoint(cur_cycle, nxt_cycle)) {
				join(cur_cycle, nxt_cycle);
				// reattach left and right
				pii cur_neighbor;
				if(cur.second == 0) cur_neighbor = get_pii(l[cur.first]);
				else cur_neighbor = get_pii(r[cur.first]);

				pii nxt_neighbor;
				if(nxt.second == 0) nxt_neighbor = get_pii(l[nxt.first]);
				else nxt_neighbor = get_pii(r[nxt.first]);

				if(cur_neighbor.second == 0 && nxt.second == 0) l[cur_neighbor.first] = l[nxt.first];
				if(cur_neighbor.second == 0 && nxt.second == 1) l[cur_neighbor.first] = r[nxt.first];
				if(cur_neighbor.second == 1 && nxt.second == 0) r[cur_neighbor.first] = l[nxt.first];
				if(cur_neighbor.second == 1 && nxt.second == 1) r[cur_neighbor.first] = r[nxt.first];

				if(nxt_neighbor.second == 0 && cur.second == 0) l[nxt_neighbor.first] = l[cur.first];
				if(nxt_neighbor.second == 0 && cur.second == 1) l[nxt_neighbor.first] = r[cur.first];
				if(nxt_neighbor.second == 1 && cur.second == 0) r[nxt_neighbor.first] = l[cur.first];
				if(nxt_neighbor.second == 1 && cur.second == 1) r[nxt_neighbor.first] = r[cur.first];

				if(cur.second == 0) l[cur.first] = get_id(nxt);
				else r[cur.first] = get_id(nxt);

				if(nxt.second == 0) l[nxt.first] = get_id(cur);
				else r[nxt.first] = get_id(cur);
			}
		}
	}

	if(answer) {
		cout << beauty << endl;
		auto v = move(get_cycle(1, l, r));
		for(int x : v) cout << x << ' ';
		cout << endl;
		exit(0);
	} else {
		return dsuSize(0) == cycles;
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    FOR(i, 1, n) cin >> v[i].first >> v[i].second;
    int l = 0, r = 20;
    while(l < r) {
    	int mid = (l+r+1)/2;
    	if(check(mid, false)) l = mid;
    	else r = mid-1;
    }
    if(l == 0) {
	    cout << 0 << endl;
	    FOR(i, 1, 2*n) cout << i << ' ';
	    cout << endl;
    } else {
    	check(l, true);
    }

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