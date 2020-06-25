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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    vector<vector<int>> g(n+1);
    FOR(i, 2, n) {
    	int e;
    	cin >> e;
    	g[i].push_back(e);
    	g[e].push_back(i);
    }
    vector<int> dist(n+1, INF);
    queue<int> next;
    next.push(1);
    dist[1] = 1;
    map<int, int> ds;
    while(!next.empty()) {
    	int cur = next.front();
    	next.pop();
    	ds[dist[cur]]++;
    	for(int v : g[cur]) {
    		if(dist[cur] + 1 < dist[v]) {
    			next.push(v);
    			dist[v] = dist[cur]+1;
    		}
    	}
    }
    int ans = 0;
    for(pii p : ds) {
    	ans += p.second & 1;
    }
    cout << ans << endl;


    return 0;
}