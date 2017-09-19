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
    int n, x;
    cin >> n >> x;
    int a, b;
    vector<vector<int>> g(n);
    REP(i, n-1) {
    	cin >> a >> b;
    	g[a-1].push_back(b-1);
    	g[b-1].push_back(a-1);
    }
    vector<bool> checkedA(n, 0);
    vector<int> distA(n, -1);
    queue<int> next;
    int cur;
    distA[0] = 0;
    checkedA[0] = 1;
    next.push(0);
    while(!next.empty()) {
    	cur = next.front();
    	next.pop();
    	//cout << cur << endl;
    	REP(i, g[cur].size()) {
    		if(!checkedA[g[cur][i]]) {
    			checkedA[g[cur][i]] = 1;
    			distA[g[cur][i]] = distA[cur]+1;
    			next.push(g[cur][i]);
    		}
    	}
    }

	vector<bool> checkedB(n, 0);
    vector<int> distB(n, -1);
    distB[x-1] = 0;
    checkedB[x-1] = 1;
    next.push(x-1);
    while(!next.empty()) {
    	cur = next.front();
    	next.pop();
    	REP(i, g[cur].size()) {
    		if(!checkedB[g[cur][i]]) {
    			checkedB[g[cur][i]] = 1;
    			if(distA[g[cur][i]] > distB[cur]+1) {
    				distB[g[cur][i]] = distB[cur]+1;
    				next.push(g[cur][i]);
    			}
    		}
    	}
    }
    int fV = x-1;
    REP(i, n) if(distB[i] != -1 && distA[i] > distA[fV]) fV = i;

    cout << distA[fV]*2 << endl;

    return 0;
}