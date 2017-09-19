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
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> bd(n);
    set<pair<int, int>> pq;
    REP(i, m) {
    	int s, e;
    	cin >> s >> e;
    	--s;
    	--e;
    	g[s].push_back(e);
    	++bd[e];
    }
    REP(i, n) pq.insert({bd[i], i});
    vector<int> ans(n, INF);
    REP(i, n) {

    	/*for(auto itr = pq.begin(); itr != pq.end(); ++itr) {
	    	cout << itr->first << ',' << itr->second << " ";
	    }
	    cout << endl;*/

    	int v = pq.begin()->second;
    	pq.erase(pq.begin());
    	ans[v] = i+1;
    	REP(j, g[v].size()) {
    		//DEBUG(v);
    		//DEBUG(g[v][j]);
    		int v2 = g[v][j];
    		pq.erase({bd[v2], v2});
    		--bd[v2];
    		pq.insert({bd[v2], v2});
    	}
    }
    REP(i, n) cout << ans[i] << " ";
    cout << endl;

    return 0;
}