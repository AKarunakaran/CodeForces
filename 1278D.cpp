#include <bits/stdc++.h>
using namespace std;
// #define int long long
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

// Initialize with std::iota(parent, parent+N, 0), std::fill(sz, sz+N, 1);

const int N = 5e5+10; // Upper bound for n

int parent[N];

// Uses path compression
int find(int x) {return parent[x] = (x == parent[x] ? x : find(parent[x]));}

bool disjoint(int x, int y) {return find(x) != find(y);}

void join(int x, int y) {
	if (!disjoint(x, y)) return;
	int newPar = find(x), newChild = find(y);
	parent[newChild] = newPar;
}

void bad() {
	cout << "NO" << endl;
	exit(0);
}

int n, edges;
pii ev[2*N], s[N]; // first is id, second is 1 for start, 2 for end
map<int, int> m;

void print(vector<int>& s) {
	for(int x : s) cout << x << ' ';
	cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    std::iota(parent, parent+N, 0);
    cin >> n;
    REP(i, n) {
        cin >> s[i].first >> s[i].second;
    }
    sort(s, s+n);
    REP(i, n) {
    	int st, ed;
    	tie(st, ed) = s[i];
    	ev[st] = {i, 1};
    	ev[ed] = {i, 2};
    }
    vector<int> open;
    FOR(i, 1, 2*n) {
    	pii cur = ev[i];
    	if(ev[i].second == 1) { // open interval at i
    		open.push_back(ev[i].first);
            m[ev[i].first] = ev[i].second;
    	} else { // close interval at i
    		int curseg = ev[i].first;
            int id = lower_bound(open.begin(), open.end(), curseg)-open.begin();
            int num_add = open.size()-1-id;
            if(edges + num_add > n-1) bad();
            edges += num_add;
    		FOR(j, id+1, open.size()-1) {
                int x = open[j];
    			if(!disjoint(x, curseg)) bad();
    			join(x, curseg);
    		}
            open.erase(open.begin()+id);
    		if(i != 2*n && open.empty()) bad();
    	}
    	// print(open);
    }
    set<int> total;
    REP(i, n) total.insert(find(i));
    if(total.size() > 1) bad();
    cout << "YES" << endl;

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
