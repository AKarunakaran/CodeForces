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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 200001;

int n, start, finish, prevV[N], dist[N], dist2[N], marked[N];
bool vis[N], rem[N];
vector<int> g[N];

int bfs(int s) {
	fill(dist, dist+1+n, INF);
	fill(vis, vis+1+n, 0);
	fill(prevV, prevV+1+n, 0);
	queue<int> next;
	vis[s] = 1;
	dist[s] = 0;
	prevV[s] = -1;
	int farthest = s;
	next.push(s);
	// DEBUG(s);
	while(!next.empty()) {
		int cur = next.front();
		// DEBUG(cur);
		next.pop();
		for(int v : g[cur]) {
			if(!vis[v]) {
				vis[v] = 1;
				prevV[v] = cur;
				dist[v] = dist[cur]+1;
				farthest = v;
				next.push(v);
			}
		}
	}
	return farthest;
}

void bfs2(int s) {
	fill(dist2, dist2+1+n, INF);
	fill(vis, vis+1+n, 0);
	queue<int> next;
	vis[s] = 1;
	dist2[s] = 0;
	next.push(s);
	while(!next.empty()) {
		int cur = next.front();
		next.pop();
		for(int v : g[cur]) {
			if(!vis[v]) {
				vis[v] = 1;
				dist2[v] = dist2[cur]+1;
				next.push(v);
			}
		}
	}
}

void findDiameter() {
	start = bfs(1);
	finish = bfs(start);
	bfs2(finish);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    fill(marked, marked+n+1, 0);
    REP(i, n-1) {
    	int a, b;
    	cin >> a >> b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    	++marked[a];
    	++marked[b];
    }
    fill(rem, rem+n+1, 0);
    findDiameter();
    // DEBUG(start);
    // DEBUG(finish);
    queue<int> r;
    FOR(i, 1, n) if(i != start && i != finish && marked[i] == 1) r.push(i);
    vector<vector<int>> ans;
    ll score = 0;
    while(!r.empty()) {
    	int cur = r.front();
    	r.pop();
    	score += max(dist[cur], dist2[cur]);
    	if(dist[cur] > dist2[cur]) ans.push_back({cur, start, cur});
    	else ans.push_back({cur, finish, cur});
    	for(int v : g[cur]) {
    		if(!rem[v]) {
    			--marked[v];
    			if(marked[v] == 1) r.push(v);
    			break;
    		}
    	}
    	rem[cur] = 1;
    }
    r.push(start);
    while(r.front() != finish) {
    	int cur = r.front();
    	r.pop();
    	score += dist2[cur];
    	ans.push_back({cur, finish, cur});
    	for(int v : g[cur]) {
    		if(!rem[v]) {
    			r.push(v);
    			break;
    		}
    	}
    	rem[cur] = 1;
    }
    cout << score << endl;
    REP(i, ans.size()) cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl;

    return 0;
}