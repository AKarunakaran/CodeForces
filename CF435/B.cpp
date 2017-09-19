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

set<int> first;
set<int> second;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    if(n == 1) {
    	cout << 0 << endl;
    	exit(0);
    }
    vector<vector<int>> g(n+1);
    REP(i, n-1) {
    	int s, e;
    	cin >> s >> e;
    	g[s].push_back(e);
    	g[e].push_back(s);
    }
    first.insert(1);
    queue<int> next, f;
    vector<bool> checked(n+1, 0);
    next.push(1);
    f.push(1);
    checked[1] = 1;
    while(!next.empty()) {
    	int cur = next.front();
    	int frst = f.front();
    	next.pop();
    	f.pop();
    	for(int v : g[cur]) {
    		if(!checked[v]) {
    			next.push(v);
    			f.push(1-frst);
    			checked[v] = 1;
    		}
    		if(frst) second.insert(v);
    		else first.insert(v);
    	}
    }
    cout << first.size()*second.size() - (n-1) << endl;

    return 0;
}