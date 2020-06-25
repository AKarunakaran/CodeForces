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
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// #define int long long
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
struct node {
	int val;
	node *nxt, *prev;
};

const int N = 2e5+10;
int n;
map<int, pair<node*, node*>> m;


// Initialize with std::iota(parent, parent+n+1, 0), std::fill(sz, sz+n+1, 1);

int parent[N];

// Uses path compression
int find(int x) {return parent[x] = (x == parent[x] ? x : find(parent[x]));}

bool disjoint(int x, int y) {return find(x) != find(y);}

void join(int x, int y) {
	if (!disjoint(x, y)) return;
	int newPar = find(x), newChild = find(y);
	parent[newChild] = newPar;
	
	auto& ls = m[newPar];
	auto& rs = m[newChild];
	// cout << ls.first->val << ' ' << ls.second->val << "  " << rs.first->val << ' ' << rs.second->val << endl;
	ls.second->nxt = rs.first;
	rs.first->prev = ls.second;
	m[newPar] = {ls.first, rs.second};
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    std::iota(parent, parent+n+1, 0);
    FOR(i, 1, n) {
    	node *cur = new node{i, 0, 0};
    	m[i] = {cur, cur};
    }
    REP(_, n-1) {
    	int a, b;
    	cin >> a >> b;
    	join(a, b);
    }
    auto& l = m[find(1)];
    for(auto itr = l.first; itr; itr = itr->nxt) {
    	cout << itr->val << ' ';
    }
    cout << endl;

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

