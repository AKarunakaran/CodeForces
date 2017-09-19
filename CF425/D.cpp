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
#include <unordered_set>
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

int dijkstra(const vector< vector<int> >& g, int src, int tgt, vector<int>& prev, vector<int>& dist) {
    dist[src] = 0;
    set<pair<int,int>> next;
    next.insert({0, src});
    int cur;
    while(!next.empty()) {
        cur = next.begin()->second;
        if(cur == tgt) return dist[cur];
        next.erase(next.begin());
        REP(i, g[cur].size()) {
        	int v = g[cur][i];
            if(dist[cur] + 1 < dist[v]) {
                next.erase({dist[v], v});
                dist[v] = dist[cur] + 1;
                next.insert({dist[v], v});
                prev[v] = cur;
            }
        }
    }
    return INF;
}

int modDijk(const vector< vector<int> >& g, int src, vector<int>& dist, vector<int>& rdist, unordered_set<int>& s) {
    vector<int> curD(g.size(), INF);
    curD[src] = 0;
    set<pair<int,int>> next;
    next.insert({0, src});
    int cur;
    while(!next.empty()) {
        cur = next.begin()->second;
        if(s.find(cur) != s.end()) return curD[cur]+min(rdist[cur], dist[cur]);
        next.erase(next.begin());
        REP(i, g[cur].size()) {
        	int v = g[cur][i];
            if(curD[cur] + 1 < curD[v]) {
                next.erase({curD[v], v});
                curD[v] = curD[cur] + 1;
                next.insert({curD[v], v});
            }
        }
    }
    return INF;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n+1);
    FOR(i, 2, n) {
    	int in;
    	cin >> in;
    	g[i].push_back(in);
    	g[in].push_back(i);
    }
    vector<int> prev(n, 0), dist(n), rdist(n);
    REP(test, q) {
    	int a, b, c, ans = INF, d, cur, rd;
    	cin >> a >> b >> c;
    	fill(prev.begin(), prev.end(), 0);
    	fill(dist.begin(), dist.end(), INF);
    	fill(rdist.begin(), rdist.end(), INF);
    	d = dijkstra(g, a, b, prev, dist);
    	unordered_set<int> s1;
    	cur = b;
    	rd = 0;
    	while(cur != a) {
    		s1.insert(cur);
    		rdist[cur] = rd++;
    		cur = prev[cur];
    	}
    	s1.insert(a);
    	rdist[a] = d;
    	ans = min(ans, modDijk(g, c, dist, rdist, s1));

    	fill(prev.begin(), prev.end(), 0);
    	fill(dist.begin(), dist.end(), INF);
    	fill(rdist.begin(), rdist.end(), INF);
    	d = dijkstra(g, a, c, prev, dist);
    	unordered_set<int> s2;
    	cur = c;
    	rd = 0;
    	while(cur != a) {
    		s2.insert(cur);
    		rdist[cur] = rd++;
    		cur = prev[cur];
    	}
    	s2.insert(a);
    	rdist[a] = d;
    	ans = min(ans, modDijk(g, b, dist, rdist, s1));

    	fill(prev.begin(), prev.end(), 0);
    	fill(dist.begin(), dist.end(), INF);
    	fill(rdist.begin(), rdist.end(), INF);
    	d = dijkstra(g, b, c, prev, dist);
    	unordered_set<int> s3;
    	cur = b;
    	rd = 0;
    	while(cur != b) {
    		s3.insert(cur);
    		rdist[cur] = rd++;
    		cur = prev[cur];
    	}
    	s3.insert(b);
    	rdist[b] = d;
    	ans = min(ans, modDijk(g, a, dist, rdist, s1));
    	cout << ans << endl;
    }


    return 0;
}