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

// Initialize with std::iota(parent, parent+n+1, 0), std::fill(sz, sz+n+1, 1), std::fill(rnk, rnk+n+1, 0);

const int N = 1e5+5; // Upper bound for n

vector<bool> open;
vector<vector<int>> sw;
vector<int> parent, color;

// Uses path compression
int find(int x) {return parent[x] = (x == parent[x] ? x : find(parent[x]));}

bool disjoint(int x, int y) {return find(x) != find(y);}

void join(int x, int y) {if(disjoint(x, y)) parent[find(y)] = find(x);}


int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m;
    cin >> n >> m;
    open.resize(n+1);
    parent.resize(m+1);
    color.resize(m+1, 0);
    iota(parent.begin(), parent.end(), 0);
    sw.resize(n+1);
    FOR(i, 1, n) {
    	int x;
    	cin >> x;
    	open[i] = x;
    }
    FOR(i, 1, m) {
    	int x;
    	cin >> x;
    	REP(j, x) {
    		int door;
    		cin >> door;
    		sw[door].push_back(i);
    	}
    }
    vector<pii> cant;
    FOR(i, 1, n) {
    	int d1 = sw[i][0], d2 = sw[i][1];
    	// DEBUG(i);
    	// DEBUG(d1);
    	// DEBUG(d2);
    	if(open[i]) join(d1, d2);
    	else cant.push_back({d1, d2});
    }
    // FOR(i, 1, m) cout << parent[i] << ' ';
    // cout << endl;
    map<int, vector<int>> g;
    for(auto p : cant) {
    	if(!disjoint(p.first, p.second)) {
    		// DEBUG(p.first);
    		// DEBUG(p.second);
    		cout << "NO" << endl;
    		exit(0);
    	}
    	g[find(p.first)].push_back(find(p.second));
    	g[find(p.second)].push_back(find(p.first));
    }
    queue<pii> next;
    vector<bool> vis(m+1, 0);
    for(auto thing : g) {
    	if(!vis[thing.first]) {
		    next.push({thing.first, 1});
		    vis[thing.first] = 1;
		    while(!next.empty()) {
		    	pii cur = next.front();
		    	next.pop();
		    	int curV = cur.first;
		    	color[curV] = cur.second;
		    	for(auto v : g[curV]) {
		    		if(color[v] == color[curV]) {
		    			cout << "NO" << endl;
		    			exit(0);
		    		}
		    		if(!vis[v]) {
		    			vis[v] = 1;
		    			next.push({v, 3-color[curV]});
		    		}
		    	}
		    }
    	}
    }
    cout << "YES" << endl;

    return 0;
}