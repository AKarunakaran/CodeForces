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
const int INF = 0x3f3f3f3f;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

int dijkstra(vector<vector<int>>& g, vector<int>& dist, int src, int tgt) {
    dist[src] = 0;
    set<pair<int,int>> next;
    next.insert({0, src});
        
    while(!next.empty()) {
        int cur = next.begin()->second;
        if(cur == tgt) return dist[cur];
        next.erase(next.begin());
        REP(i, g[cur].size()) {
            if (dist[cur] + 1 < dist[g[cur][i]]) {
                next.erase({dist[g[cur][i]], g[cur][i]});
                dist[g[cur][i]] = dist[cur] + 1;
                next.insert({dist[g[cur][i]], g[cur][i]});
            }
        }
    }
    return INF;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s, --t;
    vector<vector<int>> g(n), mat(n, vector<int>(n, 0));
    REP(i, m) {
    	int a, b;
    	cin >> a >> b;
    	--a, --b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    	mat[a][b] = mat[b][a] = 1;
    }
    vector<int> sd(n, INF), td(n, INF);
    int dist = dijkstra(g, sd, s, t);
    dijkstra(g, td, t, s);
    // DEBUG(dist);
    // REP(i, n) cout << sd[i] << ' ';
    // cout << endl;
    // REP(i, n) cout << td[i] << ' ';
    // cout << endl;
    
    ll ans = 0;
    REP(i, n) {
    	FOR(j, i+1, n-1) {
    		if(!mat[i][j]) {
    			if(sd[i]+td[j]+1 >= dist && sd[j]+td[i]+1 >= dist) {
    				++ans;
    			}
    		}
    	}
    }
    cout << ans << endl;

    return 0;
}