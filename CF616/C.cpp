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

const int N = 3e5+10;

int parent[2*N], sz[2*N], numo[2*N];

// Uses path compression
int find(int x) {return parent[x] = (x == parent[x] ? x : find(parent[x]));}

bool disjoint(int x, int y) {return find(x) != find(y);}

void join(int x, int y) {
	if (!disjoint(x, y)) return;
	int newPar = find(x), newChild = find(y);
	sz[newPar] += sz[newChild];
	numo[newPar] += numo[newChild];
	parent[newChild] = newPar;
}

int dsuSize(int x) {return sz[find(x)];}
int numOnes(int x) {return numo[find(x)];}

// 2*i = i, 2*i+1 = i', 1 <= i <= n
int n, k, t[2*N];
string s;
vector<int> g[N], l[N], def;



signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(t, -1, sizeof(t));
    std::iota(parent, parent+2*N, 0), std::fill(sz, sz+2*N, 1);
    cin >> n >> k >> s;
    FOR(i, 1, n) numo[2*i] = 1;
    FOR(i, 1, k) {
    	int num;
    	cin >> num;
    	REP(_, num) {
    		int x;
    		cin >> x;
    		g[i].push_back(x);
    		l[x].push_back(i);
    	}
    }
    set<int> heads;
    int ans = 0;
    FOR(i, 1, n) {
    	//
    	if(l[i].size() == 1) {
    		int curs = l[i][0];
    		if(s[i] == '0') {
    			def.push_back(2*curs);
    		} else {
    			def.push_back(2*curs+1);
    		}
    	} else if(l[i].size() == 2) {
    		// if s[i] == 1, link true true and false false, else link true false and false true
    		int s1 = l[i][0], s2 = l[i][1];
    		if(s[i] == '0') {
    			join(2*s1, 2*s2+1);
    			join(2*s1+1, 2*s2);
    		} else {
    			join(2*s1, 2*s2);
    			join(2*s1+1, 2*s2+1);
    		}
    		heads.insert(find(2*s1)/2);
    	}
    	ans = 0;
    	for(int x : heads) {
    		ans += min(numOnes(2*x), numOnes(2*x+1));
    	}
    	cout << ans << endl;
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
